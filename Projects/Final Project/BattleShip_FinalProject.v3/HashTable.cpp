/*
 * File:   HashTable.cpp
 * Author: Noel Perez
 * Created on December 7, 2023, 1:06 AM
 */

#include "HashTable.h"

HashTable::HashTable(int capacity) {
    this->capacity = capacity;
    table = new Node*[capacity]();
}

unsigned long int::HashTable::hashFunction(const string& key) {
    unsigned long int hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % capacity;
}

void::HashTable::insert(const string& key, int value) {
    int index = hashFunction(key);
    Node* newNode = new Node(key, value);

    if (table[index] == nullptr) {
        table[index] = newNode;
    } else {
        Node* current = table[index];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int::HashTable::search(const string& key) {
    int index = hashFunction(key);
    Node* current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

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