
/* 
 * File:   Coordinates.h
 * Author: Noel Perez
 *
 * Created on October 29, 2023, 9:16 PM
 */

#ifndef COORDINATES_H
#define COORDINATES_H

#include <set>
#include <utility>
#include <iterator>
#include <iostream>

using namespace std;

class Coordinates {
    
public:
    
    Coordinates();
    
    Coordinates(char row, int col);
    
    Coordinates(const Coordinates& orig);
    
    virtual ~Coordinates();
    
     void setRow(char r);

    // Getter function for col
    int getCol() const ;
    // Setter function for col
    void setCol(int c);

    // Member function to add a coordinate to the set
    void addCoordinate();
    
    // Member function to check if a set of coordinates exists in the set
    bool isInSet(const set<pair<char, int>>& coords);

    // Member function to get the coordinates in the set
    static set<pair<char, int>>& getAllCoords();
    
    // Member function to print the coordinates in the set
    static void printCoords();
    
    // Static member function to add coordinates to the set without creating an object
    static void addCoordsToSet(char row, int col);

    // Function to get user input for coordinates and add to the set
    static void getUserInput();
    
     // Static member function to get the first element in the set
    static pair<char, int> getFirstCoord() {
        
        if (!getAllCoords().empty()) {
            return *getAllCoords().begin();
        } else {
            // Return a default value or handle the case when the set is empty
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
            // Return a default value or case when there are fewer than two elements
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
 

private:

    char row;
    
    int col;
       
};

#endif /* COORDINATES_H */

