#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <sstream> // For building the output in memory
#include <chrono>  // For timing

using namespace std;
using namespace std::chrono;

void generateGraphFile(const string& filename, int numVertices, int edgeProbability, int maxCapacity) {
    stringstream output;

    // Write the number of vertices
    output << numVertices << endl;
    
    srand(time(nullptr)); // Seed for randomness
    
    // Generate the adjacency matrix in memory
    vector<vector<int>> adjacencyMatrix(numVertices, vector<int>(numVertices, 0));
    
    for (int i = 0; i < numVertices; ++i) {
        for (int j = i + 1; j < numVertices; ++j) { // Only compute for upper triangle
            if ((rand() % 100) < edgeProbability) { // Randomly decide if an edge exists
                int capacity = rand() % maxCapacity + 1; // Random capacity between 1 and maxCapacity
                adjacencyMatrix[i][j] = capacity;
                adjacencyMatrix[j][i] = capacity; // Mirror the edge
            }
        }
    }
    
    // Output the adjacency matrix to the stringstream
    for (const auto& row : adjacencyMatrix) {
        for (int value : row) {
            output << value << " ";
        }
        output << endl;
    }
    
    // Define source and sink (for simplicity, source = 0 and sink = numVertices-1)
    int s = 0;
    int t = numVertices - 1;
    output << s << " " << t << endl;
    
    // Write all at once to the file
    ofstream outfile(filename);
    if (!outfile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    outfile << output.str();
    outfile.close();
}

int main() {
    string filename = "graph.txt";
    int numVertices;
    int edgeProbability;
    int maxCapacity;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the edge probability (in %): ";
    cin >> edgeProbability;
    cout << "Enter the maximum capacity for an edge: ";
    cin >> maxCapacity;
    
    auto start = high_resolution_clock::now();
    generateGraphFile(filename, numVertices, edgeProbability, maxCapacity);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    
    cout << "Graph generated and saved to " << filename << endl;
    cout << "Time taken to generate the graph: " << duration.count() << " milliseconds" << endl;
    
    return 0;
}
