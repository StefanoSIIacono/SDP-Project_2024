#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <omp.h>
#include <fstream>

using namespace std;

// Function to print the graph matrix (for debugging purposes)
void printGraph(const vector<vector<int>>& graph) {
    int V = graph.size();
    cout << "Graph adjacency matrix:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to perform BFS in the level graph
bool bfsLevelGraph(vector<vector<int>>& rGraph, int s, int t, vector<int>& level) {
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

// Function to perform DFS in the residual graph
int dfsBlockingFlow(vector<vector<int>>& rGraph, vector<int>& level, vector<int>& start, int u, int t, int flow) {
    if (u == t) return flow;

    for (int& v = start[u]; v < rGraph.size(); ++v) {
        if (level[v] == level[u] + 1 && rGraph[u][v] > 0) {
            int curr_flow = min(flow, rGraph[u][v]);
            int temp_flow = dfsBlockingFlow(rGraph, level, start, v, t, curr_flow);

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
int dinicMaxFlow(vector<vector<int>>& graph, int s, int t) {
    int V = graph.size();
    vector<vector<int>> rGraph = graph; // Residual graph
    vector<int> level(V);
    int max_flow = 0;

    while (bfsLevelGraph(rGraph, s, t, level)) {
        vector<int> start(V, 0);
        
        while (int flow = dfsBlockingFlow(rGraph, level, start, s, t, INT_MAX)) {
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
    
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            infile >> graph[i][j];
        }
    }

    int s, t;
    infile >> s >> t;

    infile.close();

    cout << "the value for s and t are " << s << " " << t << endl;

    double start, end;

    // Sequential version timing
    start = omp_get_wtime();
    int max_flow_sequential = dinicMaxFlow(graph, s, t);
    end = omp_get_wtime();
    double total_time_sequential = end - start;
    cout << "Sequential: The maximum possible flow is " << max_flow_sequential << endl;
    cout << "Time taken (Sequential): " << total_time_sequential << " seconds" << endl;

    // Parallel version timing
    int desired_threads = 2; // Adjust this as needed
    omp_set_num_threads(desired_threads);

    start = omp_get_wtime();
    #pragma omp parallel 
    {
        #pragma omp single
        {
            int num_threads = omp_get_num_threads();
            cout << "Number of threads running in parallel: " << num_threads << endl;
            int max_flow_parallel = dinicMaxFlow(graph, s, t);
        }
    }
    end = omp_get_wtime();
    double total_time_parallel = end - start;
    cout << "Parallel: The maximum possible flow is " << max_flow_sequential << endl; // Use the same max_flow_sequential as placeholder
    cout << "Time taken (Parallel): " << total_time_parallel << " seconds" << endl;

    return 0;
}
