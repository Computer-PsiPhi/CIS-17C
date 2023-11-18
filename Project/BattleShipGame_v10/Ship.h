/* File:   Ship.h
 * Author: Noel Perez
 * Created on October 29, 2023, 9:17 PM
 */
#include "Coordinates.h"

#ifndef SHIP_H
#define SHIP_H

#include <map>
#include <unordered_map>
#include <string>

class Ship {
public:

    Ship(); // Defualt constructor 
    Ship(const Coordinates& orig); // Copy constructor passing in Coordiinates object 

    virtual ~Ship(); // Destructor 

    int Hits(); // Function that returns ship's hits

    // Add ship position to coordinates class    
    void setPostion();

    // Get ship length
    int getShipLenght(int k);

    // Get ships' names
    string getShipName(int index);

    // Map for ship <int ship lenght, character symbol>
    map<int, pair<int, char>> &getShips();

    // Map for ship name and orientation
    map<int, pair<string, char>> &getShipNO();

    // Add elements to unordered_map 
    void addToUnMap(int k, char r, int c);
    
    // Function to add orientation to map that holds ships
    void addToMapNO(int k, char o);

    // Function for displaying ship <size,symbol>
    void displayMap(map<int, pair<int, char>>&map);

    // Function for displaying ship<char row, int col>
    void displayUnMap(unordered_map<int, pair<char, int>>&map);

    // Display ship name and orientation <string name, char orientation>
    void displayMapNO(map<int, pair<string, char>>&map);

    // Function to insert coordinates to each map value which is a ship
    void insertCoord(int k, char row, int col, int s);
    // Bool function that checks if there is a ship at the key value passed in with coordinates
    bool isShipAtCoord(int key, char row, int col) const;

    // Function returns coordinates based on map key passed in
    set<pair<char, int>>&getCoordinates(int key);

    // Function that returns the 2D map with the map of ships' coordinates
    unordered_map<int, set<pair<char, int>>>& getShipCoords();

    // Function to print all coordinates stored in 2D map 
    void printShipCoords();

private:

    // 2D MAP for ship type and coordinates
    unordered_map<int, set<pair<char, int>> > shipCoords;

    // 2D Map for ship length and symbol
    map<int, pair<int, char>> ships;

    // 2D Map for ship name and orientation
    map<int, pair<string, char>> shipNO;

    //Aircraft Carrier (occupies 5 spaces), Battleship (4), Cruiser (3), Submarine (3), and Destroyer (2).   
    string names[5] = {"Destroyer", "Submarine", "Cruiser", "Battleship", "Aircraft Carrier"};

    int hits; // hits of each ship
};

#endif /* SHIP_H */

