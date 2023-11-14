/* File:   Player.cpp
 * Author: Noel Perez
 * Created on October 29, 2023, 9:18 PM
 */

#include "Player.h"
#include "Board.h"
using namespace std;

//Player::Player(){
//    
//}

Player::Player(): board(){
   
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
 
 void::Player::display(char **board ){
     
       cout<<"\n";
    for(int j = 0 ; j < B_SIZE ; j++){ // Column numbers
        cout<<setw(5)<<j;
    }
    // Rows with letters
    for(int i = 0; i < B_SIZE; i++){
        cout<<"\n";
        cout << static_cast<char>('A' + i) <<"|";
        for(int j = 0; j < B_SIZE; j++){
        cout<<"[ "<<board[i][j]<<" ]";       
        }
    }
 }
 
 void::Player::placeShips(char **board, Ship s){
     
     cout<<name << "Place your ships "<<endl;
     
      for (int i = 0 ; i < 5 ; i++){
        int x, y;
        char direction;
        
        map<int, pair<int, char>> &itr = s.getShips();
        map<int, pair<string,char>> &itr2 =s.getShipNO();
         
        display(board);
      
        cout<<endl;
        cout << "\nPlacing " <<itr2[i].first<< " length "<<itr[i].first<<" ship.\n";
        
        cout << "\nEnter starting coordinates (e.g., A3): ";
        string coords;
        cin >> coords;

        x = coords[0] - 'A';
        cout<<"x is: "<<x<<endl;
        y = coords[1] - '0';
        cout<<"y is "<<y<<endl;
        cout << "Enter direction (H for horizontal, V for vertical): ";
        cin >> direction;

      if (Player::board.isValidPlacement(board,x,y,direction,itr[i].first) ){
   
        for(int j = 0 ; j < itr[i].first ; j++){
            if(direction == 'H' || direction == 'h'){
                board[x][y+j] = itr[i].second;
            }
            else if(direction == 'V' || direction == 'v'){
                board[x+j][y] = itr[i].second;
            }
        } // for loop 77
      }// if 75
    }// for loop 52
     
}
     
 