/* 
 * File:   Graph.h
 * Author: Noel Perez
 * Created on December 6, 2023, 7:45 PM
 */

#ifndef GRAPH_H
#define GRAPH_H

// Weighted graph for players
#include <iostream>
#include <string>
#include<ctime>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 200;

class NodeG {
public:
    string data;
    NodeG* edges[MAX_SIZE]; // Maximum edges 
    int weights[MAX_SIZE]; // Corresponding weights for edges
    int numEdges;
    
// 1 parameter constructor 
    NodeG(string val) {
        data = val;
        numEdges = 0;
        for (int i = 0; i < MAX_SIZE; ++i) {
            edges[i] = nullptr;
            weights[i] = 0;
        }
    }
};

class Graph {
private:

    NodeG* vertices[MAX_SIZE]; // maximum vertices
    
    NodeG* findNode(const string& val); // find node helper function used in addVertex()

public:

    Graph();// default constructor 
    
    void addVertex(const string& v); // adds a vertex to graph
    
    // adds an edge to graph as long as vertices exist 
    void addEdge(const string& v1, const string& v2, int weight); 
    // display graph formatted 
    void display();
    ~Graph();

};

#endif /* GRAPH_H */

