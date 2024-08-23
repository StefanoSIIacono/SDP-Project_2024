#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <chrono>
#include <omp.h>

using namespace std;
using namespace std::chrono;

// Function to perform BFS in the level graph (Sequential)
bool bfsLevelGraph(const vector<vector<int>>& rGraph, int s, int t, vector<int>& level) {
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

// Function to perform DFS in the residual graph (Sequential)
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

// Function to perform DFS in the residual graph (Parallel)
int dfsBlockingFlowParallel(vector<vector<int>>& rGraph, vector<int>& level, vector<int>& start, int u, int t, int flow) {
    if (u == t) return flow;

    int V = rGraph.size();
    int result_flow = 0;

    #pragma omp parallel for shared(result_flow)
    for (int v = start[u]; v < V; ++v) {
        if (level[v] == level[u] + 1 && rGraph[u][v] > 0) {
            int curr_flow = min(flow, rGraph[u][v]);
            int temp_flow = dfsBlockingFlowParallel(rGraph, level, start, v, t, curr_flow);

            if (temp_flow > 0) {
                #pragma omp critical
                {
                    rGraph[u][v] -= temp_flow;
                    rGraph[v][u] += temp_flow;
                    result_flow = temp_flow;
                }
            }
        }
    }

    return result_flow;
}

// Dinic's algorithm for computing maximum flow (Sequential)
int dinicMaxFlowSequential(vector<vector<int>>& graph, int s, int t) {
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

// Dinic's algorithm for computing maximum flow (Parallel)
int dinicMaxFlowParallel(vector<vector<int>>& graph, int s, int t) {
    int V = graph.size();
    vector<vector<int>> rGraph = graph; // Residual graph
    vector<int> level(V);
    int max_flow = 0;

    while (bfsLevelGraph(rGraph, s, t, level)) {
        vector<int> start(V, 0);

        while (int flow = dfsBlockingFlowParallel(rGraph, level, start, s, t, INT_MAX)) {
            #pragma omp atomic
            max_flow += flow;
        }
    }

    return max_flow;
}

int main() {
    string filename = "G:/graph.txt";

    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }

    int V;
    infile >> V;

    cout << "Number of vertices read: " << V << endl;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    int u, v, capacity;
    while (infile >> u >> v >> capacity) {
        graph[u][v] = capacity;
    }

    // Extract source and sink from the last line of the file
    int s, t;
    infile.clear(); // Clear EOF flag
    infile.seekg(-1, ios_base::end); // Move to the last character

    // Move backward until we find the start of the last line
    bool keepLooping = true;
    while (keepLooping) {
        char ch;
        infile.get(ch);

        if ((int)infile.tellg() <= 1) { // Start of the file reached
            infile.seekg(0);
            keepLooping = false;
        } else if (ch == '\n') {
            keepLooping = false;
        } else {
            infile.seekg(-2, ios_base::cur);
        }
    }

    infile >> s >> t;

    infile.close();

    cout << "Source: " << s << " Sink: " << t << endl;

    // Sequential Execution
    auto start = high_resolution_clock::now();
    int max_flow_sequential = dinicMaxFlowSequential(graph, s, t);
    auto stop = high_resolution_clock::now();
    auto duration_sequential = duration_cast<milliseconds>(stop - start);

    cout << "Sequential: The maximum possible flow is " << max_flow_sequential << endl;
    cout << "Time taken (Sequential): " << duration_sequential.count() << " milliseconds" << endl;

    // Parallel Execution
    start = high_resolution_clock::now();
    int max_flow_parallel = dinicMaxFlowParallel(graph, s, t);
    stop = high_resolution_clock::now();
    auto duration_parallel = duration_cast<milliseconds>(stop - start);

    cout << "Parallel: The maximum possible flow is " << max_flow_parallel << endl;
    cout << "Time taken (Parallel): " << duration_parallel.count() << " milliseconds" << endl;

    return 0;
}
