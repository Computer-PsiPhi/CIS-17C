/* 
 * File:   Coordinates.cpp
 * Author: Noel Perez
 * Created on October 29, 2023, 9:16 PM
 */

#include "Coordinates.h"


Coordinates::Coordinates() {
}

// Two-parameter constructor 
Coordinates::Coordinates(char row, int col) {
       
        this->row=row;
        this->col=col;
        getAllCoords().insert(make_pair(row, col));
    }

Coordinates::Coordinates(const Coordinates& orig) {
}

Coordinates::~Coordinates() {
}

 void::Coordinates::setRow(char r) {
        row = r;
    }

    // Getter function for col
int::Coordinates::getCol() const {
        return col;
    }

    // Setter function for col
    void::Coordinates::setCol(int c) {
        col = c;
    }

    // Member function to add a coordinate to the set
    void::Coordinates::addCoordinate() {
        getAllCoords().insert(make_pair(row, col));
    }

    // Member function to check if a set of coordinates exists in the set
    bool::Coordinates::isInSet(const set<pair<char, int>>& coords) {
        return getAllCoords() == coords;
    }

    // Member function to get the coordinates in the set
   set<pair<char, int>>&::Coordinates::getAllCoords() {
       
        static set<pair<char, int>> allCoords;
        return allCoords;
    }

    // Member function to print the coordinates in the set
     void::Coordinates::printCoords() {
         
        for (set<std::pair<char, int>>::iterator it = getAllCoords().begin(); it != getAllCoords().end(); ++it) {
            cout << "(" << it->first << ", " << it->second << ") ";
        }
        cout << "\n";
    }

    // Static member function to add coordinates to the set without creating an object
     void::Coordinates::addCoordsToSet(char row, int col) {
        getAllCoords().insert(make_pair(row, col));
    }

    // Function to get user input for coordinates and add to the set
     void::Coordinates::getUserInput() {
        char userRow;
        int userCol;

        cout << "Enter row (A-Z): ";
        cin >> userRow;

        cout << "Enter column (1-9): ";
        cin >> userCol;

        // Add the entered coordinates to the set
        addCoordsToSet(userRow, userCol);
    }
    
     