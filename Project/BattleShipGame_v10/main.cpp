/*  File:   main.cpp
 * Author: Noel Perez
 * Created on October 29, 2023, 9:13 PM
 */
#include <cstdlib>
#include <string>
#include <deque>
#include <fstream>
#include <iterator>
#include "Board.h"
#include "Coordinates.h"
#include "Ship.h"
#include "Computer.h"
#include "Game.h"
#include "Player.h"

using namespace std;

void clearScreen(){
cout << "\033c";
}

void clearScreenChoice(){
    char choice = 0;
    cout<<"\n";
cout << "Do you want to clear screen(Y/N)?"<<endl;
cin>>choice;
choice = toupper(choice);

if (choice == 'Y')
{
cout << "\033c";
}

cout << endl;
}


int main(int argc, char** argv) {

    // File with game rules
    ifstream file("Rules.txt");
    
    // Test file open
    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }
    
    // Deque with Random access iterator to get file stream
    deque<char> text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    // Display the rules in stored in a .txt file 
    for (const char& words : text) {
      //  cout << words;
    }
    cout << '\n';

    clearScreenChoice();
    
    Game game;
    
    game.setupGame();
  
   //  clearScreen();
    game.playGame();
    
    
   

    return 0;
}

