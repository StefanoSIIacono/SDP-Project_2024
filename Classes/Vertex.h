//
// Created by admin on 15/07/2024.
//

#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

class Vertex {
    private:
        // Vertexes values hypothesis (it must have a sort of id)
        // Distance should be evaluated at runtime when the source is selected
        int id;
        string name;
        string color;
        int capacity;
    public:
        Vertex (int id, string name, string color, int capacity = -1):
        id {id},
        name {name},
        color {color}
        {} // constructor

        Vertex (int id, string name, string color, int capacity):
            id {id},
            name {name},
            color {color},
            capacity {capacity}
            {} // constructor

        void printVertex () const{};
};


#endif //VERTEX_H
