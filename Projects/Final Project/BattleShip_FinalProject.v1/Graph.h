
/* 
 * File:   Graph.h
 * Author: Noel Perez
 *
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

class NodeG {
public:
    string data;
    NodeG* edges[100];  // Maximum of 100 edges per node
    int weights[100];  // Corresponding weights for edges
    int numEdges;

    NodeG(string val){
        data = val;
        numEdges =0; 
        for (int i = 0; i < 100; ++i) {
            edges[i] = nullptr;
            weights[i] = 0;
        }
    }
};

class Graph {
private:
    NodeG* vertices[100];  // Assuming a maximum of 100 vertices

    NodeG* findNode(const string& val) {
        for (int i = 0; i < 100; ++i) {
            if (vertices[i] != nullptr && vertices[i]->data == val) {
                return vertices[i];
            }
        }
        return nullptr;
    }

public:
    Graph() {
        for (int i = 0; i < 100; ++i) {
            vertices[i] = nullptr;
        }
    }

    void addVertex(const string& v) {
        if (findNode(v) == nullptr) {
            for (int i = 0; i < 100; ++i) {
                if (vertices[i] == nullptr) {
                    vertices[i] = new NodeG(v);
                    break;
                }
            }
        }
    }

    void addEdge(const string& v1, const string& v2, int weight) {
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
    
    void display() {
        cout << "Graph representation of player matches." << endl;
        cout << "Vertex vs Vertex : Weight is number of matches against each other\n" << endl;
        cout << setw(21) << "Player"<<setw(6)<<"vs"<<setw(12)<<"Player" << setw(13) << "Matches" << endl;
        cout << string(75, '-') << endl;
        for (int i = 0; i < 100; ++i) {
            if (vertices[i] != nullptr) {
                for (int j = 0; j < vertices[i]->numEdges; ++j) {
                    if (vertices[i]->weights[j] > 0) {
                        cout << setw(20) << vertices[i]->data <<setw(8)<< " vs ";
                        cout << setw(10) << vertices[i]->edges[j]->data << " : ";
                        cout << setw(5) << vertices[i]->weights[j] << endl;
                    }
                }
            }
        }
    }

~Graph() {
        for (int i = 0; i < 100; ++i) {
            if (vertices[i] != nullptr) {
                delete vertices[i];
                vertices[i] = nullptr;
            }
        }
    }
};


#endif /* GRAPH_H */

