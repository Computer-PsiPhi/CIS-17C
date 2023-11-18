/*  File:   Game.h
 * Author: Noel Perez
 * Created on November 1, 2023, 6:35 PM
 */
#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "Computer.h"
#include "Coordinates.h"
#include "Ship.h"
#include <iostream>
#include <cstdio>
class Game {
public:
    Game(); // Default constructor 
    
    virtual ~Game(); // destructor 

    // Function that sets up game with player's ships
    void setupGame();
    // Function that is used to play game 
    void playGame();
    // Function used to pause console output
    void pause(); 

private:
    Player player; // Player object aggregation 
    Computer computer; // Computer object aggregation
};

#endif /* GAME_H */

