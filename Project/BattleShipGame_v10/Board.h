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
    Board();
    Board(const Ship& orig);
    virtual ~Board();

    void displayBoard();

    bool isValidPlacement(char **Grid, int r, int c, char o, int size);

    bool isShipAtCoord(int key, char row, int col) const;

    char** getGrid();

private:
    char** Grid;
    Ship ship;
};

#endif /* BOARD_H */

