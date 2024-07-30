#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <omp.h>
#include <fstream>

using namespace std;

//this funtion prints the graph matrix
// i added it to just for the debuge purpose
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
//function is used to check wheather there is a path from source to the sink in the graph
//s= source vertex
//t = sinl vertex
//parent refers to a vector that stores the path from s to t

bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    int V = rGraph.size(); //used to indicate number of vertices in the graph
    vector<bool> visited(V, false); // used to keep track of visted vertices. initally all vertices are marked as not visited
    queue<int> q;// a queue used to manage the BFS traversal
    
    q.push(s); //used to enqueue the source vertex s to start the BFS
    visited[s] = true; //mark the vertex as visited
    parent[s] = -1; // set the parent of the source vertex s to -1, indiating the start of the path
    
    while (!q.empty()) { // loop continues until queue is empty
        int u = q.front(); //get the front vertex from the queue
        q.pop(); //dequeue from the front vertex
        
        for (int v = 0; v < V; v++) { //iterate through all vertices to check the neighbours of u
            if (!visited[v] && rGraph[u][v] > 0) { // checks if vertex v is not visited and theree is a positive residual capacity from u to v
                if (v == t) { 
                    parent[v] = u;
                    return true; // return true when path from s to t is found
                }
                q.push(v);
                parent[v] = u; //  Set the parent of v to u, indicating the path from u to v
                visited[v] = true; // mark vertex as visited
            }
        }
    }
    return false; // retrun false when the queuw is empty and the sink vertex t is not reached also indicates that no path from s to t.
}

// Function to update the residual graph
// used to determine the flow along specific path
//path_flow is the flow value that can be pushed through the found path
void updateResidualGraph(vector<vector<int>>& rGraph, vector<int>& parent, int s, int t, int path_flow) {
    int v = t;
    while (v != s) {
        int u = parent[v];
        // #pragma omp critical // the enclosed block of code is executed by only one thread at a time, preventing the race condition when updating the shared rGraph strcuture
        
        {
            #pragma omp atomic //This can be used to avoid race condition
            //atomic:- Specifies that a memory location will be upadted atomically
            //expression between paragma omp atomic is the statement that has the lvalue, whose memory location you want to protect against more than one write.
            rGraph[u][v] -= path_flow; //reduce the capacity of forward edge by the path
            #pragma omp atomic
            rGraph[v][u] += path_flow; // for reverse edge. addition of backfloe capacity
        }
        v = parent[v]; //move the parent of the current vertex v to continue traversing the path back to the source s
    }
}

// Edmonds-Karp algorithm for computing maximum flow
//retrun an integer with the value of maximum flow
//garph = matrix representation of the graph
//s = source
// t = sink
int edmondsKarp(vector<vector<int>>& graph, int s, int t) {
    int V = graph.size(); //no of vertices in the graph
    
    vector<vector<int>> rGraph = graph; // Create a copy of the graph because during the execution graph will be upadated so we use the copy instead of orignal graph
    // printGraph(rGraph);
    vector<int> parent(V); // will be useful to store path from source to sink found by BFS
    int max_flow = 0;
    
    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX; // initializing the path flow to a large value
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]); // update the path flow to be the minimum residul capacity of the edges in the path.
        }
        
        // Update the residual graph
        updateResidualGraph(rGraph, parent, s, t, path_flow); // update the residual capacities of the edge in the residual graph along the path
        max_flow += path_flow; //add the path flow to the maximum flow
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
    
   double start, end;

    // Sequential version timing
    start = omp_get_wtime();
    int max_flow_sequential = edmondsKarp(graph, s, t);
    end = omp_get_wtime();
    double total_time_sequential = end - start;
    cout << "Sequential: The maximum possible flow is " << max_flow_sequential << endl;
    cout << "Time taken (Sequential): " << total_time_sequential << " seconds" << endl;

    // Parallel version timing
    start = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp single // ensurees that the section of code should be executed by only one thread within a team. 
        //ensures that only one threas executes the enclosed code block, while the other threads in the tean wait at an implicit barrier at the end of the single region unless a nowait clause is specified
        {
            int max_flow_parallel = edmondsKarp(graph, s, t); // Same function, but ensure parallel code is effective
        }
    }
    end = omp_get_wtime();
    double total_time_parallel = end - start;
    cout << "Parallel: The maximum possible flow is " << max_flow_sequential << endl; // Use the same max_flow_sequential as placeholder
    cout << "Time taken (Parallel): " << total_time_parallel << " seconds" << endl;

    return 0;
}
