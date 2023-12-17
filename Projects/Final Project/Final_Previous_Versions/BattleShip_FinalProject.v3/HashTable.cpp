/*
 * File:   HashTable.cpp
 * Author: Noel Perez
 * Created on December 7, 2023, 1:06 AM
 */

#include "HashTable.h"

// 1 Parameter constructor 
HashTable::HashTable(int capacity) {
    this->capacity = capacity;
    table = new Node*[capacity]();
}

// DJB Hash Function 
unsigned long int::HashTable::hashFunction(const string& key) {
    unsigned long int hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % capacity;
}
// Function for inserting hashed name into hashtable : hashed name and score are stored 
void::HashTable::insert(const string& key, int value) {
    int index = hashFunction(key);
    Node* newNode = new Node(key, value);

    if (table[index] == nullptr) { // make sure empty
        table[index] = newNode;  // newNode has hash and its score
    } else {
        Node* current = table[index]; // when collisions occur
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}
// Search for the score of the key passed in 
int::HashTable::search(const string& key) {
    int index = hashFunction(key);
    Node* current = table[index]; // find the index of string key 

    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}
// Function for printing hashtable : Prints index, name and score
void::HashTable::printHT() {
    for (int i = 0; i < capacity; ++i) {
        Node* current = table[i];

        cout << "Index " << i << ": ";
        while (current != nullptr) {
            cout << "(" << current->key << ", " << current->value << ") ";
            current = current->next;
        }
        cout << endl;
    }
}
// Destructor for destroying hashtable 
HashTable::~HashTable() {
    for (int i = 0; i < capacity; ++i) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}