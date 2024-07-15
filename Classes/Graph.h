//
// Created by StefanoSIIacono on 15/07/2024.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <list>
#include <Thread>
#include "Vertex.h"

class Graph {
private:
    // Graph representation via adjacency list: more efficient than adjacency matrix since a lot o vertexes
    std::vector<list<Vertex>> adjList;
public:
    Graph();
    //TODO: member methods' definitions
    void printTree (int source) const; // print the tree starting from a source vertex
    Vertex search (int id) const; //search information about the vertex
};

#endif //GRAPH_H
