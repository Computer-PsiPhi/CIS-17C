/*  File:   Coordinates.cpp
 * Author: Noel Perez
 * Created on October 29, 2023, 9:16 PM
 */
#include "Coordinates.h"

// Coordinates Class 
Coordinates::Coordinates() {
}
// Two-parameter constructor 
Coordinates::Coordinates(char row, int col) {
    this->row = row;
    this->col = col;
    getAllCoords().insert(make_pair(row, col));
}

// Destructor
Coordinates::~Coordinates() {
}
// Get row
char::Coordinates::getRow() const {
    return row;
}
// Set Row
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
// Member function to print the coordinates in the set
void::Coordinates::printCoords() {
    for (set<pair<char, int>>::iterator it = getAllCoords().begin(); it != getAllCoords().end(); ++it) {
        cout << "(" << it->first << ", " << it->second << ") ";
    }
    cout << "\n";
}
// Static member function to add coordinates to the set
void::Coordinates::addCoordsToSet(char row, int col) {
    getAllCoords().insert(make_pair(row, col));
}
// Function to get user input for coordinates and add to the set
void::Coordinates::getUserInput() {
    char userRow; // variables for user input
    int userCol;
    cout << "Enter row (A-Z): ";
    cin >> userRow;
    cout << "Enter column (1-9): ";
    cin >> userCol;

    // Add the entered coordinates to the set
    addCoordsToSet(userRow, userCol);
}
// Static  bool function to check if user input is in set
bool::Coordinates::inputInSet(char userRow, int userCol) {
    return getAllCoords().find(std::make_pair(userRow, userCol)) != getAllCoords().end();
}

