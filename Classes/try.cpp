#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <omp.h>
#include <fstream>
#include <sstream>

using namespace std;

struct Edge {
    int to;
    int capacity;
    int flow;
    int reverse_index; // Index of the reverse edge in the adjacency list
};

using Graph = vector<vector<Edge>>;

bool bfs(Graph &rGraph, int s, int t, vector<int>& level) {
    int V = rGraph.size();
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    q.push(s);
    level[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const auto& edge : rGraph[u]) {
            if (level[edge.to] < 0 && edge.capacity > edge.flow) {
                level[edge.to] = level[u] + 1;
                q.push(edge.to);
            }
        }
    }
    return level[t] >= 0;
}

int dfs(Graph &rGraph, int u, int t, int flow, vector<int>& level, vector<int>& start) {
    if (u == t) return flow;

    for (int &i = start[u]; i < rGraph[u].size(); ++i) {
        Edge &e = rGraph[u][i];

        if (level[e.to] == level[u] + 1 && e.capacity > e.flow) {
            int curr_flow = min(flow, e.capacity - e.flow);
            int temp_flow = dfs(rGraph, e.to, t, curr_flow, level, start);

            if (temp_flow > 0) {
                e.flow += temp_flow;
                rGraph[e.to][e.reverse_index].flow -= temp_flow;
                return temp_flow;
            }
        }
    }
    return 0;
}

int dfsParallel(Graph &rGraph, int u, int t, int flow, vector<int>& level, vector<int>& start) {
    if (u == t) return flow;

    int result_flow = 0;

    #pragma omp parallel for shared(result_flow)
    for (int i = start[u]; i < rGraph[u].size(); ++i) {
        Edge &e = rGraph[u][i];

        if (level[e.to] == level[u] + 1 && e.capacity > e.flow) {
            int curr_flow = min(flow, e.capacity - e.flow);
            int temp_flow = dfs(rGraph, e.to, t, curr_flow, level, start);

            if (temp_flow > 0) {
                #pragma omp critical
                {
                    e.flow += temp_flow;
                    rGraph[e.to][e.reverse_index].flow -= temp_flow;
                    result_flow += temp_flow;
                }
            }
        }
    }

    return result_flow;
}

int dinic(Graph &graph, int s, int t, bool parallel = false) {
    int V = graph.size();
    if (s == t) return -1;

    vector<int> level(V);
    int max_flow = 0;

    while (bfs(graph, s, t, level)) {
        vector<int> start(V, 0);

        while (int flow = parallel ? dfsParallel(graph, s, t, INT_MAX, level, start)
                                   : dfs(graph, s, t, INT_MAX, level, start)) {
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
    infile.ignore();  // Ignore the newline after the number of vertices

    Graph graph(V);

    int u, v, capacity;

    // Reading edges from the file
    while (infile >> u >> v >> capacity) {
        if (infile.peek() == '\n' || infile.peek() == EOF) {
            graph[u].push_back({v, capacity, 0, static_cast<int>(graph[v].size())});
            graph[v].push_back({u, 0, 0, static_cast<int>(graph[u].size()) - 1});
        }
    }

    // Read the source and sink values correctly from the last line
    infile.clear();  // Clear any error flags
    infile.seekg(0, ios::beg);  // Go back to the beginning of the file

    string lastLine;
    while (getline(infile, lastLine)) {
        // Keep reading until the last line
    }

    stringstream ss(lastLine);
    ss >> u >> v;
    int s = u;
    int t = v;

    infile.close();

    cout << "The value for s and t are " << s << " " << t << endl;
    // cout << "Graph edges:" << endl;
    // for (int i = 0; i < V; ++i) {
    //     for (auto &edge : graph[i]) {
    //         cout << i << " -> " << edge.to << " (capacity: " << edge.capacity << ")" << endl;
    //     }
    // }

    double start, end;

    // Sequential Execution
    start = omp_get_wtime();
    int max_flow_sequential = dinic(graph, s, t);
    end = omp_get_wtime();
    double total_time_sequential = end - start;
    cout << "Sequential: The maximum possible flow is " << max_flow_sequential << endl;
    cout << "Time taken (Sequential): " << total_time_sequential << " seconds" << endl;

    // Parallel Execution
    // Resetting flow values for parallel execution
    for (int i = 0; i < V; ++i) {
        for (auto &edge : graph[i]) {
            edge.flow = 0;
        }
    }

    start = omp_get_wtime();
    int max_flow_parallel = dinic(graph, s, t, true);
    end = omp_get_wtime();
    double total_time_parallel = end - start;
    cout << "Parallel: The maximum possible flow is " << max_flow_parallel << endl;
    cout << "Time taken (Parallel): " << total_time_parallel << " seconds" << endl;

    return 0;
}
