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
    Computer();
    Computer(const Computer& orig);
    virtual ~Computer();

    // Function   
    void makeRandOrientation(int l, list<char>& list);

    // Function
    queue<int> getRandCols();

    // Function 
    stack<char> getRandRows();

    void placeShips();
    
    void takeTurns(Player &opponent);

private:
     int randomChoice;
};

#endif /* COMPUTER_H */

