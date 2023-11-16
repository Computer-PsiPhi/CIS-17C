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
   // Player(int rows, int cols) : board(rows, cols);
    
    //Player(const Player& orig);
    
    virtual ~Player();

    void setName(string name);
    
    string getName();

    void display(char **board );

   // void placeShips(char **board, Ship s); 
    
    void placeShips(); 
    
    virtual void takeTurns(Player &opponent);
    
    bool hasLost();
    
    char **getBoard(){
      return  board.getGrid();
    }
      
protected:
    string name;
    Board board;
    Ship ship;
   // char** Grid;
};

#endif /* PLAYER_H */

