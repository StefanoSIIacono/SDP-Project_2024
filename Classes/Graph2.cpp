#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

#define INF INT_MAX

using namespace std;

// Number of vertices in the graph
#define V 6

// Function to perform BFS and find if there is a path from source to sink
bool bfs(int rGraph[V][V], int s, int t, int parent[]) {
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
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

// Function to implement the Edmonds-Karp algorithm
int edmondsKarp(int graph[V][V], int s, int t) {
    int u, v;
    
    int rGraph[V][V]; // Residual graph
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
    
    int parent[V];  // Array to store the path
    
    int max_flow = 0;  // Initialize max flow to zero
    
    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INF;
        
        // Find the maximum flow through the path found by BFS
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        
        // Update residual capacities of the edges and reverse edges along the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        
        max_flow += path_flow;
    }
    
    return max_flow;
}

int main() {
    // Example graph represented as an adjacency matrix
    // int graph[V][V] = {
    //     {0, 16, 13, 0, 0, 0},
    //     {0, 0, 10, 12, 0, 0},
    //     {0, 4, 0, 0, 14, 0},
    //     {0, 0, 9, 0, 0, 20},
    //     {0, 0, 0, 7, 0, 4},
    //     {0, 0, 0, 0, 0, 0}
    // };
    int graph[V][V]= {
     {0, 3, 7, 0, 0, 0}, //node s
      {0, 0, 0, 3, 4, 0}, // node A
      {0, 0, 0, 0, 3, 2}, //node B
      {0, 5, 0, 0, 3, 0}, //node C
      {0, 0, 0, 0, 0, 6}, //node D
      {0, 0, 0, 0, 0, 0} //node t
};
    cout << "The maximum possible flow is " << edmondsKarp(graph, 0, 5) << endl;
    
    return 0;
}
