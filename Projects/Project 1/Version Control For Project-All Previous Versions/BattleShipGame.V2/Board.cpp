
/* 
 * File:   Board.cpp
 * Author: 
 * Created on August 21, 2023, 5:46 PM
 */
#include <iostream>
#include "Board.h"

using namespace std; 

void Board:: drawBoard(){
   
   cout<<"\n";
//   cout << "\t";
//   
//    for(int j = 0 ; j < B_SIZE ; j++)
//    {
//        cout <<" "<< j << "  ";
//    }
//    cout <<"\n";  
//    cout << "\t";
//    cout<<"  ";
//    for(int j = 0 ; j < B_SIZE ; j++)
//    { 
//        cout << "---";
//        cout<<"|";
//    }
//        cout << "\n";
//
//    for(int i = 0 ; i < B_SIZE ; i++)
//    {   
//        cout << "\t" << static_cast<char>('A' + i) <<"|";
//        
//        for(int j = 0 ; j < B_SIZE ; j++)
//        {
//            cout << " " << Grid[i][j] << " " ;
//            cout<<"|";
//            
//        }
//           cout << "\n";
//    }
//  
   
       for(int j = 0 ; j < B_SIZE ; j++)
    {
         cout<<setw(5)<<j;
    }
    
    for(int i = 0; i < B_SIZE; i++){
        cout<<"\n";
        // cout<<"\t";
        cout << static_cast<char>('A' + i) <<"|";
        for(int j = 0; j < B_SIZE; j++){

            cout<<"[ "<<Grid[i][j]<<" ]";       
        }
    }
}

Board::Board() {
     for(int r=0; r<B_SIZE; r++){
        
        for(int c=0; c<B_SIZE; c++){
            Grid[r][c] = '-';
        }
    }
}

Board::Board(const Board& orig) {
}

Board::~Board() {
}

