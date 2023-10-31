
/* 
 * File:   Board.cpp
 * Author: Noel Perez
 * 
 * Created on October 29, 2023, 9:16 PM
 */

#include "Board.h"

Board::Board() {
    for(int r=0; r<B_SIZE; r++){
        
        for(int c=0; c<B_SIZE; c++){
            Grid[r][c] = '~';
        }
    }
}

Board::Board(const Board& orig) {
}

Board::~Board() {
}

