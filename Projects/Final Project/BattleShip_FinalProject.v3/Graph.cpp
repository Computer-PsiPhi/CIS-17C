/* 
 * File:   Graph.cpp
 * Author: Noel Perez
 * Created on December 6, 2023, 7:45 PM
 */
#include "Graph.h"

NodeG*::Graph::findNode(const string& val) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (vertices[i] != nullptr && vertices[i]->data == val) {
            return vertices[i];
        }
    }
    return nullptr;
}

Graph::Graph() {
    for (int i = 0; i < MAX_SIZE; ++i) {
        vertices[i] = nullptr;
    }
}

void::Graph::addVertex(const string& v) {
    if (findNode(v) == nullptr) {
        for (int i = 0; i < MAX_SIZE; ++i) {
            if (vertices[i] == nullptr) {
                vertices[i] = new NodeG(v);
                break;
            }
        }
    }
}

void::Graph::addEdge(const string& v1, const string& v2, int weight) {
    NodeG* nodeV1 = findNode(v1);
    NodeG* nodeV2 = findNode(v2);

    if (nodeV1 && nodeV2) {
        int index1 = nodeV1->numEdges;
        int index2 = nodeV2->numEdges;

        nodeV1->edges[index1] = nodeV2;
        nodeV1->weights[index1] = weight;
        nodeV1->numEdges++;

        nodeV2->edges[index2] = nodeV1;
        nodeV2->weights[index2] = weight;
        nodeV2->numEdges++;
    } else {
        cout << "Vertices not found." << endl;
    }
}

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

Graph::~Graph() {
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (vertices[i] != nullptr) {
            delete vertices[i];
            vertices[i] = nullptr;
        }
    }
}