/* File:   Player.cpp
 * Author: Noel Perez
 * Created on October 29, 2023, 9:18 PM
 */

#include "Player.h"

Player::Player() {
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

// Set player name
 void::Player::setName(string name){
     this->name=name;
 }
 string Player::getName(){
     return this->name;
 }
