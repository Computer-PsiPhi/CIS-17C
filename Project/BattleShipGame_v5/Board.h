/* 
 * File:   Board.h
 * Author: Noel Perez
 * Created on October 29, 2023, 9:16 PM
 */

#include "Coordinates.h"
#include "Ship.h"

#ifndef BOARD_H
#define BOARD_H

const int B_SIZE=10;

class Board {
public:
    
    Board();
    Board(const Board& orig);
    virtual ~Board();
    
    char Grid[B_SIZE][B_SIZE];
    
    bool isValidPlacement( char Grid[][B_SIZE], int r, int c ,char o, int size);
    
    bool isShipAtCoord(int key, char row, int col) const;
    
private:

    Ship ship;
    
};

#endif /* BOARD_H */

