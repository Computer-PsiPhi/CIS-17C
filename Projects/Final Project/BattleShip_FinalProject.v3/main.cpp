/*  File:   main.cpp
 * Author: Noel Perez
 * Created on October 20, 2023, 9:13 PM
 */
#include <cstdlib>
#include <string>
#include <deque>
#include <fstream>
#include <iterator>
#include <iomanip>

#include "Board.h"
#include "Coordinates.h"
#include "Ship.h"
#include "Computer.h"
#include "Game.h"
#include "Player.h"

#include "Scoreboard.h"
#include "BinarySearchTree.h"
#include "HashTable.h"
#include "Graph.h"

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

// Main function 
int main(int argc, char** argv) {

    srand(static_cast<unsigned int> (time(0))); // Seed for random number generation

    // String array for player names , used in scoreboard
    string playerNames[26] = {
        "Jack", "Grace", "Henry", "Isabella", "Frank",
        "Alice", "Emma", "Charlie", "David", "Bobby",
        "Yetty", "Victor", "Willow", "Xavier", "Urie",
        "Kate", "Noah", "Mia", "Liam", "Olivia",
        "Patricia", "Wolly", "Ryan", "Sophia", "Thomas", "Quinn",
    };

    int choice = 0; // Variable used for user input
    int size = 26; // Variable for number of players
    string art;    //  Variable for displaying ascii art
    bool goAhead = true;  // Loop condition 

    BinarySearchTree bst; // Binary Search Tree object declaration 
    Graph graph;          // Graph object declaration 
    HashTable hashTable(size); // HashTable object declaration 

    /*Load binary search tree with player's scores from text file*/
    bst.loadFromFile("scores.txt");

    /* Get int scores from loaded Binary Search Tree so they can be
     * put into scoreboard object
     */
    int* values = bst.getValuesFromRoot();

    // Load Scoreboard with int values from Binary Search Tree
    Scoreboard scoreboard(playerNames, values, size);

    // File with game rules
    ifstream file("Rules.txt");
    // File with ascii Art 
    ifstream file2("Art.txt");

    // Test files open
    if (!file.is_open() || !file2.is_open()) {
        cerr << "Failed to open the file." << endl;
        return -1;
    }

    // Deque with Random access iterator to get file stream
    deque<char> text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    while (getline(file2, art)) { // Display ascii art 
        cout << art << "\n";
    }
    file2.close(); // close file when done 

    scoreboard.displayScores(); // Display Players and scores on scoreboard for user to see  

    // Add each player as a vertex to graph and hash name
    for (int i = 0; i < size; i++) {
        graph.addVertex(playerNames[i]); // Add vertices to graph
        hashTable.insert(playerNames[i], values[i]); // insert hash into table 
    }

    // Add edge and weight between vertices
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
           graph.addEdge(playerNames[i], playerNames[j], (j % 1 == 0 && j % rand() % 9 == 0) ? rand() % 5 + 1 : 0); // Adding edges with weights 
        }
    }
    cout << "\n";

    /************DISPLAY MENU**************/
    while (choice != 7) {
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Display Rules" << endl;
        cout << "2. Play Game" << endl;
        cout << "3. Test Hash: Search For A Player(Player name hashed and stored as key-value pair with score)" << endl;
        cout << "4. Test Recursive Sort: Sort Players Alphabetically(MergeSort)" << endl;
        cout << "5. Test Graph: Show Previous Matches (Graph Implementation)" << endl;
        cout << "6. Test Tree: Binary Search Tree Options" << endl;
        cout << "7. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Input validation for menu options
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
            clearScreenChoice(); // clear screen

        } else if (choice == 2) {
            Coordinates c; // Declare Coordinates object that resets each game
            // Declare Game object so that it resets if user chooses to play multiple games
            Game game;
            game.setupGame(); // Setup game with both player's boards
            game.playGame(); // Start game 
            c.getAllCoords().clear(); // Clear Coordinates after each game

        } else if (choice == 3) { // Hash option test 

            do {
                string userInput; // Var for user input 
                cout << "Enter a name to search for: ";
                cin >> userInput;

                int score = hashTable.search(userInput); // Search hash table 
                if (score != -1) {
                    cout << "\nName: " << userInput << ", Score: " << score << endl; //Output
                } else {
                    cout << "\nName '" << userInput << "' not found." << endl; // Output 
                }
                cin.ignore();
                char user; // for user input
                cout << "\nDo you want to search for another player? (y/n): "; // prompt 
                cin >> user;
                user = toupper(user);
                if (user != 'Y') {
                    goAhead = false;
                }
            } while (goAhead);

            if (goAhead == false) {
                cout << "Do you want to print the hash table? (y/n)"; // ask user to print table 
                char user;
                cin >> user;
                user = toupper(user);
                if (user == 'Y') {
                    cout << "\nPlayer Names & Scores" << endl;
                    cout << endl;
                    hashTable.printHT(); // Print hash table 

                    cout << "\nPlayer name is hashed and stored as key-value pairs in indices" << endl;
                }
            }

        } else if (choice == 4) { // Sort player names with merge-sort 
            scoreboard.sortScores(); // cal the sort function 
            cout << "\n\nAfter Sorting Alphabetically with MergeSort\n" << endl;
            scoreboard.displayScores(); // display after sorting 
            
        } else if (choice == 5) { // Graph test option 

            graph.display(); // Display graph 

            cout << "\nGraph displayed above." << endl;

            cout << "\nDo you want to add to the graph ?(y/n)"; // prompt

            char user;
            cin >> user;
            user = toupper(user);

            if (user == 'Y') {
                string userInput; // user input to add vertex
                string userInput2; // user input to add vertex 
                int weight;         // for weight user wants to add 
                cout << "\nEnter a name to add as vertex: ";
                cin >> userInput; // input

                graph.addVertex(userInput); // add name user entered as vertex 
                cout << "\nEnter another name to add so there is an edge between: ";
                cin >>userInput2; // input

                graph.addVertex(userInput2); // add other name user entered as vertex so an edge can be made 
                cout << "\nEnter weight which symbolizes number of matches against each other: ";
                cin >> weight; // input
                // make an edge after vertices have been added with weight 
                graph.addEdge(userInput, userInput2, weight); 

                graph.display(); // display so user can see what they added
                cout << "\nAfter adding to graph above." << endl;
            }

        } else if (choice == 6) { // Binary Tree Option 
            int num = 0;
            bst.displayTree(); // Display tree
            bst.displayDepth(); // Display tree depth-wise
            bst.inorder();      // Display tree in-order
            bst.postorder();    // Display tree post-order
            bst.preorder();     // Display tree pre-order
            int x = bst.getHeight();
            cout << "Height of tree: " << x << endl; // display tree height 
            cout << boolalpha;
            cout << "Tree is balanced: " << bst.isBalanced() << endl; // display if balanced 
            cout << "\nEnter value to search: "; // prompt 
            cin>>num;                           // input
            cout << num << " in tree: " << bst.search(num) << endl; // search for value 
            cout << "\nEnter value to remove: ";
            cin>>num;                               // input
            bst.remove(num);                        // remove element user entered
            bst.displayTree();                      // display tree after removing element
            bst.displayDepth();                     // display depth after removing element 
            cout << "Tree is balanced: " << bst.isBalanced() << endl; // display if balanced 
            clearScreenChoice();                // prompt to clear screen 
        } else if (choice == 7) { // Quit
            cout << "Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }
        cin.ignore(100, '\n'); // Clear the input buffer
    }

    // clean up memory 
    delete[]values; 
    
    return 0;
}

