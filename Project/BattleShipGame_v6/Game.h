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

class Game {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    
    void displayBoards(){
        char Grid[B_SIZE][B_SIZE];
        char Grid2[B_SIZE][B_SIZE];

  // Initialize boards
    for(int i = 0; i< B_SIZE; i++){
        for(int j = 0; j < B_SIZE; j++){
            Grid[i][j] = '~';
            Grid2[i][j] = '^';
        }
    }

// Display 2 boards    
       
        cout << "\n";
    for(int k = 0 ; k < 2 ; k++){ // Column numbers
              cout<<setw(9);
               for(int col = 0 ; col < B_SIZE ; col++){
                cout<<" "<<setw(4)<<col;
                   if(col == 9)
                    cout<<"\t";
                }
            }
        cout << "\n";

//    for(int k = 0 ; k < 2 ; k++){
//            cout<<setw(4);
//            for(int j = 0 ; j < 10 ; j++){
//              cout<<setw(3); // moves row A
//            }
//        }
    for(int i = 0 ; i < 10 ; i++){
            cout << "\t" << static_cast<char>('A' + i) << "|" ;
            for(int j = 0 ; j < 10 ; j++){ 
                cout<<setw(1);
                cout<<"[ "<<Grid[i][j]<<" ]";
            }
            cout<<setw(5);
           
            cout << "\t"<< static_cast<char>('A' + i) << "|" ;
    for(int j = 0 ; j < 10 ; j++){
                if(Grid[i][j] != 'S') {
                    cout<<"[ "<<Grid2[i][j]<<" ]";
                }
                else 
                    cout << '.' ;       
            }
            cout << "\n";
        }
    cout<<setw(21)<<"User Board ";
    cout<<setw(68)<<"Computer board";
    cout<<"\n";
    }
    
private:
    
    Player player;
    Computer computer;
    Board board;
};

#endif /* GAME_H */

