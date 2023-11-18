/*  File:   main.cpp
 * Author: Noel Perez
 * Created on October 20, 2023, 9:13 PM
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

// Function to clear screen
void clearScreen() {
    cout << "\033c";
}

// Function to clear screen with user input for choice
void clearScreenChoice() {
    char choice = 0;
    cout << "\n";
    cout << "Do you want to clear screen(Y/N)?" << endl;
    cin>>choice;
    choice = toupper(choice);

    if (choice == 'Y') {
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

    int choice = 0; // Variable used for user input

    // Display menu
    while (choice != 3) {
        cout<<endl;
        cout << "Menu:" << endl;
        cout << "1. Display Rules" << endl;
        cout << "2. Play Game" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Input validation for menu options
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(100, '\n');
         // Choice 1 from menu   
        } else if (choice == 1) {
            // Display the rules in stored in a .txt file 
            cout << endl;
            for (const char& words : text) {
                cout << words;
            }
            cout << '\n';
            clearScreenChoice(); // clear screen
         // Choice 2 from menu
        } else if (choice == 2) {
            Coordinates c; // Declare Coordinates object that resets each game
            // Declare Game object so that it resets if user chooses to play multiple games
            Game game;    
            game.setupGame(); // Setup game with both player's boards
            game.playGame(); // Start game 
            c.getAllCoords().clear(); // Clear Coordinates after each game
        } else if (choice == 3) { // Quit
            cout << "Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }
        cin.ignore(100, '\n'); // Clear the input buffer
    }

    return 0;
}

