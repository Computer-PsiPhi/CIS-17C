
/* 
 * File:   BinarySearchTree.h
 * Author: Noel Perez
 *
 * Created on December 6, 2023, 9:15 PM
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;



class Node {
public:
    int data;
    Node* left;
    Node* right;

    
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
    
    
public:
   
    BinarySearchTree(const BinarySearchTree& orig){};
    virtual ~BinarySearchTree(){};
    
     BinarySearchTree() {
         root=nullptr;
    }

    void printTree() {
        cout << "Tree structure:" << endl;
        printTree(root, 0);
    }

    void insert(int value) {
        root = insert(root, value);
    }

    int remove(int value) {
        if (search(value)) {
            root = deleteRec(root, value);
            return value;
        } else {
            // cout<<"Value not in tree";
            return 0;
        }
    }

    bool search(int value) {
        Node* current = root;
        while (current != nullptr) {
            if (value == current->data) {
                return true;
            } else if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }

    int getHeight() {
        return calcHeight(root);
    }

    bool isBalanced() {
        return isBalRec(root);
    }

    void inorder() {
        inOrderRec(root);
        cout << endl;
    }

    void preorder() {
        preOrderRec(root);
        cout << endl;
    }

    void postorder() {
        postOrderRec(root);
        cout << endl;
    }
    
        //Display the traversal of the depth 
    void displayDepth() {
        cout << "Depth traversal: ";
        printLevelOrder(root);
        cout << endl;
    }
    
    
       // Function to insert scores from a file into the BST
    void insertFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file." << std::endl;
            return;
        }

        int score;
        while (file >> score) {
            insert(score);
        }

        file.close();
    }
    
 
    
  int* getValuesFromRoot() const {
        int nodeCount = countNodes(root);
        int* values = new int[nodeCount]; // To store values

        int index = 0;
        Node* current = root;

        while (current != nullptr) {
            if (current->left == nullptr) {
                values[index++] = current->data;
                current = current->right;
            } else {
                Node* pre = current->left;
                while (pre->right != nullptr && pre->right != current) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = current;
                    current = current->left;
                } else {
                    pre->right = nullptr;
                    values[index++] = current->data;
                    current = current->right;
                }
            }
        }

        return values;
    }

private:
    
       Node* root;

    void printTree(Node* current, int space) {
        if (current == nullptr) {
            return;
        }

        space += 8;
        printTree(current->right, space);

        for (int i = 5; i < space; i++) {
            cout << " ";
        }

        if (current == root) {
            cout << endl;
            cout << "root->";
        }

        cout << current->data << "\n";

        printTree(current->left, space);
    }

    Node* insert(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insert(current->left, value);
        } else if (value > current->data) {
            current->right = insert(current->right, value);
        }

        return current;
    }

    Node* deleteRec(Node* current, int value) {
        if (current == nullptr) {
            return current;
        }

        if (value < current->data) {
            current->left = deleteRec(current->left, value);
        } else if (value > current->data) {
            current->right = deleteRec(current->right, value);
        } else {
            if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                return temp;
            }

            Node* successor = findMin(current->right);
            current->data = successor->data;
            current->right = deleteRec(current->right, successor->data);
        }
        return current;
    }

    int calcHeight(Node* node) {
        if (node == nullptr) {
            return -1;
        } else {
            int leftHeight = calcHeight(node->left);
            int rightHeight = calcHeight(node->right);

            return max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalRec(Node* node) {
        if (node == nullptr) {
            return true;
        }

        int leftHeight = calcHeight(node->left);
        int rightHeight = calcHeight(node->right);

        if (abs(leftHeight - rightHeight) <= 1 && isBalRec(node->left) && isBalRec(node->right)) {
            return true;
        }

        return false;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void inOrderRec(Node* current) {
        if (current != nullptr) {
            inOrderRec(current->left);
            cout << current->data << " ";
            inOrderRec(current->right);
        }
    }

    void preOrderRec(Node* current) {
        if (current != nullptr) {
            cout << current->data << " ";
            preOrderRec(current->left);
            preOrderRec(current->right);
        }
    }

    void postOrderRec(Node* current) {
        if (current != nullptr) {
            postOrderRec(current->left);
            postOrderRec(current->right);
            cout << current->data << " ";
        }
    }
    
     void printLevelOrder(Node* root) {
        int h = calcHeight(root);

        for (int i = 1; i <= h; i++)
            printCurrentLevel(root, i);
    }

    // Print nodes at current level
    void printCurrentLevel(Node* root, int level) {
        if (root == NULL)
            return;
        if (level == 1)
            cout << root->data << " ";
        else if (level > 1) {
            printCurrentLevel(root->left, level - 1);
            printCurrentLevel(root->right, level - 1);
        }
    }
    
    int countNodes(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return countNodes(node->left) + countNodes(node->right) + 1;
    }

};

#endif /* BINARYSEARCHTREE_H */



   