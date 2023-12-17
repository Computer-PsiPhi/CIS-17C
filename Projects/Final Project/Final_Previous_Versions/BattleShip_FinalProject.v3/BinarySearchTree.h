/* 
 * File:   BinarySearchTree.h
 * Author: Noel Perez
 * Created on December 6, 2023, 9:15 PM
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

// Node class used in BST class 
class Node {
public:
    int data; // data used in BST 
    Node* left;
    Node* right;

    // Constructor for Node 
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// BST Class - uses Node class above 
class BinarySearchTree {
public:

    BinarySearchTree(); // Constructor 

    virtual ~BinarySearchTree(); // Destructor 

    void displayTree(); // Helper function for displaying the tree visually 

    void insert(int value); // Helper function for inserting element into tree 

    void remove(int value); // Helper function for removing an element 

    bool search(int value); // bool function for checking if element is in tree 

    int getHeight(); // Helper function for height 

    bool isBalanced(); // Helper function used with getHeight 

    void inorder(); // Helper function used with for in order traversal
 
    void preorder(); // Helper function used with pre order traversal 

    void postorder(); // Helper function used with post order traversal 

    void displayDepth(); // Helper function for depthwise traversal 

    // Function to insert scores from a file into the BST
    void loadFromFile(const string& filename);

    int* getValuesFromRoot(); // Returns the elements in the tree 

private:

    Node* root; // root of tree

    void printTree(Node* current, int space); // Prints tree visually called by helper function 

    Node* insert(Node* current, int value); // Insert into tree called by helper function 

    Node* deleteRec(Node* current, int value); // Delete from tree called by helper function 

    int calcHeight(Node* node); // Determine height of tree called by helper function 

    bool isBalRec(Node* node); // Recursive function checks if tree is balanced 

    Node* findMin(Node* node); // Find minimum element 

    void inOrderRec(Node* current); // Recursive print in order function 

    void preOrderRec(Node* current); // Recursive print pre order function 

    void postOrderRec(Node* current); // Recursive print post order function 

    void getLevel(Node* root); // Function for helping get the level to display depth traversal 

    void currentLevel(Node* root, int level); // helper function for depth traversal

    int countNodes(Node* node) const; // Function correctly determines size of what is in the tree

};

#endif /* BINARYSEARCHTREE_H */



