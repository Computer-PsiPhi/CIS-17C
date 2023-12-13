/*  File:   Game.cpp
 * Author: Noel Perez
 * Created on November 1, 2023, 6:35 PM
 */

#include "Game.h"
#include <algorithm>
#include <string>

// Default constructor with constructor delegation
Game::Game(): computer(), player() {}

// Destructor 
Game::~Game() {
}
// Function that causes a pause in console out so user can see output/game progress
void::Game::pause() {
    cout << endl << setw(7) << ' ' << "Press ENTER to continue: \n";
    cin.ignore();
    cin.get();
}

// Function that sets up the game: Gets players' names, places their ships and gets game ready
void::Game::setupGame() {
    string name; // var for name
    cin.ignore(100,'\n');
    cout << "\nEnter Player's Name : "; // Input from user: Name
    getline(cin,name);
    player.setName(name); // set player name 

    player.placeShips(); // Set the players ships 
    pause();
    computer.setName("Computer"); // Assign name to computer
    
    cout << "\nComputer is placing its ships" << endl;
    computer.placeShips();      // Place Computer's ships on board 
    
    cout << endl;
    
    cout << "\nGame is set up and ready to play!" << endl;
    // Pause and wait for user input to begin game
    cout << endl << setw(7) << ' ' << "Press ENTER to continue: \n"; 
    cin.get();
}
// Function that is used to play game and take player turns
// Creates two Player pointer object so they can swap turns
void::Game::playGame() {
    // Create a Player object pointer that is the user 
    Player* currentPlayer = &player; 
    // Create a Player object pointer that is the computer
    Player* opponent = &computer;
// Loop while a winner has not been declared by boolean function condition 
    while (true) {
        cout << "\n"; // Following is simply displaying both players' boards on the scrreen during game play
        for (int k = 0; k < 2; k++) { // Column numbers
            cout << setw(9);
            for (int col = 0; col < B_SIZE; col++) {
                cout << " " << setw(4) << col;
                if (col == 9)
                    cout << "\t";
            }
        }
        cout << "\n";
        for (int i = 0; i < B_SIZE; i++) {
            cout << "\t" << static_cast<char> ('A' + i) << "|";
            for (int j = 0; j < 10; j++) {
                cout << setw(1);
                cout << "[ " << player.getBoard()[i][j] << " ]"; // Display player's board 
            }
            cout << setw(5);
            cout << "\t" << static_cast<char> ('A' + i) << "|";
            for (int j = 0; j < B_SIZE; j++) {
                // Hide computer board with '~" so its ship coordinates are not shown to player
                // then update after player takes turn with correct symbol
                if (computer.getBoard()[i][j] != 'A' &&
                        computer.getBoard()[i][j] != 'B' &&
                        computer.getBoard()[i][j] != 'C' &&
                        computer.getBoard()[i][j] != 'D' &&
                        computer.getBoard()[i][j] != 'S') {
                    cout << "[ " << computer.getBoard()[i][j] << " ]";
                } else {
                    cout << "[ " << '~' << " ]";
                }
            }
            cout << "\n";
        }
        cout << setw(15) << player.getName() << "'s Board"; // User Board 
        cout << setw(61) << computer.getName() << "'s Board"; // Computer board
        cout << endl;
// Output whose turn it is
        cout << "\n" << currentPlayer->getName() << "'s Turn:\n";

     // Make the Player object take turns
        currentPlayer->takeTurns(*opponent);

     // Check to see if a winner can be declared based on if ships are on respective board  
        if (opponent->hasLost()) {
            cout << endl;
            pause();
            cout << "\n" << currentPlayer->getName() << " wins!\n";
            cout << "All of " << opponent->getName() << "'s ships are sunk!" << endl;
            break;
        }
// For output formatting and appropriate pause and wait for user to press ENTER
          if(currentPlayer->getName() == "Computer") {
           cout << endl << setw(7) << ' ' << "Press ENTER to continue:\n";
           cin.get();
       }else{
              pause();
       }
        // SWAP PLAYERS SO THEY CAN TAKE TURNS
        swap(currentPlayer, opponent);
    }
    /*DISPLAY BOTH BOARDS AFTER WINNER DECLARED
     * With correct formatting
     */
    cout << "\n";
    for (int k = 0; k < 2; k++) { // Column numbers
        cout << setw(9);
        for (int col = 0; col < B_SIZE; col++) {
            cout << " " << setw(4) << col;
            if (col == 9)
                cout << "\t";
        }
    }
    cout << "\n";
    for (int i = 0; i < B_SIZE; i++) {
        cout << "\t" << static_cast<char> ('A' + i) << "|";
        for (int j = 0; j < 10; j++) {
            cout << setw(1);
            cout << "[ " << player.getBoard()[i][j] << " ]"; // player 
        }
        cout << setw(5);

        cout << "\t" << static_cast<char> ('A' + i) << "|";
        for (int j = 0; j < B_SIZE; j++) {
            cout << "[ " << computer.getBoard()[i][j] << " ]";
        }
        cout << "\n";
    }
    cout << setw(15) << player.getName() << "'s Board"; //<<"User Board 
    cout << setw(61) << computer.getName() << "'s Board"; //<<"Computer board
    cout << endl;
    // Game is over, so display 2 boards one more time so user can see results and verify
    cout << "GAME OVER!" << endl; 
    cout << endl << setw(7) << ' ' << "Press ENTER TWICE to continue:\n"; // Prompts user with starting menu
    cin.get();
};