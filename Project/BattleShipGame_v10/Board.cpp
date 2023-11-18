/*  File:   Board.cpp
 * Author: Noel Perez
 * Created on October 29, 2023, 9:16 PM
 */
#include "Board.h"
// Default constructor
Board::Board() {
        Grid = new char*[B_SIZE]; // Dynamically create 2D array 
        for (int i = 0; i < B_SIZE; ++i) {
            Grid[i] = new char[B_SIZE];
            for (int j = 0; j < B_SIZE; ++j) {
                Grid[i][j] = '~';
            }
        }
}
// Destructor 
Board::~Board() {
    // Release dynamically allocated memory for 2d array board
        for (int i = 0; i < B_SIZE; ++i) {
            delete[] Grid[i];
        }
        delete[] Grid;
}

// Function that returns 2D pointer that is the Grid for the board
char**::Board::getGrid() {
        return Grid;
    }

// Function to display board 
void::Board::displayBoard(){
        cout<<"\n";
    for(int j = 0 ; j < B_SIZE ; j++){ // Column numbers
        cout<<setw(5)<<j;
    }
    // Rows with letters
    for(int i = 0; i < B_SIZE; i++){
        cout<<"\n";
        cout << static_cast<char>('A' + i) <<"|";
        for(int j = 0; j < B_SIZE; j++){
        cout<<"[ "<<Grid[i][j]<<" ]";       
        }
    }
}
// Function to determine of placement of ships is valid
// Checks to make sure no ships overlap or go over board edge
bool::Board::isValidPlacement( char **Grid, int r, int c ,char o, int size){
  // Check board to make sure there are no ships, if orientation is horizontal 
    if(o == 'H' || o == 'h'){   
        for(int i =c; i< c +size; i++){
            if(i >= B_SIZE || Grid[r][i] =='A'){
               return false;
            }
            if(i >= B_SIZE || Grid[r][i] =='B'){
               return false;
            }
            if(i >= B_SIZE || Grid[r][i] =='C'){
               return false;
            }
            if(i >= B_SIZE || Grid[r][i] =='D'){
               return false;
            }
            if(i >= B_SIZE || Grid[r][i] =='S'){
               return false;
            }
        }  
    }
    else{ // Check board to make sure there are no ships, if orientation is vertical
        for(int j = r; j<  r+size; j++){
            if(j >= B_SIZE || Grid[j][c] == 'A'){
               return false;
            }
            if(j >= B_SIZE || Grid[j][c] == 'B'){
               return false;
            }
            if(j >= B_SIZE || Grid[j][c] == 'C'){
               return false;
            }
            if(j >= B_SIZE || Grid[j][c] == 'D'){
               return false;
            }
            if(j >= B_SIZE || Grid[j][c] == 'S'){
               return false;
            }
        }
    }
    return true;
}
// Bool function to check if there is a ship at coordinate
bool::Board::isShipAtCoord(int key, char row, int col) const {
        return ship.isShipAtCoord(key, row, col);
}  

