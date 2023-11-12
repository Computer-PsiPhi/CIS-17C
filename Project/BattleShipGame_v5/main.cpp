/*  File:   main.cpp
 * Author: Noel Perez
 * Created on October 29, 2023, 9:13 PM
 */
#include <cstdlib>
#include <string>

#include "Board.h"
#include "Coordinates.h"
#include "Ship.h"


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
   
    Ship s;
    
   
    
    return 0;
}

