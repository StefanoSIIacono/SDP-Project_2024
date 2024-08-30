#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <climits> // For INT_MAX
#include <omp.h>
#include <atomic>

using namespace std;

class PushRelabel {
public:
    PushRelabel(int n) : n(n), capacity(n, vector<int>(n, 0)), flow(n, vector<int>(n, 0)), height(n, 0), excess(n, 0) {}

    void addEdge(int u, int v, int cap) {
        capacity[u][v] = cap;
    }

    int getMaxFlow(int source, int sink) {
        height[source] = n;
        excess[source] = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (capacity[source][i] > 0) {
                push(source, i);
            }
        }

        while (true) {
            int u = -1;
            for (int i = 0; i < n; i++) {
                if (i != source && i != sink && excess[i] > 0) {
                    u = i;
                    break;
                }
            }

            if (u == -1) break;

            bool pushed = false;
            for (int v = 0; v < n && excess[u] > 0; v++) {
                if (capacity[u][v] - flow[u][v] > 0 && height[u] == height[v] + 1) {
                    push(u, v);
                    pushed = true;
                }
            }

            if (!pushed) {
                relabel(u);
            }
        }

        int maxFlow = 0;
        for (int i = 0; i < n; i++) {
            maxFlow += flow[source][i];
        }

        return maxFlow;
    }

    int getMaxFlowParallel(int source, int sink) {
        height[source] = n;
        excess[source] = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (capacity[source][i] > 0) {
                push(source, i);
            }
        }

        bool active = true;
        while (active) {
            active = false;
        #pragma omp parallel
            {
                int num_threads = omp_get_num_threads();
                cout << "Number of threads in parallel region: " << num_threads << endl;

            #pragma omp  for
            for (int u = 0; u < n; u++) {
                if (u != source && u != sink && excess[u] > 0) {
                    bool pushed = false;
                    for (int v = 0; v < n && excess[u] > 0; v++) {
                        if (capacity[u][v] - flow[u][v] > 0 && height[u] == height[v] + 1) {
                            push(u, v);
                            pushed = true;
                        }
                    }
                    if (!pushed) {
                        relabel(u);
                    }
                    if (excess[u] > 0) active = true;
                }
            }
        }
        }

        int maxFlow = 0;
        for (int i = 0; i < n; i++) {
            maxFlow += flow[source][i];
        }

        return maxFlow;
    }

private:
    int n;
    vector<vector<int>> capacity;
    vector<vector<int>> flow;
    vector<int> height;
    vector<int> excess;

    void push(int u, int v) {
        int delta = min(excess[u], capacity[u][v] - flow[u][v]);
        flow[u][v] += delta;
        flow[v][u] -= delta;
        excess[u] -= delta;
        excess[v] += delta;
    }

    void relabel(int u) {
        int minHeight = INT_MAX;
        for (int v = 0; v < n; v++) {
            if (capacity[u][v] - flow[u][v] > 0) {
                minHeight = min(minHeight, height[v]);
            }
        }
        if (minHeight < INT_MAX) {
            height[u] = minHeight + 1;
        }
    }
};

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Unable to open file graph.txt" << endl;
        return 1;
    }

    int n;
    inputFile >> n;
    
    PushRelabel graph(n);

    int u, v, cap;
    while (inputFile >> u >> v >> cap) {
        //  cout << u << " "<< v<<" "<<cap<<endl;
        graph.addEdge(u, v, cap);
    }

    // Read source and sink
    int source=0, sink=0;
    
    inputFile.clear();  // Clear the EOF flag to allow reading again
    inputFile >> u >> v;
    source = u;
    sink = v;
    cout << "Source and sink is " <<source << " "<< sink << endl;
    inputFile.close();

    // auto start = omp_get_wtime();
    // int maxFlow = graph.getMaxFlow(source, sink);
    // auto end = omp_get_wtime();
    // // chrono::duration<double> duration = end - start;
    // double duration = end - start;
    // cout << "Sequential Max Flow: " << maxFlow << endl;
    // cout << "Sequential Time Taken: " << duration << " seconds" << endl;

    omp_set_num_threads(1);
    auto start = omp_get_wtime();
    int maxFlow1 = graph.getMaxFlowParallel(source, sink);
    auto end = omp_get_wtime();
    double duration1 = end - start;
    // chrono::duration<double> duration1 = end - start;

    cout << "Parallel Max Flow: " << maxFlow1 << endl;
    cout << "Parallel Time Taken: " << duration1 << " seconds" << endl;

    return 0;
}
