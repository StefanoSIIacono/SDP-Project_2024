# Documentation SDP Project
## Project Q3 Flow Network

### 1. Introduction
The project was about finding the maximum flow that can be sent from a source vertex to a sink vertex in a flow network, represented as a directed graph with capacities on its edges. The project implements Dinic's algorithm to compute the maximum flow in a flow network.

### 2. Design Choices

#### 2.1 Graph Generation
- **Input Parameters**:  
  Describe the parameters used to generate the graph (e.g., number of vertices, edge probability, and maximum edge capacity).

- **Efficiency in Space Usage**:  
  - **Sparse Graphs**: For graphs where most possible edges do not exist (low edge probability), this approach is particularly efficient. By not explicitly storing absent edges (which would have a capacity of zero), you save considerable memory.
  - **Adjacency List-Like Behavior**: The generated output file resembles an adjacency list in terms of storage. The first line in the file corresponds to the total number of vertices in the graph. Following lines store vertices connected to adjacent vertices with their capacity. The last line provides information about the source and sink nodes.

  Example:  total no of vertices
            vetices1 vertice2 capacity
            source sink


- **Dynamic Edge Creation**:  
The decision to create an edge between any two vertices is made dynamically based on the given `edgeProbability`. Depending on the edge probability, we define the denseness of the graph. Graphs with high `edgeProbability` are highly connected and are considered dense graphs. By assigning a random capacity to each edge at the time of its creation, we avoid unnecessary storage for edges with zero capacity.

- **Scalability**:  
Larger graphs with thousands of vertices scale well but exhibit linear growth in memory consumption as the number of vertices and the edge density grows. Graphs with lower density will consume less memory due to sparser connections. This method is designed to scale efficiently with large graphs by focusing on space efficiency and avoiding the pre-allocation of large structures (like full adjacency matrices), allowing it to handle graphs with large numbers of vertices while keeping memory usage low.

- **Potential Trade-Offs**:  
The output file is compact and stores only relevant information. While it may be less interpretable than an adjacency matrix, this method optimizes memory consumption. However, this approach involves some computation since each edge is generated dynamically and its capacity is decided on the fly.

#### 2.2 Implementation Details
- **Randomization**:  
The use of `rand()` seeded with the current time (`srand(time(nullptr))`) ensures that each graph generated is unique, providing a wide variety of test cases for flow network algorithms.

- **File Output**:  
The generated graph is saved in a simple text file, where each line represents an edge with its source, destination, and capacity. The source and sink nodes are explicitly defined at the end of the file.

#### 2.3 Advantages
- **Reduced Memory Footprint**:  
By only storing actual edges, the algorithm minimizes the memory required to represent the graph.

- **Flexibility**:  
The parameters for vertex count, edge probability, and maximum capacity allow for flexible generation of a wide range of graph structures, from very sparse to relatively dense networks.

---

## Documentation for Maximum Flow Calculation Using Dinic's Algorithm

### 1. Introduction
This project implements Dinic's algorithm to compute the maximum flow in a flow network. The algorithm reads a graph from an input file, where each edge is assigned a capacity, and calculates the maximum possible flow from a specified source node to a sink node. The project also includes a comparison between sequential and parallel versions of the algorithm to evaluate performance improvements.

### 2. Design Choices

#### 2.1 Graph Representation
The graph is represented using an adjacency matrix, where each entry `graph[u][v]` holds the capacity of the edge from vertex `u` to vertex `v`. This choice allows for easy access and modification of edge capacities, which is crucial for the operations in Dinic's algorithm.

#### 2.2 Algorithm Implementation
- **BFS (Breadth-First Search)**:  
The BFS function constructs the level graph by finding the shortest path from the source node to all other nodes in the graph. This level graph helps in identifying augmenting paths during the DFS phase.

- **DFS (Depth-First Search)**:  
The DFS function finds blocking flows by exploring the level graph. It recursively finds augmenting paths from the source to the sink, updating the residual capacities along the way.

- **Dinic's Algorithm**:  
The main algorithm repeatedly constructs a level graph using BFS and then finds blocking flows using DFS until no more augmenting paths are found. The sum of all blocking flows gives the maximum flow from the source to the sink.

#### 2.3 Parallelism Design
- **Parallel Version**:  
OpenMP is used to parallelize the execution of the Dinic's algorithm. However, the parallelism is applied at a higher level, where the entire algorithm is executed within a parallel region. This design choice was made to explore the effectiveness of simple parallelization without delving into more complex parallel structures.

### 3. Implementation Details

#### 3.1 Input File Handling
- The input file contains the number of vertices, followed by a list of edges, where each edge is defined by its source vertex, destination vertex, and capacity. The file ends with the source and sink nodes.
- The program reads the graph data from the file and initializes the adjacency matrix accordingly.

#### 3.2 Sequential Version
- The sequential version of Dinic's algorithm is implemented first. It calculates the maximum flow and measures the execution time using `omp_get_wtime()`.

#### 3.3 Parallel Version
- The parallel version uses OpenMP to execute the entire Dinic's algorithm in a parallel region. The number of threads is controlled by `omp_set_num_threads(desired_threads)`. The performance is measured similarly to the sequential version.

### 4. Experimental Evaluation

#### 4.1 Setup
- **Hardware**:  
The experiments were conducted on a system with [insert details: e.g., 4-core CPU, 8GB RAM].

- **Software Environment**:  
The code was compiled using GCC with OpenMP enabled, running on Windows, Linux, and Mac.

#### 4.2 Test Cases
- **Graph Sizes**:  
The algorithm was tested on graphs with varying sizes, from small (100 vertices) to large (50,000 vertices).

- **Thread Counts**:  
The parallel version was tested with different numbers of threads (1, 2, 3, 4, 6, 8 threads) to evaluate scalability.

#### 4.3 Results
- **Performance Comparison**:
- The sequential version was used as the baseline.
- The parallel version's execution time was compared to the sequential version.
- It was observed that with increasing graph size, the parallel version shows some performance gains, though the simple parallelization approach used might not fully exploit the available CPU cores.

- **Memory Usage**:  
No significant difference in memory usage was observed between the sequential and parallel versions since both used the same graph representation and algorithmic approach.

#### 4.4 Analysis
TODO

### 5. Conclusion
This project successfully implements Dinic's algorithm for maximum flow calculation and explores the impact of parallelization using OpenMP. While the parallel version showed some performance improvements, the results suggest that more granular parallelization could be explored to fully utilize the available computational resources.

### 6. Appendices

#### 6.1 Code Listings
- **Graph Generation Code**:  
The code for generating test graphs is included in `generate_graph.cpp`.

- **Maximum Flow Calculation Code**:  
The full source code for the Dinic's algorithm implementation, including both sequential and parallel versions, is included in `Dincs.cpp`.

