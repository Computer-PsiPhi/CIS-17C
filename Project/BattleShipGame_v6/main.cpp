/*  File:   main.cpp
 * Author: Noel Perez
 * Created on October 29, 2023, 9:13 PM
 */
#include <cstdlib>
#include <string>

#include "Board.h"
#include "Coordinates.h"
#include "Ship.h"
#include "Computer.h"
#include "Game.h"

using namespace std;

void clearScreen(){
cout << "\033c";
}

void clearScreenChoice(){
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

   
    Player p;
    
    Ship s;
    Board bo;
    
    Game g;
   
    
   char** playerGrid = bo.getGrid();
   
   int a=1;
   int b=2;
   char c='V';
   int d =3;
   
 
   cout<<boolalpha;
   // char Grid[][B_SIZE], int r, int c ,char o, int size
  cout<< bo.isValidPlacement(playerGrid , a, b, c, d);
  
  p.placeShips(playerGrid, s);
  
    return 0;
}

