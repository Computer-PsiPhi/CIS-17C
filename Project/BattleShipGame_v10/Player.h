/* File:   Player.h
 * Author: Noel 
 * Created on October 29, 2023, 9:18 PM
 */
#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"

class Player {
public:
    Player();
    
    virtual ~Player();

    void setName(string name);

    string getName();

    void display(char **board);

    void placeShips();

    virtual void takeTurns(Player &opponent);

    bool hasLost();

    char **getBoard() {
        return board.getGrid();
    }
    
    void searchIndx(char**& board, int row, int col, char target);
    
    void showHint();

protected:
    string name;
    Board board;
    Ship ship;
};

#endif /* PLAYER_H */

