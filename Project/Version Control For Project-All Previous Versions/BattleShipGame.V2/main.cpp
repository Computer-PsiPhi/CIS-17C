/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: blott
 *
 * Created on August 21, 2023, 5:46 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

#include "Board.h"

/*
 * 
 */


void clearScreen(){
    char choice = 0;
    cout<<"\n";
cout << "Do you want to clear screen?"<<endl;
cin>>choice;
choice = toupper(choice);

if (choice == 'Y')
{
cout << "\033c";
}

cout << endl;
}

int main(int argc, char** argv) {
    
    Board brd;
    
     cout<<"\n";
    cout<< "Board "<<"\n";
    
    brd.drawBoard();
    
   
        
    clearScreen();
//    brd.drawBoard();

    return 0;
}

