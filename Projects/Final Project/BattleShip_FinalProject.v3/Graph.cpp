/* 
 * File:   Graph.cpp
 * Author: Noel Perez
 * Created on December 6, 2023, 7:45 PM
 */
#include "Graph.h"

// Default constructor 
Graph::Graph() {
    for (int i = 0; i < MAX_SIZE; ++i) {
        vertices[i] = nullptr;
    }
}

// Function for finding the node where element passed is in the graph
NodeG*::Graph::findNode(const string& val) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (vertices[i] != nullptr && vertices[i]->data == val) {
            return vertices[i];
        }
    }
    return nullptr; // when not found 
}

// Function for adding vertex to graph 
void::Graph::addVertex(const string& v) {
    if (findNode(v) == nullptr) { // make sure empty, before we add it 
        for (int i = 0; i < MAX_SIZE; ++i) {
            if (vertices[i] == nullptr) {
                vertices[i] = new NodeG(v);
                break;
            }
        }
    }
}
// Function for adding an edge between two vertices: takes in the two vertices
// and the corresponding weight between them
void::Graph::addEdge(const string& v1, const string& v2, int weight) {
    // Need to make sure both vertices exist before we can add an edge between them
    NodeG* nodeV1 = findNode(v1);
    NodeG* nodeV2 = findNode(v2);

    if (nodeV1 && nodeV2) { // if vertices exist make an edge 
        int index1 = nodeV1->numEdges;
        int index2 = nodeV2->numEdges;

        nodeV1->edges[index1] = nodeV2;
        nodeV1->weights[index1] = weight;
        nodeV1->numEdges++;

        nodeV2->edges[index2] = nodeV1;
        nodeV2->weights[index2] = weight;
        nodeV2->numEdges++;
    } else { // if they dont exist
        cout << "Vertices not found." << endl; 
    }
}

/*
 * This graph represents a network of simulated matches between player through out the 
 * history of the game: Each vertex is a player and the weight is the number of matches 
 * they have had. It is an undirected weighted graph so the weights are the same both ways.
 * 
 * This is the display function for the graph with formatting 
 */
void::Graph::display() {
    cout << "\n\nGraph representation of player matches." << endl;
    cout << "Vertex vs Vertex : Weight is number of matches against each other\n" << endl;
    cout << setw(21) << "Player" << setw(6) << "vs" << setw(12) << "Player" << setw(12) << "Matches" << endl;
    cout << string(75, '-') << endl;
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (vertices[i] != nullptr) {
            for (int j = 0; j < vertices[i]->numEdges; ++j) {
                if (vertices[i]->weights[j] > 0) {
                    cout << setw(20) << vertices[i]->data << setw(8) << " vs ";
                    cout << setw(10) << vertices[i]->edges[j]->data << " : ";
                    cout << setw(7) << vertices[i]->weights[j] << endl;
                }
            }
        }
    }
}
// Destructor 
Graph::~Graph() {
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (vertices[i] != nullptr) {
            delete vertices[i];
            vertices[i] = nullptr;
        }
    }
}