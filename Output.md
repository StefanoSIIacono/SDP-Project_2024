## Observation


| **Run**           | **Number of Vertices** | **Edge Probability (%)** | **Max Capacity for Edge** | **Source (s)** | **Sink (t)** | **Sequential Max Flow** | **Time (Sequential) (s)** | **Number of Threads (Parallel)** | **Parallel Max Flow** | **Time (Parallel) (s)** |
|-------------------|------------------------|--------------------------|---------------------------|----------------|--------------|-------------------------|----------------------------|-------------------------------|-----------------------|--------------------------|
| **Result 1**      | 5000                   | 5                        | 20                        | 0              | 4999         | 2523                    | 62.979                     | 8                             | 2523                  | 86.314                   |
| **Result 2**      | 5000                      | 5                         |  20                         | 0               |   4999           |   2523                      |  34.191                          |  8                             |  2523                     |    35.921                      |
| **Result 3**      | 5000                      | 5                         |  20                         | 0               |   4999           |   2523                      |  35.103                          |  1                             |  2523                     |    34.995                      |
| **Result 4**      | 5000                      | 5                         |  20                         | 0               |   4999           |   2523                      |  34.338                         |  2                             |  2523                     |    34.206                      |
| **Result 5**      | 5000                      | 5                         |  20                         | 0               |   4999           |   2523                      |  34.366                        |  3                             |  2523                     |    34.973                      |
| **Result 6**      | 5000                      | 5                         |  20                         | 0               |   4999           |   2523                      |  34.218                        |  4                             |  2523                     |    34.107                      |
| **Result 7**      | 5000                      | 5                         |  20                         | 0               |   4999           |   2523                      |  34.267                        |  5                             |  2523                     |    34.347                      |
| **Result 8**      | 5000                      | 10                         |  20                         | 0               |   4999           |   5143                      |  83.628                        |  5                             |  5143                     |    84.041                      |
| **Result 9**      | 5000                      | 10                         |  20                         | 0               |   4999           |   5143                      |  83.126                        |  3                             |  5143                     |    83.253                      |
| **Result 10**      | 5000                      | 10                         |  20                         | 0               |   4999           |   5143                      |  84.152                       |  6                             |  5143                     |    83.318                      |
| **Result 11**      | 10000                     | 5                         |  20                         | 0               |   9999           |   5170                      | 359.912                      |  6                             |  5170                     |    411.826                      |
| **Result 12**      | 10000                     | 5                         |  20                         | 0               |   9999           |   5170                      | 421.727                      |  3                             |  5170                     |    410.449                     |


Enter the filename: graph.txt
the value for s and t are 0 4999
Sequential: The maximum possible flow is 2523
Time taken (Sequential): 58.5093 seconds
Number of threads running in parallel: 8
Parallel: The maximum possible flow is 2523
Time taken (Parallel): 57.4862 seconds

//graph generation*******************************************************************
Enter the number of vertices: 10000
Enter the edge probability (in %): 20
Enter the maximum capacity for an edge: 30
Graph generated and saved to graph.txt
Time taken to generate the graph: 9137 milliseconds

Enter the filename: graph.txt
the value for s and t are 0 9999
Sequential: The maximum possible flow is 30173
Time taken (Sequential): 3055.17 seconds
Number of threads running in parallel: 8
Parallel: The maximum possible flow is 30173
Time taken (Parallel): 3056.95 seconds


//graph generation*******************************************************************
Enter the number of vertices: 100
Enter the edge probability (in %): 50
Enter the maximum capacity for an edge: 20
Graph generated and saved to graph.txt
Time taken to generate the graph: 12 milliseconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 589
Time taken (Sequential): 0.0301662 seconds
Number of threads running in parallel: 4
Parallel: The maximum possible flow is 589
Time taken (Parallel): 0.0202074 seconds

//graph generation*******************************************************************
Enter the number of vertices: 100
Enter the edge probability (in %): 1  
Enter the maximum capacity for an edge: 20
Graph generated and saved to graph.txt
Time taken to generate the graph: 5 milliseconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 0
Time taken (Sequential): 0.000746717 seconds
Number of threads running in parallel: 4
Parallel: The maximum possible flow is 0
Time taken (Parallel): 0.000662129 seconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 0
Time taken (Sequential): 0.000739202 seconds
Number of threads running in parallel: 1
Parallel: The maximum possible flow is 0
Time taken (Parallel): 0.000388009 seconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 0
Time taken (Sequential): 0.000706616 seconds
Number of threads running in parallel: 2
Parallel: The maximum possible flow is 0
Time taken (Parallel): 0.00095002 seconds

the value for s and t are 0 99
Sequential: The maximum possible flow is 0
Time taken (Sequential): 0.000569055 seconds
Number of threads running in parallel: 3
Parallel: The maximum possible flow is 0
Time taken (Parallel): 0.000876701 seconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 0
Time taken (Sequential): 0.000714124 seconds
Number of threads running in parallel: 4
Parallel: The maximum possible flow is 0
Time taken (Parallel): 0.000751244 seconds

the value for s and t are 0 99
Sequential: The maximum possible flow is 0
Time taken (Sequential): 0.000622298 seconds
Number of threads running in parallel: 5
Parallel: The maximum possible flow is 0
Time taken (Parallel): 0.000760087 seconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 0
Time taken (Sequential): 0.000187914 seconds
Number of threads running in parallel: 6
Parallel: The maximum possible flow is 0
Time taken (Parallel): 0.000459554 seconds



//Graph generation******************************************************************
Enter the number of vertices: 100
Enter the edge probability (in %): 10
Enter the maximum capacity for an edge: 20
Graph generated and saved to graph.txt
Time taken to generate the graph: 4 milliseconds


Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 64
Time taken (Sequential): 0.00854546 seconds
Number of threads running in parallel: 1
Parallel: The maximum possible flow is 64
Time taken (Parallel): 0.00650695 seconds


Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 64
Time taken (Sequential): 0.0050144 seconds
Number of threads running in parallel: 2
Parallel: The maximum possible flow is 64
Time taken (Parallel): 0.00498867 seconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 64
Time taken (Sequential): 0.00838365 seconds
Number of threads running in parallel: 4
Parallel: The maximum possible flow is 64
Time taken (Parallel): 0.00820107 seconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 64
Time taken (Sequential): 0.0103419 seconds
Number of threads running in parallel: 6
Parallel: The maximum possible flow is 64
Time taken (Parallel): 0.00774239 seconds


Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 64
Time taken (Sequential): 0.00874454 seconds
Number of threads running in parallel: 8
Parallel: The maximum possible flow is 64
Time taken (Parallel): 0.0159514 seconds

//Graph Generation************************************************************************
Enter the number of vertices: 100
Enter the edge probability (in %): 30
Enter the maximum capacity for an edge: 20
Graph generated and saved to graph.txt
Time taken to generate the graph: 4 milliseconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 236
Time taken (Sequential): 0.0165807 seconds
Number of threads running in parallel: 1
Parallel: The maximum possible flow is 236
Time taken (Parallel): 0.00949473 seconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 236
Time taken (Sequential): 0.0377021 seconds
Number of threads running in parallel: 3
Parallel: The maximum possible flow is 236
Time taken (Parallel): 0.0126964 seconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 236
Time taken (Sequential): 0.0139718 seconds
Number of threads running in parallel: 5
Parallel: The maximum possible flow is 236
Time taken (Parallel): 0.0124296 seconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 236
Time taken (Sequential): 0.0144212 seconds
Number of threads running in parallel: 8
Parallel: The maximum possible flow is 236
Time taken (Parallel): 0.0179606 seconds

//graph generation******************************************************************
Enter the number of vertices: 100
Enter the edge probability (in %): 50
Enter the maximum capacity for an edge: 20
Graph generated and saved to graph.txt
Time taken to generate the graph: 5 milliseconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 564
Time taken (Sequential): 0.0296096 seconds
Number of threads running in parallel: 8
Parallel: The maximum possible flow is 564
Time taken (Parallel): 0.0313454 seco

the value for s and t are 0 99
Sequential: The maximum possible flow is 564
Time taken (Sequential): 0.0256748 seconds
Number of threads running in parallel: 6
Parallel: The maximum possible flow is 564
Time taken (Parallel): 0.0223727 seconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 564
Time taken (Sequential): 0.0302564 seconds
Number of threads running in parallel: 4
Parallel: The maximum possible flow is 564
Time taken (Parallel): 0.021448 seconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 564
Time taken (Sequential): 0.0309701 seconds
Number of threads running in parallel: 2
Parallel: The maximum possible flow is 564
Time taken (Parallel): 0.0218763 seconds


Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 564
Time taken (Sequential): 0.0265645 seconds
Number of threads running in parallel: 1
Parallel: The maximum possible flow is 564
Time taken (Parallel): 0.0200309 seconds

//graph generate*********************************************************************
Enter the number of vertices: 100
Enter the edge probability (in %): 100
Enter the maximum capacity for an edge: 20
Graph generated and saved to graph.txt
Time taken to generate the graph: 3 milliseconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 1005
Time taken (Sequential): 0.0416742 seconds
Number of threads running in parallel: 1
Parallel: The maximum possible flow is 1005
Time taken (Parallel): 0.0361866 seconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 1005
Time taken (Sequential): 0.0452928 seconds
Number of threads running in parallel: 3
Parallel: The maximum possible flow is 1005
Time taken (Parallel): 0.0362081 seconds

Enter the filename: graph.txt 
the value for s and t are 0 99
Sequential: The maximum possible flow is 1005
Time taken (Sequential): 0.0682879 seconds
Number of threads running in parallel: 5
Parallel: The maximum possible flow is 1005
Time taken (Parallel): 0.0383448 seconds

Enter the filename: graph.txt
the value for s and t are 0 99
Sequential: The maximum possible flow is 1005
Time taken (Sequential): 0.0371706 seconds
Number of threads running in parallel: 7
Parallel: The maximum possible flow is 1005
Time taken (Parallel): 0.0384835 seconds

//graph generate **********************************************************************
Enter the number of vertices: 1000
Enter the edge probability (in %): 1
Enter the maximum capacity for an edge: 20
Graph generated and saved to graph.txt
Time taken to generate the graph: 73 milliseconds

the value for s and t are 0 999
Sequential: The maximum possible flow is 120
Time taken (Sequential): 0.813808 seconds
Number of threads running in parallel: 7
Parallel: The maximum possible flow is 120
Time taken (Parallel): 0.809217 seconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 120
Time taken (Sequential): 0.808998 seconds
Number of threads running in parallel: 5
Parallel: The maximum possible flow is 120
Time taken (Parallel): 0.797528 seconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 120
Time taken (Sequential): 0.802259 seconds
Number of threads running in parallel: 3
Parallel: The maximum possible flow is 120
Time taken (Parallel): 0.814512 seconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 120
Time taken (Sequential): 0.807433 seconds
Number of threads running in parallel: 1
Parallel: The maximum possible flow is 120
Time taken (Parallel): 0.821103 seconds

//graph generate************************************************************************
Enter the number of vertices: 1000
Enter the edge probability (in %): 10
Enter the maximum capacity for an edge: 20
Graph generated and saved to graph.txt
Time taken to generate the graph: 103 milliseconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 836
Time taken (Sequential): 1.15912 seconds
Number of threads running in parallel: 1
Parallel: The maximum possible flow is 836
Time taken (Parallel): 1.16109 seconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 836
Time taken (Sequential): 1.14033 seconds
Number of threads running in parallel: 2
Parallel: The maximum possible flow is 836
Time taken (Parallel): 1.14679 seconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 836
Time taken (Sequential): 1.16106 seconds
Number of threads running in parallel: 4
Parallel: The maximum possible flow is 836
Time taken (Parallel): 1.28562 seconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 836
Time taken (Sequential): 1.18098 seconds
Number of threads running in parallel: 6
Parallel: The maximum possible flow is 836
Time taken (Parallel): 1.19839 seconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 836
Time taken (Sequential): 1.13016 seconds
Number of threads running in parallel: 8
Parallel: The maximum possible flow is 836
Time taken (Parallel): 1.16456 seconds

//graph_generate************************************************************************
Enter the number of vertices: 1000
Enter the edge probability (in %): 50
Enter the maximum capacity for an edge: 20
Graph generated and saved to graph.txt
Time taken to generate the graph: 115 milliseconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 5193
Time taken (Sequential): 13.7877 seconds
Number of threads running in parallel: 8
Parallel: The maximum possible flow is 5193
Time taken (Parallel): 13.6113 seconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 5193
Time taken (Sequential): 13.7443 seconds
Number of threads running in parallel: 6
Parallel: The maximum possible flow is 5193
Time taken (Parallel): 14.0766 seconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 5193
Time taken (Sequential): 13.6844 seconds
Number of threads running in parallel: 5
Parallel: The maximum possible flow is 5193
Time taken (Parallel): 13.7259 seconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 5193
Time taken (Sequential): 13.6028 seconds
Number of threads running in parallel: 2
Parallel: The maximum possible flow is 5193
Time taken (Parallel): 13.5204 seconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 5193
Time taken (Sequential): 14.0663 seconds
Number of threads running in parallel: 1
Parallel: The maximum possible flow is 5193
Time taken (Parallel): 13.7719 seconds

//graph generation*******************************************************************
Enter the number of vertices: 1000
Enter the edge probability (in %): 80 
Enter the maximum capacity for an edge: 20
Graph generated and saved to graph.txt
Time taken to generate the graph: 87 milliseconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 8419
Time taken (Sequential): 28.3073 seconds
Number of threads running in parallel: 1
Parallel: The maximum possible flow is 8419
Time taken (Parallel): 27.9313 seconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 8419
Time taken (Sequential): 27.2664 seconds
Number of threads running in parallel: 3
Parallel: The maximum possible flow is 8419
Time taken (Parallel): 27.255 seconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 8419
Time taken (Sequential): 27.5977 seconds
Number of threads running in parallel: 5
Parallel: The maximum possible flow is 8419
Time taken (Parallel): 27.0554 seconds

Enter the filename: graph.txt
the value for s and t are 0 999
Sequential: The maximum possible flow is 8419
Time taken (Sequential): 28.2239 seconds
Number of threads running in parallel: 8
Parallel: The maximum possible flow is 8419
Time taken (Parallel): 28.3605 seconds

//graph generate********************************************************************
Enter the number of vertices: 10000
Enter the edge probability (in %): 1
Enter the maximum capacity for an edge: 20
Graph generated and saved to graph.txt
Time taken to generate the graph: 8431 milliseconds

Enter the filename: graph.txt
the value for s and t are 0 9999
Sequential: The maximum possible flow is 929
Time taken (Sequential): 180.932 seconds
Number of threads running in parallel: 8
Parallel: The maximum possible flow is 929
Time taken (Parallel): 181.581 seconds

Enter the filename: graph.txt
the value for s and t are 0 9999
Sequential: The maximum possible flow is 929
Time taken (Sequential): 183.04 seconds
Number of threads running in parallel: 6
Parallel: The maximum possible flow is 929
Time taken (Parallel): 181.326 seconds


Enter the filename: graph.txt
the value for s and t are 0 9999
Sequential: The maximum possible flow is 929
Time taken (Sequential): 182.392 seconds
Number of threads running in parallel: 4
Parallel: The maximum possible flow is 929
Time taken (Parallel): 180.956 seconds


Enter the filename: graph.txt
the value for s and t are 0 9999
Sequential: The maximum possible flow is 929
Time taken (Sequential): 182.229 seconds
Number of threads running in parallel: 2
Parallel: The maximum possible flow is 929
Time taken (Parallel): 181.465 seconds

Enter the filename: graph.txt
the value for s and t are 0 9999
Sequential: The maximum possible flow is 929
Time taken (Sequential): 181.146 seconds
Number of threads running in parallel: 1
Parallel: The maximum possible flow is 929
Time taken (Parallel): 181.803 seconds

//generate_graph*********************************************************************
Enter the number of vertices: 10000
Enter the edge probability (in %): 10
Enter the maximum capacity for an edge: 20
Graph generated and saved to graph.txt
Time taken to generate the graph: 8730 milliseconds

Enter the filename: graph.txt
the value for s and t are 0 9999
Sequential: The maximum possible flow is 10551
Time taken (Sequential): 911.186 seconds
Number of threads running in parallel: 1
Parallel: The maximum possible flow is 10551
Time taken (Parallel): 910.894 seconds


Enter the filename: graph.txt
the value for s and t are 0 9999
^[[5~Sequential: The maximum possible flow is 10551
Time taken (Sequential): 908.481 seconds
Number of threads running in parallel: 2
Parallel: The maximum possible flow is 10551
Time taken (Parallel): 906.749 seconds

//using dincs algorithm 
Enter the filename: graph.txt
the value for s and t are 0 9999
Sequential: The maximum possible flow is 10551
Time taken (Sequential): 3.35546 seconds
Number of threads running in parallel: 2
Parallel: The maximum possible flow is 10551
Time taken (Parallel): 3.26619 seconds

