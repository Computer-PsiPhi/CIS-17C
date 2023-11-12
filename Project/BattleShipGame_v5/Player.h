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
    Player(const Player& orig);
    virtual ~Player();
    
    void setName(string name);
    string getName();
    
private:
    string name;
    Board board;
    
};

#endif /* PLAYER_H */

