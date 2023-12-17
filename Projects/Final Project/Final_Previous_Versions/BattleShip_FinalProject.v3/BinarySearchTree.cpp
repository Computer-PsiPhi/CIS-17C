/* 
 * File:   BinarySearchTree.cpp
 * Author: Noel Perez
 * Created on December 6, 2023, 9:15 PM
 */
#include "BinarySearchTree.h"

// Destructor 
BinarySearchTree::~BinarySearchTree() {
};

// Default constructor 
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}
//  Helper function to print tree 
void::BinarySearchTree::displayTree() {
    cout << "Tree structure:" << endl;
    printTree(root, 0); // call print tree function 
}
// Overloaded helper function to insert into tree
void::BinarySearchTree::insert(int value) {
    root = insert(root, value); 
}
// Helper function to remove element from tree
void::BinarySearchTree::remove(int value) {
    if (search(value)) {
        root = deleteRec(root, value); // call rec function to delete

    } else {
        cout << "Value not in tree";

    }
}

// Function for searching if element is in tree: bool 
bool::BinarySearchTree::search(int value) {
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

// Helper function for getting tree height 
int::BinarySearchTree::getHeight() {
    return calcHeight(root); // call private function 
}

// Helper function for checking if tree is balanced 
bool::BinarySearchTree::isBalanced() {
    return isBalRec(root);
}

// Helper function for in-order display 
void::BinarySearchTree::inorder() {
    cout << "In-Order traversal: ";
    inOrderRec(root);
    cout << endl;
}

// Helper function for in-order display  
void::BinarySearchTree::preorder() {
    cout << "Pre-Order traversal: ";
    preOrderRec(root);
    cout << endl;
}

// Helper function for post-order display 
void::BinarySearchTree::postorder() {
    cout << "Post-Order traversal: ";
    postOrderRec(root);
    cout << endl;
}

// Helper function used for depth order display 
void::BinarySearchTree::displayDepth() {
    cout << endl;
    cout << "\nDepth traversal: ";
    getLevel(root); // get the level of each 
    cout << endl;
}

// Function to insert scores from a file into the BST
void::BinarySearchTree::loadFromFile(const string& filename) {
    
    ifstream file(filename); // create file stream for insertion of values  
    if (!file.is_open()) { // make sure file stream is good to go 
        cerr << "Error opening file." << endl;
        return;
    }

    int score; // Variable used to read in data from file
    while (file >> score) {
        insert(score); // call function to insert data into Binary Search Tree 
    }

    file.close();  // Close file when done. 
}
// Function that returns the values that are stored in the BST so they can be used in program 
int*::BinarySearchTree::getValuesFromRoot() {

    int nodeCount = countNodes(root); // to get size of how many nodes in tree

    int* values = new int[nodeCount]; // To store values

    int index = 0;
    Node* current = root; // to start at root 
    
// Go thru tree and subtrees to get values so they can be returned
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

// Recursive function for printing tree roots and nodes in console for visual purposes 
void::BinarySearchTree::printTree(Node* current, int space) {
    if (current == nullptr) {
        return;
    }

    space += 9; // spaces for displaying tree visually 

    // Print right subtree
    printTree(current->right, space);


    for (int i = 5; i < space; i++) { // formatting 
        cout << " ";
    }
    if (current == root) {
        cout<<endl;
        cout << "root->";
    }
    cout << current->data << "\n"; // root 

    // Print left subtree
    printTree(current->left, space);
}
// Recursive function for inserting element into tree
Node*::BinarySearchTree::insert(Node* current, int value) {
    if (current == nullptr) {
        return new Node(value); // add new node 
    }
// left case
    if (value < current->data) {
        current->left = insert(current->left, value);
    } else if (value > current->data) { // right case 
        current->right = insert(current->right, value);
    }

    return current;
}
// Recursive function for deleting elements from tree 
Node*::BinarySearchTree::deleteRec(Node* current, int value) {
    if (current == nullptr) {
        return current;
    }
// left case 
    if (value < current->data) {
        current->left = deleteRec(current->left, value);
    } else if (value > current->data) { // right case 
        current->right = deleteRec(current->right, value);
    } else {
        if (current->left == nullptr) { // left node is empty go right 
            Node* temp = current->right;
            delete current;
            return temp;
        } else if (current->right == nullptr) { // right node is empty go left 
            Node* temp = current->left;
            delete current;
            return temp;
        }

        Node* _next = findMin(current->right); // check to see if there are lesser elements
        current->data = _next->data; 
        current->right = deleteRec(current->right, _next->data);
    }
    return current;
}
// Recursive function for calculating height of tree 
int::BinarySearchTree::calcHeight(Node* node) {
    if (node == nullptr) {
        return -1;
    } else {
        int leftHeight = calcHeight(node->left); // go down left side
        int rightHeight = calcHeight(node->right); // go down right side

        return max(leftHeight, rightHeight) +1; 
    }
}
// Recursive function for determining if tree is balanced based on heights of subtrees 
bool::BinarySearchTree::isBalRec(Node* node) {
    if (node == nullptr) {
        return true;
    }

    int leftHeight = calcHeight(node->left); // get height of left side 
    int rightHeight = calcHeight(node->right); // get height of right side

    if (abs(leftHeight - rightHeight) <= 1 && isBalRec(node->left) && isBalRec(node->right)) {
        return true;
    }

    return false;
}
// Function for finding minimum element in tree
Node*::BinarySearchTree::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}
// Recursive display in order function : left root right 
void::BinarySearchTree::inOrderRec(Node* current) {
    if (current != nullptr) {
        inOrderRec(current->left);
        cout << current->data << " ";
        inOrderRec(current->right);
    }
}
// Recursive display pre-order function : root left right 
void::BinarySearchTree::preOrderRec(Node* current) {
    if (current != nullptr) {
        cout << current->data << " ";
        preOrderRec(current->left);
        preOrderRec(current->right);
    }
}
// Recursive display post-order function : left right root
void::BinarySearchTree::postOrderRec(Node* current) {
    if (current != nullptr) {
        postOrderRec(current->left);
        postOrderRec(current->right);
        cout << current->data << " ";
    }
}
// Helper function for calculating level from root
void::BinarySearchTree::getLevel(Node* root) {
    int h = calcHeight(root); // get correct height
    for (int i = 1; i <= h; i++)
        currentLevel(root, i);
}

// Recursive function to print nodes at each level which is used for depth traversal 
void::BinarySearchTree::currentLevel(Node* root, int level) {
    if (root == nullptr)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        currentLevel(root->left, level - 1);
        currentLevel(root->right, level - 1);
    }
}
// Recursive function - helper function that determines number of nodes so correct number/size can be returned
// when getting values from BST in return-values-from-root function 
int::BinarySearchTree::countNodes(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return countNodes(node->left) + countNodes(node->right) + 1;
}