#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <omp.h>

#define INF INT_MAX
#define V 6

using namespace std;

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

void updateResidualGraph(int rGraph[V][V], int parent[], int s, int t, int path_flow) {
    int u, v;
    #pragma omp parallel for private(u, v) shared(rGraph, parent)
    for (int i = 0; i < V; ++i) {
        v = t;
        while (v != s) {
            u = parent[v];
            #pragma omp atomic
            rGraph[u][v] -= path_flow;
            #pragma omp atomic
            rGraph[v][u] += path_flow;
            v = parent[v];
        }
    }
}

int edmondsKarp(int graph[V][V], int s, int t) {
    int u, v;

    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];

    int max_flow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INF;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        updateResidualGraph(rGraph, parent, s, t, path_flow);

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    double start, end;

    // Sequential version timing
    start = omp_get_wtime();
    cout << "Sequential: The maximum possible flow is " << edmondsKarp(graph, 0, 5) << endl;
    end = omp_get_wtime();
    cout << "Time taken (Sequential): " << (end - start) << " seconds" << endl;

    // Resetting the graph for the parallel version
    int graph_parallel[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    // Parallel version timing

    start = omp_get_wtime();
    cout << "Parallel: The maximum possible flow is " << edmondsKarp(graph_parallel, 0, 5) << endl;
    end = omp_get_wtime();
    cout << "Time taken (Parallel): " << (end - start) << " seconds" << endl;

    return 0;
}
