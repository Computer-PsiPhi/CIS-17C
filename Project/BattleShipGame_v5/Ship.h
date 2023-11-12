/* 
 * File:   Ship.h
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
    
   Ship();
   // Ship(Coordinates& position);
    
   Ship(const Ship& orig);
   
   virtual ~Ship();
 
// add ship position to coordinates class    
 void setPostion();
 
 // Get ships' names
 string getShipName(int index);
    
 // Map for ship <int ship lenght, character symbol>
 map<int, pair<int, char>> &getShips();
 
 // Map for ship name and orientation
 map<int, pair<string,char>> &getShipNO();
     
 // Add elements to unordered_map 
 void addToUnMap(int k, char r, int c);    
 
 void addToMapNO(int k, char o);

 // for ship <size,symbol>
 void displayMap(map<int, pair<int, char>>& map);
 
// for ship<char row, int col>
 void displayUnMap(unordered_map<int, pair<char, int>>& map);
 
 // Display ship name and orientation <string name, char orientation>
 void displayMapNO(map<int, pair<string, char>>& map);
 
 // Function 
void insertCoord(int k , char row, int col, int s);
 
 // Function 
 set<pair<char, int>>& getCoordinates(int key);
 
 // Function
 unordered_map<int, set<pair<char, int>>>& getShipCoords();
 
 // Function 
 void printShipCoords();
 
private:
    
  unordered_map<int,set<pair<char, int>> > shipCoords;
    
  // Map for ship length and symbol
   map<int, pair<int, char>> ships;
   
   // Map for ship name and orientation
   map<int, pair<string,char>> shipNO;
   
   //Aircraft Carrier (occupies 5 spaces), Battleship (4), Cruiser (3), Submarine (3), and Destroyer (2).   
    string names[5]={"Destroyer", "Submarine", "Cruiser", "Battleship", "Aircraft Carrier"};
    
};

#endif /* SHIP_H */

