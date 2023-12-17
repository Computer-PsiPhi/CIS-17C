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

#include "Scoreboard.h"
#include "BinarySearchTree.h"
#include "Graph.h"
#include "HashTable.h"

using namespace std;

// Function to clear screen
void clearScreen() {
    cout << "\033c";
};

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
};

int main(int argc, char** argv) {
    
     srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

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
    int size = 26; 
       BinarySearchTree bst;
       Graph graph;
     bst.insertFromFile("scores.txt");
    // bst.printTree();
     
      HashTable hashTable(size);
     
    // Display menu
//    while (choice != 3) {
//        cout<<endl;
//        cout << "Menu:" << endl;
//        cout << "1. Display Rules" << endl;
//        cout << "2. Play Game" << endl;
//        cout << "3. Quit" << endl;
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        // Input validation for menu options
//        if (cin.fail()) {
//            cout << "Invalid input. Please enter a valid number." << endl;
//            cin.clear();
//            cin.ignore(100, '\n');
//         // Choice 1 from menu   
//        } else if (choice == 1) {
//            // Display the rules in stored in a .txt file 
//            cout << endl;
//            for (const char& words : text) {
//                cout << words;
//            }
//            cout << '\n';
//            clearScreenChoice(); // clear screen
//         // Choice 2 from menu
//        } else if (choice == 2) {
//            Coordinates c; // Declare Coordinates object that resets each game
//            // Declare Game object so that it resets if user chooses to play multiple games
//            Game game;    
//            game.setupGame(); // Setup game with both player's boards
//            game.playGame(); // Start game 
//            c.getAllCoords().clear(); // Clear Coordinates after each game
//        } else if (choice == 3) { // Quit
//            cout << "Goodbye!" << endl;
//        } else {
//            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
//        }
//        cin.ignore(100, '\n'); // Clear the input buffer
//    }

 
   
    string playerNames[26] = {
       "Jack", "Grace", "Henry", "Isabella", "Frank",
        "Alice", "Emma", "Charlie", "David", "Bobby",
        "Yetty", "Victor", "Willow", "Xavier", "Urie",
        "Kate", "Noah", "Mia", "Liam", "Olivia",
        "Penelope", "Wolly", "Ryan", "Sophia", "Thomas" ,"Quinn",
       
    };
  //  int plyScores[26];
//    int playerScores[26] = { 150, 200, 180, 165, 190,
//                             175, 185, 170, 155, 145,
//                             160, 140, 130, 125, 135,
//                             115, 120, 110, 105, 100,
//                             95, 90, 85, 80, 75 , 99 };
int* values = bst.getValuesFromRoot();

for(int i =0 ; i < size; i++){
    graph.addVertex(playerNames[i]);
     hashTable.insert(playerNames[i], values[i]);
}

 for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            graph.addEdge(playerNames[i], playerNames[j], (j%1 == 0 && j%rand()%9 == 0)?rand()%5+1:0); // Adding an edge with weight 1
        }
    }
   Scoreboard scoreboard(playerNames, values, size);
  // graph.display();
    // Display unsorted scores
    scoreboard.displayScores();

    // Sort and display scores
    scoreboard.sortScores();
   // scoreboard.displayScores();
    hashTable.printHT();
     bool goAhead = true;
    while (goAhead) {
        string userInput;
        cout << "Enter a name to search for: ";
        cin >> userInput;

        int score = hashTable.search(userInput);
        if (score != -1) {
            cout << "Name: " << userInput << ", Score: " << score << endl;
        } else {
            cout << "Name '" << userInput << "' not found." << endl;
        }

        char choice;
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
        toupper(choice);
        if (choice != 'Y') {
            goAhead = false;
        }
    }

    
    delete[]values;
    return 0;
}

