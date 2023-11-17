/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Board.h
 * Author: blott
 *
 * Created on August 21, 2023, 5:46 PM
 */

#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const int B_SIZE = 10;

class Board {
public:
    char Grid[B_SIZE][B_SIZE];
    
    void drawBoard();
    void clearBoard();
    Board();
    Board(const Board& orig);
    virtual ~Board();
private:

};

#endif /* BOARD_H */

