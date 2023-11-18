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

void clearScreen() {
    cout << "\033c";
}

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

  
    int choice = 0;

    while (choice != 3) {
        cout<<endl;
        cout << "Menu:" << endl;
        cout << "1. Display Rules" << endl;
        cout << "2. Play Game" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            
        } else if (choice == 1) {
            // Display the rules in stored in a .txt file 
            cout << endl;
            for (const char& words : text) {
                cout << words;
            }
            cout << '\n';
            clearScreenChoice();
            
        } else if (choice == 2) {
            Coordinates c;
            Game game;
            game.setupGame();
            game.playGame();
            c.getAllCoords().clear();
        } else if (choice == 3) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }

        cin.ignore(100, '\n'); // Clear the input buffer
    }

    return 0;
}

