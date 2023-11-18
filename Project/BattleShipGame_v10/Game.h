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
    Game();
    Game(const Game& orig);
    virtual ~Game();

    void displayBoards();
    void setupGame();
    void playGame();
    void pause(); 

private:
    Player player;
    Computer computer;
};

#endif /* GAME_H */

