/* 
 * File:   Board.cpp
 * Author: Noel Perez
 * Created on October 29, 2023, 9:16 PM
 */

#include "Board.h"

Board::Board() {
    for(int r=0; r<B_SIZE; r++){
        
        for(int c=0; c<B_SIZE; c++){
            Grid[r][c] = '~';
        }
    }
}

bool::Board::isValidPlacement( char Grid[][10], int r, int c ,char o, int size){
    
   // cout<<Grid[r][c];
//    cout<<"inFunc row "<<r<<endl;
//    cout<<"inFunc c "<<c<<endl;
//    cout<<"in Func orientation "<<o<<endl;
//    cout<<"in func size "<<size<<endl;

    
    if(o == 'H' || o == 'h'){
        for(int i =c; i< c +size; i++){
            if(i >= B_SIZE || Grid[r][i] =='S'){
                //cout<<"ship at :"<<Grid[r][i];
               return false;
            }
        }
            
    }
    else{
        for(int j = r; j<  r+size; j++){
            if(j >= B_SIZE || Grid[j][c] == 'S'){
                //cout<<"ship there too"<<endl;
               return false;
            }
        }
    }
   
    return true;
}

Board::Board(const Board& orig) {
}

Board::~Board() {
}

