# SDP-Project_2024

## Maximum Flow Algorithm Project

### Project Description

- This project implements the Edmonds-Karp algorithm to solve the Maximum Flow Problem in a flow network.
- The implementation includes both sequential and parallel versions using OpenMP for parallelization.
- The project is implemented using C++ programming.

### Features

- Reads graph input from a file (`graph.txt`).
- Implements the Edmonds-Karp algorithm for maximum flow calculation.
- Provides both sequential and parallel implementations.
- Measures and compares the performance of both implementations.
- Includes a graph generation utility.

### Installation and Usage

1. Ensure you have a C++ compiler installed (e.g., `g++`) with OpenMP support.

2. Compile the code using the following commands:

    To compile the main code:
    ```sh
    g++ -fopenmp -o ParallelGraph ParallelGraph.cpp
    ```

    To compile the file to generate the random graph:
    ```sh
    g++ -o generate_graph generate_graph.cpp
    ```

3. Run the programs:

    To run the main program:
    ```sh
    ./ParallelGraph
    ```

    To run the graph generation utility:
    ```sh
    ./generate_graph
    ```

4. Enter the filename as `graph.txt` when prompted.

### Code Structure

- **ParallelGraph.cpp**: Main code file implementing the Edmonds-Karp algorithm.
- **generate_graph.cpp**: File to generate a random graph and save it to a file (`graph.txt`).

### Algorithms Used

- **Edmonds-Karp Algorithm**: An implementation of the Ford-Fulkerson method using BFS to find augmenting paths.
- **Parallelization with OpenMP**: Utilizes OpenMP to parallelize parts of the algorithm for improved performance on multi-core systems.

### Performance

- The program measures and prints the execution time for both the sequential and parallel versions of the algorithm.
- Performance can be tested using different graph sizes and configurations.

### Extra Files

- These files are for testing and understanding the algorithm and can be deleted in the final version:
  - **Graph.cpp**: Used to get maximum flow using Ford-Fulkerson.
  - **Graph2.cpp**: Used to get the maximum flow using Edmonds-Karp.
  - **try.cpp**: Used to try some parallel execution commands to check how they work.


