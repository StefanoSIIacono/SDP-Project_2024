# SDP-Project_2024

# Maximum Flow Algorithm Project

## Project Description

- This project implements the Edmonds-Karp algorithm to solve the Maximum Flow Problem in a flow network. 
- The implementation includes both sequential and parallel versions using OpenMP for parallelization.
- Project is implemented using C++ programming

## Features

- Reads graph input from a file (graph.txt)
- Implements the Edmonds-Karp algorithm for maximum flow calculation
- Provides both sequential and parallel implementations
- Measures and compares the performance of both implementations
- Includes a graph generation utility

## Installation and Usage


1. Ensure you have a C++ compiler installed (e.g., g++) with OpenMP support.
2. Compile the code using the following command:
    to compile the main code
    ```sh
    g++ -fopenmp -o ParallelGraph ParallelGraph.cpp
    ./ParallelGraph
    ```

    to complie the file to generate the random graph is
    ```sh
    g++ -o generate_graph generate_graph.cpp
    ./generate_graph
    ```
3. Enter the filename as graph.txt

## Code Structure

- **ParallelGraph.cpp**: Main code file implementing the Edmonds-Karp algorithm.
- **generate_graph.cpp**: File to generate a random graph and save it to a file(graph.txt).

## Algorithms Used

- **Edmonds-Karp Algorithm**: An implementation of the Ford-Fulkerson method using BFS to find augmenting paths.
- **Parallelization with OpenMP**: Utilizes OpenMP to parallelize parts of the algorithm for improved performance on multi-core systems.

## Performance

- The program measures and prints the execution time for both the sequential and parallel versions of the algorithm.
- Performance can be tested using different graph sizes and configurations.



## extra files i have which we can delete in the final 
- just have those file for testing and understanding the algorithm
- Graph.cpp :- used to get maximum flow using fordFulkerson
- Graph2.cpp :- used to get the maximum flow using EdmondsKarp
- try.cpp :- just used to try some of the parallel execution commands to check how they work
