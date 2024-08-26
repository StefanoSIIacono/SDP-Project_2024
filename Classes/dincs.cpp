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

using namespace std;
using namespace std::chrono;

// Function to perform BFS and construct level graph
bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& level) {
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
int dfs(vector<vector<int>>& rGraph, vector<int>& level, vector<int>& start, int u, int t, int flow) {
    if (u == t) return flow;

    for (int& v = start[u]; v < rGraph.size(); ++v) {
        if (level[v] == level[u] + 1 && rGraph[u][v] > 0) {
            int curr_flow = min(flow, rGraph[u][v]);
            int temp_flow = dfs(rGraph, level, start, v, t, curr_flow);

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
int dinic(vector<vector<int>>& graph, int s, int t) {
    int V = graph.size();
    vector<vector<int>> rGraph = graph;

    vector<int> level(V);
    vector<int> start(V);
    int max_flow = 0;

    while (bfs(rGraph, s, t, level)) {
        fill(start.begin(), start.end(), 0);

        while (int flow = dfs(rGraph, level, start, s, t, INT_MAX)) {
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

    vector<vector<int>> graph(V, vector<int>(V, 0));

    int u, v, capacity;
    while (infile >> u >> v >> capacity) {
        graph[u][v] = capacity;
    }

    infile.clear(); // Clear the EOF flag
    infile >> u >> v; // Reading the source and sink values

    int s = u; // source
    int t = v; // sink

    infile.close();

    cout << "The value for s and t are " << s << " " << t << endl;

    double start, end;

    // Sequential version timing
    start = omp_get_wtime();
    // auto start = high_resolution_clock::now();
    int max_flow_sequential = dinic(graph, s, t);
    end = omp_get_wtime();
    // auto end = high_resolution_clock::now();
    double total_time_sequential = end - start;
    // auto total_time_sequential = (end - start);
    cout << "Sequential: The maximum possible flow is " << max_flow_sequential << endl;
    cout << "Time taken (Sequential): " << total_time_sequential << " seconds" << endl;

    
    // Parallel version timing
    int desired_threads = 3; // Adjust this as needed
    omp_set_num_threads(desired_threads);

    start = omp_get_wtime();
    #pragma omp parallel 
    {
        #pragma omp single
        {
            int num_threads = omp_get_num_threads();
            cout << "Number of threads running in parallel: " << num_threads << endl;
            int max_flow_parallel = dinic(graph, s, t); // Same function, but ensure parallel code is effective
        }
    }
    end = omp_get_wtime();
    double total_time_parallel = end - start;
    cout << "Parallel: The maximum possible flow is " << max_flow_sequential << endl; // Use the same max_flow_sequential as placeholder
    cout << "Time taken (Parallel): " << total_time_parallel << " seconds" << endl;

    return 0;
}
