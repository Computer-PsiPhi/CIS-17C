/* File:   Computer.h
 * Author: Noel Perez
 * Created on November 1, 2023, 6:34 PM
 */
#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include <list>
#include <cstdlib>
#include <forward_list>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>

class Computer : public Player {
public:
    Computer(); // Default constructor
    virtual ~Computer(); // Destructor

    // Function that generates random ship orientation for computer
    void makeRandOrientation(int l, list<char>& list);

    // Function that generates a random column choice for the computer and puts it in a queue 
    queue<int> getRandCols();

   // Function that generates a random row choice for the computer and puts it in a stack 
    stack<char> getRandRows();

    void placeShips(); // Function that places the computer's ships

    // Overloaded function for taking turn depending on player type
    void takeTurns(Player &opponent); 
    
    // Recursive function for traversing 2D array indices
    void searchIndx(char**& board, int row, int col, char target);

private:
    int randomChoice; // Computer simulation of random choice
};

#endif /* COMPUTER_H */

