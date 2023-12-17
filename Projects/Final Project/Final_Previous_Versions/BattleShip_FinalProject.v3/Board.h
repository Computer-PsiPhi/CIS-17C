/*File:   Board.h
 * Author: Noel Perez
 * Created on October 29, 2023, 9:16 PM
 */
#include "Coordinates.h"
#include "Ship.h"

#ifndef BOARD_H
#define BOARD_H

const int B_SIZE = 10;

class Board {
public:
    Board();    // Default constructor
    Board(const Ship& orig); // Copy constructor 
    virtual ~Board(); // Destructor 

    void displayBoard(); // Function for displaying board
    
    // Check if ship length and orientation is OK to place on board  
    bool isValidPlacement(char **Grid, int r, int c, char o, int size);
    // Function that lets you check if there is a ship at coordinate 
    bool isShipAtCoord(int key, char row, int col) const;
    // Return the dynamically allocated 2d array that is the board
    char** getGrid();

private:
    char** Grid; // Member variable for 2d array that is used to make board
    Ship ship;  // Board has ships
};

#endif /* BOARD_H */

