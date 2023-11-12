/* File:   Computer.h
 * Author: Noel Perez
 * Created on November 1, 2023, 6:34 PM
 */

#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"

class Computer: public Player {
public:
    Computer();
    Computer(const Computer& orig);
    virtual ~Computer();
private:

};

#endif /* COMPUTER_H */

