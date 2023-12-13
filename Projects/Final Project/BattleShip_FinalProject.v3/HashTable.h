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

    struct Node {
        string key;
        int value;
        Node* next;

        Node(const string& key, int value) {
            this-> key = key;
            this->value = value;
            next = nullptr;
        }
    };

    int capacity;

    Node** table;

    unsigned long int hashFunction(const string& key);


public:

    HashTable(int capacity);


    void insert(const string& key, int value);

    int search(const string& key);


    void printHT();


    ~HashTable();

};

#endif /* HASHTABLE_H */

