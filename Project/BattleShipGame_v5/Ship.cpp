/* 
 * File:   Ship.cpp
 * Author: Noel Perez
 * Created on October 29, 2023, 9:17 PM
 */
#include "Ship.h"

//Aircraft Carrier (occupies 5 spaces), Battleship (4), Cruiser (3), Submarine (3), and Destroyer (2).  
Ship::Ship() {
  
    ships[0] = make_pair(2, 'D');
    ships[1] = make_pair(3, 'S');
    ships[2] = make_pair(3, 'C');
    ships[3] = make_pair(4, 'B');
    ships[4] = make_pair(5, 'A');    
      
    shipNO[0]=make_pair(names[0],'X');
    shipNO[1]=make_pair(names[1],'X');
    shipNO[2]=make_pair(names[2],'X');
    shipNO[3]=make_pair(names[3],'X');
    shipNO[4]=make_pair(names[4],'X');
}

Ship::Ship(const Ship& orig) {
}

Ship::~Ship() {
}

// Get ship names by index
string Ship::getShipName(int index){
      
     if (index >= 0 && index < 5) {
        return names[index];
    } else {
        return "Invalid!";
    }
  }

// Set user position 
void::Ship::setPostion(){
    
    Coordinates::getUserInput();
}

// Return map that holds ship length and symbol
map<int, pair<int, char>>&::Ship::getShips(){
        return ships;
 }

// Return map that holds ship name and orientation 
map<int, pair<string,char>>&::Ship::getShipNO(){
     return shipNO;
 }

 // Add orientation to ship by name 
void::Ship::addToMapNO(int k, char o){
     
     shipNO[k]=make_pair(names[k], o);
 }
 
 // Displays map with ship length and symbol 
 void::Ship::displayMap(map<int, pair<int, char>>& map){
     
     for(int i=0; i<5; i++){
        cout<< ships[i].first;
        cout<< ships[i].second<<endl;
     }
 } 
  
 // Displays map with ship name and orientation data
 void::Ship::displayMapNO(map<int, pair<string, char>>& map){
     
     for(int i=0; i<5; i++){
        cout<< shipNO[i].first<<" ";
        cout<< shipNO[i].second<<endl;
     }
 } 
 
 // Function to insert a set pair which are coordinates
void::Ship::insertCoord(int k , char row, int col, int s) {
        // Check if ship size exceeds the maximum 
        int Size = shipCoords[k].size();
        int Length = s - Size;

        // Add coordinates to the specified ship length
        for (int i = 0; i < Length; ++i) {
     
            shipCoords[k].insert(make_pair(row, col));
        }
 }

// Function returns map key 
 set<pair<char, int>>&::Ship::getCoordinates(int key) {
        return shipCoords[key];
    }

 // Function returns map with set of pairs with ships coordinates
 unordered_map<int, set<pair<char, int>>>&::Ship::getShipCoords() {
        return shipCoords;
    }
 
 // Displays all ships coordinates
 void::Ship::printShipCoords() {
 
        for (unordered_map<int, set<pair<char, int>>>::iterator iter = shipCoords.begin(); iter != shipCoords.end(); iter++) {
            
            cout << names[iter->first]<< " "<<iter->first << ": ";
          //  cout << getShipName(iter->first)<< " "<<iter->first << ": ";
            
            for (set<pair<char, int>>::iterator setIter = iter->second.begin(); setIter != iter->second.end(); setIter++) {
                
                cout << "(" << setIter->first << ", " << setIter->second << ") ";
            }
            cout << "\n";
        }
    }

