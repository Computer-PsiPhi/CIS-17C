/* 
 * File:   main.cpp
 * Author: Noel Perez
 * Created on October 29, 2023, 9:13 PM
 */

#include <cstdlib>

#include "Board.h"
#include "Coordinates.h"

using namespace std;


int main(int argc, char** argv) {
   
       // Create a Coordinate object
    Coordinates myCoordinate;
    myCoordinate.addCoordsToSet('A',9);
    myCoordinate.addCoordsToSet('J',5); 
     

    return 0;
}

