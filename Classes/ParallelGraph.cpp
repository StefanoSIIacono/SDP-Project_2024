#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <omp.h>
#include <fstream>

using namespace std;

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

// Function to perform BFS in the residual graph
bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    int V = rGraph.size();
    vector<bool> visited(V, false);
    queue<int> q;
    
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

// Function to update the residual graph
void updateResidualGraph(vector<vector<int>>& rGraph, vector<int>& parent, int s, int t, int path_flow) {
    int v = t;
    while (v != s) {
        int u = parent[v];
        #pragma omp critical
        {
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        v = parent[v];
    }
}

// Edmonds-Karp algorithm for computing maximum flow
int edmondsKarp(vector<vector<int>>& graph, int s, int t) {
    int V = graph.size();
    
    vector<vector<int>> rGraph = graph; // Create a copy of the graph
    // printGraph(rGraph);
    vector<int> parent(V);
    int max_flow = 0;
    
    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        
        // Update the residual graph
        updateResidualGraph(rGraph, parent, s, t, path_flow);
        max_flow += path_flow;
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
    
   
    cout << "the value for s and t are "<< s << " " << t << endl;
    // Run multiple iterations to get accurate timing
    
    double total_time_sequential = 0.0;
    double total_time_parallel = 0.0;


        double start, end;

         // Sequential version timing
//    printGraph(graph);
    start = omp_get_wtime();
    int max_flow_sequential = edmondsKarp(graph, s, t);
    end = omp_get_wtime();
    total_time_sequential = end - start;
    cout << "Sequential: The maximum possible flow is " << max_flow_sequential << endl;
    cout << "Time taken (Sequential): " << total_time_sequential << " seconds" << endl;

    // Parallel version timing
    start = omp_get_wtime();
    int max_flow_parallel = edmondsKarp(graph, s, t); // Same function, but ensure parallel code is effective
    end = omp_get_wtime();
    total_time_parallel = end - start;
    cout << "Parallel: The maximum possible flow is " << max_flow_parallel << endl;
    cout << "Time taken (Parallel): " << total_time_parallel << " seconds" << endl;


    return 0;
}
