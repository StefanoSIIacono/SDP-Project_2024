#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

void generateGraphFile(const string& filename, int numVertices, int edgeProbability, int maxCapacity) {
    ofstream outfile(filename);
    if (!outfile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    
    // Write the number of vertices
    outfile << numVertices << endl;
    
    srand(time(nullptr)); // Seed for randomness
    
    // Generate and write the adjacency matrix
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (i != j && (rand() % 100) < edgeProbability) { // Randomly decide if an edge exists
                int capacity = rand() % maxCapacity + 1; // Random capacity between 1 and maxCapacity
                outfile << capacity << " ";
            } else {
                outfile << 0 << " ";
            }
        }
        outfile << endl;
    }
    
    // Define source and sink (for simplicity, source = 0 and sink = numVertices-1)
    int s = 0;
    int t = numVertices - 1;
    outfile << s << " " << t << endl;
    
    outfile.close();
}

int main() {
    string filename = "graph.txt";
    int numVertices = 10000; // Number of nodes
    int edgeProbability = 1; // Probability factor for edge creation (1% chance)
    int maxCapacity = 1000;  // Maximum capacity for an edge

    generateGraphFile(filename, numVertices, edgeProbability, maxCapacity);
    
    cout << "Graph generated and saved to " << filename << endl;
    
    return 0;
}
