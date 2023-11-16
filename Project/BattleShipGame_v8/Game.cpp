/*  File:   Game.cpp
 * Author: Noel Perez
 * Created on November 1, 2023, 6:35 PM
 */

#include "Game.h"
#include <algorithm>
Game::Game() {
    Player();
    Computer();
    Board();
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

void::Game::displayBoards(){
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

 void::Game::setupGame(){
     
    
    
    string name;
    cout << "\nEnter Player's Name : ";
    cin >> name;
    player.setName(name);
    
   // cout << "\tplace your ships" << endl;
    player.placeShips();

    computer.setName("Komputer");
    
   //clear();
    
    cout << "\nComputer is placing its ships.\n";
     computer.placeShips();
    
  

    cout << "\nGame is set up and ready to play!\n";
    
   
     
 }
 void::Game::playGame(){
     
    Player* currentPlayer = &player;
    Player* opponent = &computer;
    
    char **playerBoard = Game::board.getGrid();
    
    char **compBoard = Game::board.getGrid();

    opponent->getBoard();
    while(true){
        
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
        player.getBoard();
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
                cout<<"[ "<<playerBoard[i][j]<<" ]"; // player 
            }
            cout<<setw(5);
           
            cout << "\t"<< static_cast<char>('A' + i) << "|" ;
    for(int j = 0 ; j < 10 ; j++){
                if(Game::board.getGrid()[i][j] != 'S') {
                    cout<<"[ "<<compBoard[i][j]<<" ]"; // compupter
                }
                else 
                    cout << '.' ;       
            }
            cout << "\n";
        }
    cout<<setw(15)<<player.getName()<<" Board";//<<"User Board ";
    cout<<setw(62)<<computer.getName()<<" Board";//<<"Computer board";
    cout<<"\n";
    
     cout << "\n" << currentPlayer->getName() << "'s Turn:\n";
        
        currentPlayer->takeTurns(*opponent);

        if (opponent->hasLost())
        {
            cout << "\n" << currentPlayer->getName() << " wins!\n";
            break;
        }

        
        swap(currentPlayer,opponent);
    }
   
 }