/* File:   Coordinates.h
 * Author: Noel Perez
 * Created on October 29, 2023, 9:16 PM
 */
#ifndef COORDINATES_H
#define COORDINATES_H

#include <set>
#include <utility>
#include <iterator>
#include <iostream>
#include <iomanip>
using namespace std;

class Coordinates {
    
 private:
    char row;
    int col;
    
public:
    
    Coordinates();
    Coordinates(char row, int col);
    Coordinates(const Coordinates& orig);
    virtual ~Coordinates();
    
//Structure with comparison operator for comparing sets and user input
    struct CompareCoordinates {
        // bool operator function to compare pairs that make up sets
        bool operator()(const pair<char, int>& lhs, const pair<char, int>& rhs) const {
            return (lhs.first < rhs.first) || ((lhs.first == rhs.first) && (lhs.second < rhs.second));
        }
    };    

char getRow() const ;    
    
void setRow(char r);

// Getter function for col
int getCol() const ;
    
 // Setter function for col
void setCol(int c);
    
// Member function to print the coordinates in the set
static void printCoords();
    
// Static member function to add coordinates to the set 
static void addCoordsToSet(char row, int col);

// Function to get user input for coordinates and add to the set
static void getUserInput();
    
// Static function to check if user input is in set
static bool inputInSet(char userRow, int userCol);
   
// Static member function to get the first element in the set
static pair<char, int> getFirstCoord() {
        
        if (!getAllCoords().empty()) {
            return *getAllCoords().begin();
        } else {
            // Return a default value 
            return make_pair('\0', 0);
        }
    }

//Static member function to get the second element in the set
static pair<char, int> getSecondCoord() {
        
        if (getAllCoords().size() > 1) {
            set<pair<char, int>>::iterator it = getAllCoords().begin();
            ++it; // Move to the second element
            return *it;
        } else {
            // Return a default value 
            return make_pair('\0', 0);
        }
    }
 
// Static method to get all rows in set      
static set<char> getAllRows() {
      set<char> rows;
    
    for (set<pair<char, int>>::iterator it = getAllCoords().begin(); it != getAllCoords().end(); ++it) {
        rows.insert(it->first);
    }
    return rows;
}
 
//Static method to get all columns in set
static set<int> getAllColumns() {
    
    set<int> columns;
    
    for (set<pair<char, int>>::iterator it = getAllCoords().begin(); it != getAllCoords().end(); ++it) {
        
        columns.insert(it->second);
    }
    return columns;
} 
 // Static function named that returns a reference to the set of pairs.
static set<pair<char, int>, CompareCoordinates>& getAllCoords() {
       
        static set<pair<char, int>, CompareCoordinates> allCoordinates;
        
        return allCoordinates;
    }
 
};

#endif /* COORDINATES_H */

