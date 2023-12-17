/*
 * File:   HashTable.h
 * Author: Noel Perez
 * Created on December 7, 2023, 1:06 AM
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>

using namespace std;

class HashTable {
private:

    // struc for building hashtable class 
    struct Node {
        string key; // names of players as strings
        int value; // int value - players score
        Node* next; // pointer to next node

        // 2 Parameter constructor 
        Node(const string& key, int value) {
            this-> key = key;
            this->value = value;
            next = nullptr;
        }
    };

    int capacity; // capacity of hash table

    Node** table; // for key-value pairs 

    // Function for hashing 
    unsigned long int hashFunction(const string& key);


public:
    // 1 parameter constructor 
    HashTable(int capacity); 

// Function for inserting hashed name and value associated with that hash into hashtable
    void insert(const string& key, int value);

    int search(const string& key); // returns score of hashed name if it exists


    void printHT(); // prints index and key-value pairs stored in each indices if there are collisions


    ~HashTable(); // Destructor 

};

#endif /* HASHTABLE_H */

