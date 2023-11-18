/*  File:   Game.cpp
 * Author: Noel Perez
 * Created on November 1, 2023, 6:35 PM
 */

#include "Game.h"
#include <algorithm>
#include <string>

Game::Game() {
    Player();
    Computer();
    Board();
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

void::Game::pause() {
    cout << endl << setw(7) << ' ' << "Press ENTER to continue: \n";
    cin.ignore();
    cin.get();
}

void::Game::setupGame() {
    string name;
    cin.ignore(100,'\n');
    cout << "\nEnter Player's Name : ";
    getline(cin,name);
    player.setName(name);

    player.placeShips();
    pause();
    computer.setName("Computer");
    
    cout << "\nComputer is placing its ships" << endl;
    computer.placeShips();
    
    cout << endl;
    int x = 1;
    cout << "\nGame is set up and ready to play!" << endl;

    cout << endl << setw(7) << ' ' << "Press ENTER to continue: \n";
    cin.get();
}

void::Game::playGame() {

    Player* currentPlayer = &player;
    Player* opponent = &computer;

    while (true) {
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
        cout << setw(15) << player.getName() << "'s Board"; //<<"User Board ";
        cout << setw(61) << computer.getName() << "'s Board"; //<<"Computer board";
        cout << endl;

        cout << "\n" << currentPlayer->getName() << "'s Turn:\n";

     
        currentPlayer->takeTurns(*opponent);

        
        if (opponent->hasLost()) {
            cout << endl;
            pause();
            cout << "\n" << currentPlayer->getName() << " wins!\n";
            cout << "All of " << opponent->getName() << "'s ships are sunk!" << endl;
            break;
        }
//     cout << endl << setw(7) << ' ' << "Press ENTER to continue:\n";
//     cin.get();
          if(currentPlayer->getName() == "Computer") {
           cout << endl << setw(7) << ' ' << "Press ENTER to continue:\n";
           cin.get();
       }else{
              pause();
       }
        // SWAP PLAYERS
        swap(currentPlayer, opponent);
    }
    /*
     * DISPLAY BOTH BOARDS AFTER WINNER DECLARED
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
    cout << "GAME OVER!" << endl;
    cout << endl << setw(7) << ' ' << "Press ENTER TWICE to continue:\n";
    cin.get();
};