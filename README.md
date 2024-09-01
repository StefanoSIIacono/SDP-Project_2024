SDP-Project_2024

-----------------------------------------------------------------------------------------------------------

Maximum Flow Algorithm Project

-----------------------------------------------------------------------------------------------------------

Project Description

This project implements three key algorithms to solve the Maximum Flow Problem in a flow network:
- Edmonds-Karp Algorithm
- Dinitz's Algorithm
- Push-Relabel Algorithm
Each algorithm is implemented in both sequential and parallel versions, with the parallel versions optimized using OpenMP.
Additionally, a graph generation code is included, allowing you to create test graphs easily if you just want to test the algorithms without providing your own input.

-----------------------------------------------------------------------------------------------------------

Implementation Details:

- Programming Language: 
The project is implemented in C++.
- Parallelization: 
Parallel versions leverage OpenMP for enhanced performance on multi-core systems.
- Further Details: 
  Detailed descriptions of each algorithm, including their implementation specifics and theoretical background, can be found in the accompanying documentation file `DOCUMENTATION.md`. This file provides in-depth explanations of the algorithms, their parallelization strategies, and any additional considerations related to their implementation.

-----------------------------------------------------------------------------------------------------------

Features

- Multiple Maximum Flow Algorithms:
  - Implements three different algorithms to solve the Maximum Flow Problem: Edmonds-Karp, Dinitz's, and Push-Relabel.

- Sequential and Parallel Implementations:
  - Provides both sequential and parallel implementations for each algorithm.

- Performance Measurement:
  - Measures execution time for both the sequential and parallel implementations of each algorithm.

- Graph Generation Utility:
  - Includes a tool for generating test graphs to facilitate algorithm testing.

- Supported Graph File Format:
  - The input graph should be provided in a `.txt` file with the following structure:
    - First Line: Number of vertices (n) and number of edges (m).
    - Next m Lines: Each line represents an edge with three values: the starting vertex, the ending vertex, and the capacity of the edge.
    - Last Line: Contains two values representing the source and sink vertices.
  - An example input file is provided in the project folder under `graph.txt`.

-----------------------------------------------------------------------------------------------------------

Compilation and Execution

1. Ensure you have a C++ compiler installed:
   - Make sure you have a C++ compiler like `g++` installed with OpenMP support.

2. Compile the code using the following commands:

   - To compile the Edmonds-Karp algorithm:
     g++ -fopenmp -o Edmonds_Karp.exe Edmonds_Karp.cpp

   - To compile Dinitz's algorithm:
     g++ -fopenmp -o Dinitz.exe Dinitz.cpp

   - To compile the Push-Relabel algorithm:
     g++ -fopenmp -o Push_Relabel.exe Push_Relabel.cpp

   - To compile the graph generation utility:
     g++ -o generate_graph.exe generate_graph.cpp

3. Run the programs:

   - To run the Edmonds-Karp algorithm:
     ./Edmonds_Karp.exe <graph_file.txt> [number_of_threads]

   - To run Dinitz's algorithm:
     ./Dinitz.exe <graph_file.txt> [number_of_threads]

   - To run the Push-Relabel algorithm:
     ./Push_Relabel.exe <graph_file.txt> [number_of_threads]

   - To run the graph generation utility:
     ./generate_graph.exe [output_file.txt]

     - Note: Replace `[output_file.txt]` with the desired name for the generated graph file. If omitted, the default filename `graph.txt` will be used.

     - Interactive Prompts: After execution, you will be prompted to enter the following details via standard input:
       - Number of vertices: The total number of vertices in the graph.
       - Edge probability: The probability (in percentage) that an edge exists between any pair of vertices.
       - Maximum capacity: The maximum capacity for any edge in the graph.

   - Note: For all algorithms, replace `<graph_file.txt>` with the name of your graph file. The `[number_of_threads]` argument is optional and specifies the number of threads to be used in parallel execution. If omitted, the program defaults to 8 threads.

-----------------------------------------------------------------------------------------------------------

Code Structure

- Edmonds_Karp.cpp: Main code file implementing the Edmonds-Karp algorithm.
- Dinitz.cpp: Main code file implementing Dinitz's algorithm.
- Push_Relabel.cpp: Main code file implementing the Push-Relabel algorithm.
- generate_graph.cpp: Utility for generating a random graph and saving it to a file (default: `graph.txt`).

-----------------------------------------------------------------------------------------------------------

Algorithms Used

- Edmonds-Karp Algorithm: 
  - Implements the Ford-Fulkerson method for computing the maximum flow in a flow network.
  - Utilizes Breadth-First Search (BFS) to find augmenting paths.
  - The algorithm repeatedly finds augmenting paths from the source to the sink and updates the flow until no more augmenting paths can be found.

- Dinitz's Algorithm:
  - An efficient algorithm for finding the maximum flow in a flow network.
  - Uses a level graph and blocking flows to improve performance over the Ford-Fulkerson method.
  - Constructs level graphs using Breadth-First Search and finds blocking flows using Depth-First Search.

- Push-Relabel Algorithm:
  - An advanced algorithm for computing maximum flow in a flow network.
  - Operates by maintaining a preflow and adjusting the flow using push and relabel operations.
  - Efficient in practice, especially for networks with large numbers of vertices and edges.

- Parallelization with OpenMP:
  - Uses OpenMP to parallelize certain parts of the algorithms to leverage multi-core processors.
  - Improves performance by dividing tasks among multiple threads and reducing execution time for large networks.
  - The implementation includes parallelized sections to handle the BFS in Edmonds-Karp, the level graph construction in Dinitz's, and the push/relabel operations in the Push-Relabel algorithm.

-----------------------------------------------------------------------------------------------------------

Parallel Execution

Efficiency on Multicore CPUs

The parallel implementations of the algorithms are designed to make use of multiple CPU cores to enhance performance. Here’s a quick guide: 

- Multicore CPUs: The parallel algorithms perform best on systems with multiple cores, as they can divide the workload among several threads, leading to reduced execution times.

- Single-Core CPUs: On single-core systems, parallelization may not offer significant benefits. The overhead from managing multiple threads can sometimes outweigh the performance gains.

However, the effectiveness of parallelization varies by algorithm.

- Thread Management: The number of threads used can be specified when running the algorithms. The default is 8 threads, but you can adjust this based on your system’s capabilities.

Practical Considerations

- System Resources: Ensure your system has enough CPU and memory resources to handle parallel execution. Excessive threading on limited resources can lead to reduced performance.

- Testing: Experiment with different thread counts to find the best configuration for your hardware.

-----------------------------------------------------------------------------------------------------------

Memory Management

Memory usage varies by algorithm:

- Edmonds-Karp Algorithm: Uses a matrix for residual capacities and additional arrays. Memory usage is primarily dependent on the number of vertices.

- Dinitz's Algorithm: Similar to Edmonds-Karp but includes extra structures like a level graph and start array.

- Push-Relabel Algorithm: Requires additional matrices and arrays, leading to higher memory usage compared to the other algorithms.

RAM Requirements

- Large Graphs: 
  When working with large graphs, the memory requirements can increase significantly. For very large graphs, the memory usage can become a limiting factor and may require careful management of system resources to prevent out-of-memory errors.

  - Example: For a graph with 10^4 vertices, the adjacency matrix alone will require on the order of 100 MB of RAM. With additional arrays and data structures, the total memory usage can be considerably higher.

- System Considerations: 
  Ensure that your system has adequate RAM to handle the size of the graphs you plan to work with. For extremely large graphs, you may need to use machines with large amounts of memory or consider optimizing your algorithms for better memory efficiency.

-----------------------------------------------------------------------------------------------------------

Execution Time

For large graphs, the execution time of these algorithms can increase significantly. As the size of the graph grows, the complexity and number of operations involved in finding the maximum flow also grow. This can lead to substantial increases in computation time.
