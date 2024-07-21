#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent an edge in the flow network
struct Edge {
  int source, sink, capacity;
};

// Function to perform Breadth-First Search (BFS)
bool bfs(vector<vector<int>>& residual_capacity, int source, int sink, vector<int>& parent) {
  // Create a visited array to keep track of visited nodes
  vector<bool> visited(residual_capacity.size(), false);

  // Create BFS queue
  queue<int> q;

  // Mark source as visited and enqueue it
  visited[source] = true;
  q.push(source);

  // Standard BFS Loop
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v = 0; v < residual_capacity[u].size(); v++) {
      if (!visited[v] && residual_capacity[u][v] > 0) {
        visited[v] = true;
        q.push(v);
        parent[v] = u;
      }
    }
  }

  // Return true if sink is reached
  return visited[sink];
}

// Ford-Fulkerson algorithm to find maximum flow
int fordFulkerson(vector<vector<int>>& capacity, int source, int sink) {
  int max_flow = 0;

  // Create a residual capacity matrix
  vector<vector<int>> residual_capacity(capacity.size(), vector<int>(capacity.size(), 0));
  for (int i = 0; i < capacity.size(); i++) {
    for (int j = 0; j < capacity[i].size(); j++) {
      residual_capacity[i][j] = capacity[i][j];
    }
  }

  // Augment flow while there is a path from source to sink
  vector<int> parent(residual_capacity.size());
  while (bfs(residual_capacity, source, sink, parent)) {
    // Find minimum residual capacity in the path from source to sink
    int path_flow = std::numeric_limits<int>::max();
    for (int v = sink; v != source; v = parent[v]) {
      int u = parent[v];
      path_flow = min(path_flow, residual_capacity[u][v]);
    }

    // Update residual capacities and flow values
    for (int v = sink; v != source; v = parent[v]) {
      int u = parent[v];
      residual_capacity[u][v] -= path_flow;
      residual_capacity[v][u] += path_flow;
    }

    // Add path flow to overall flow
    max_flow += path_flow;
  }

  // Return the overall maximum flow
  return max_flow;
}

int main() {
  // Sample graph with capacities
//   vector<vector<int>> capacity = {
//       {0, 16, 13, 0, 0, 0}, //node s
//       {0, 0, 0, 12, 0, 0}, // node v1
//       {0, 4, 0, 0, 14, 0}, //node v2
//       {0, 0, 9, 0, 0, 20}, //node v3
//       {0, 0, 0, 7, 0, 4}, //node D
//       {0, 0, 0, 0, 0, 0} //node t
//   };

  vector<vector<int>> capacity = {
    //{S, A,B.C,D,T}
      {0, 3, 7, 0, 0, 0}, //node s
      {0, 0, 0, 3, 4, 0}, // node A
      {0, 0, 0, 0, 3, 2}, //node B
      {0, 5, 0, 0, 3, 0}, //node C
      {0, 0, 0, 0, 0, 6}, //node D
      {0, 0, 0, 0, 0, 0} //node t
  };

  int source = 0, sink = 5;

  // Find maximum flow using Ford-Fulkerson algorithm
  int max_flow = fordFulkerson(capacity, source, sink);

  cout << "Maximum flow from " << source << " to " << sink << " is " << max_flow << endl;

  return 0;
}
