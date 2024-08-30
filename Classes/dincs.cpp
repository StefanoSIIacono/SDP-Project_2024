#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <omp.h>
#include <fstream>
#include <ctime>   // For time()
#include <chrono>  // For timing
#include <cfloat>  // For DBL_MAX

using namespace std;
using namespace std::chrono;

size_t estimateMemoryUsage(const vector<vector<double>>& graph) {
    size_t totalMemory = 0;

    // Memory for the outer vector structure
    totalMemory += sizeof(graph);

    for (const auto& row : graph) {
        // Memory for each inner vector structure
        totalMemory += sizeof(row);

        // Memory for the elements in each inner vector
        totalMemory += row.size() * sizeof(double);
    }

    return totalMemory;
}

// Function to perform BFS and construct level graph
bool bfs(vector<vector<double>>& rGraph, int s, int t, vector<int>& level) {
    int V = rGraph.size();
    fill(level.begin(), level.end(), -1);
    level[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; ++v) {
            if (level[v] < 0 && rGraph[u][v] > 0) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }

    return level[t] >= 0;
}

// Function to perform DFS and find the blocking flow
double dfs(vector<vector<double>>& rGraph, vector<int>& level, vector<int>& start, int u, int t, double flow) {
    if (u == t) return flow;

    for (int& v = start[u]; v < rGraph.size(); ++v) {
        if (level[v] == level[u] + 1 && rGraph[u][v] > 0) {
            double curr_flow = min(flow, rGraph[u][v]);
            double temp_flow = dfs(rGraph, level, start, v, t, curr_flow);

            if (temp_flow > 0) {
                rGraph[u][v] -= temp_flow;
                rGraph[v][u] += temp_flow;
                return temp_flow;
            }
        }
    }

    return 0;
}

// Dinic's algorithm for computing maximum flow
double dinic(vector<vector<double>>& graph, int s, int t) {
    int V = graph.size();
    vector<vector<double>> rGraph = graph;

    vector<int> level(V);
    vector<int> start(V);
    double max_flow = 0;

    while (bfs(rGraph, s, t, level)) {
        fill(start.begin(), start.end(), 0);

        while (double flow = dfs(rGraph, level, start, s, t, DBL_MAX)) {
            max_flow += flow;
        }
    }

    return max_flow;
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int V;
    infile >> V;
    // cout << "debus the value of V is " << V << endl;
    vector<vector<double>> graph(V, vector<double>(V, 0));

    int u, v;
    double capacity;
    while (infile >> u >> v >> capacity) {
        // cout << "u is "<< u << "and v is "<< v << endl;
        graph[u][v] = capacity;
    }

    infile.clear(); // Clear the EOF flag
    infile >> u >> v; // Reading the source and sink values

    int s = u; // source
    int t = v; // sink

    infile.close();
     size_t memoryUsage = estimateMemoryUsage(graph);
    cout << "Estimated memory usage of the graph: " << memoryUsage << " bytes" << endl;

    cout << "The value for s and t are " << s << " " << t << endl;

    double start, end;

    // Sequential version timing
    start = omp_get_wtime();
    double max_flow_sequential = dinic(graph, s, t);
    end = omp_get_wtime();
    double total_time_sequential = end - start;
    cout << "Sequential: The maximum possible flow is " << max_flow_sequential << endl;
    cout << "Time taken (Sequential): " << total_time_sequential << " seconds" << endl;

    
    // Parallel version timing
    int desired_threads = 8; // Adjust this as needed
    omp_set_num_threads(desired_threads);

    start = omp_get_wtime();
    #pragma omp parallel 
    {
        #pragma omp single
        {
            int num_threads = omp_get_num_threads();
            cout << "Number of threads running in parallel: " << num_threads << endl;
            double max_flow_parallel = dinic(graph, s, t); // Same function, but ensure parallel code is effective
            cout << "Parallel: The maximum possible flow is " << max_flow_parallel << endl;
        }
    }
    end = omp_get_wtime();
    double total_time_parallel = end - start;
    cout << "Time taken (Parallel): " << total_time_parallel << " seconds" << endl;

    return 0;
}
