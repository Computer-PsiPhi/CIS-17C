

/* 
 * File:   Board.h
 * Author: blott
 *
 * Created on October 29, 2023, 9:16 PM
 */

#include "Coordinates.h"

#ifndef BOARD_H
#define BOARD_H

const int B_SIZE=10;

class Board {
public:
    
    Coordinates coord; 
    char Grid[B_SIZE][B_SIZE];
    
    bool isValidPosition();
    
    Board();
    Board(const Board& orig);
    virtual ~Board();
private:

};

#endif /* BOARD_H */

