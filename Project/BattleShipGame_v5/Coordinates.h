
/* 
 * File:   Coordinates.h
 * Author: Noel Perez
 *
 * Created on October 29, 2023, 9:16 PM
 */

#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates {
public:
    
    char row;
    int col; 
    
    Coordinates();
    Coordinates(const Coordinates& orig);
    virtual ~Coordinates();
private:

};

#endif /* COORDINATES_H */

