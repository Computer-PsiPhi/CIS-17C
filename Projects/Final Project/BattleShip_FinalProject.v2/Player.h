/* File:   Player.h
 * Author: Noel 
 * Created on October 29, 2023, 9:18 PM
 */
#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"

class Player {
public:
    Player(); // Default constructor 
    
    virtual ~Player(); // Destructor 

    // Set player name
    void setName(string name);
    // Get player name
    string getName();
    // Function to display board game when passing board as argument
    void display(char **board);
    // Overloaded Function that places user's ships
    void placeShips();
// Virtual Function that is overloaded, used for taking turns for the player/computer
    virtual void takeTurns(Player &opponent);

    // Bool function to determine if there are any ships left on the board
    bool hasLost();
    // Returns 2D array board
    char **getBoard() {
        return board.getGrid();
    }
    // Recursive function that searches through array indices instead of iterating with for loops
    void searchIndx(char**& board, int row, int col, char target);
    
    // Function that will show user Computer's ships coordinates if they need a hint
    void showHint();

protected:
    string name; // Player name
    Board board; // Player has a board, aggregated
    Ship ship;   // Player has ships, aggregated
};

#endif /* PLAYER_H */

