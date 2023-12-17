/* File:   Player.cpp
 * Author: Noel Perez
 * Created on October 29, 2023, 9:18 PM
 */
#include "Player.h"
#include "Board.h"
#include <cctype>
using namespace std;

// Default constructor 
Player::Player(){
} 
// Destructor
Player::~Player() {   
}

// Set player name
void::Player::setName(string name) {
    this->name = name;
}

// Get player name
string Player::getName() {
    return this->name;
}

// Display players board
void::Player::display(char **board) {
    cout << "\n";
    for (int j = 0; j < B_SIZE; j++) { // Column numbers
        cout << setw(5) << j;
    }
    // Rows with letters
    for (int i = 0; i < B_SIZE; i++) {
        cout << "\n";
        cout << static_cast<char> ('A' + i) << "|";
        for (int j = 0; j < B_SIZE; j++) {
            cout << "[ " << board[i][j] << " ]";
        }
    }
    
}// Overloaded function that places the Players ships
void::Player::placeShips() {
    cout<<"\n" << name << ", Place your ships!" << endl;
    // MOVE BACK TO 5!
    for (int i = 0; i < 5; i++) {
        int x, y;  // Variables for user input
        char r;     // User's row choice
        char direction; // User's ship orientation choice

        // 2D map with pair of integers and characters as values
        // Key maps to ships length and board symbol
        map<int, pair<int, char>> &itr = Player::ship.getShips();
        // 2D map with pair of string and characters as values
        // Key maps to ships name and orientation on the board
        map<int, pair<string, char>> &itr2 = Player::ship.getShipNO();

        // Display board after each ship placement so player can see
        display(Player::board.getGrid()); 

        cout << endl;
        cout << "\nPlace " << itr2[i].first << " length " << itr[i].first << " ship.\n";
        cout << "\nEnter starting coordinates (e.g., A3): ";

        cin >> r>>y; // User input for row and column choices 
         
        r = toupper(r); // Make upper case 
        x = r - 'A';    // Make row char into integer so it can be placed on board 
        y = y;
        
        
        /* Input validation: check user input for ship orientation 
         * Keep prompting until a valid input is provided
         */     
        while (true) {
            cout << "Enter direction (H for horizontal, V for vertical): ";
            cin >> direction;
            direction = toupper(direction);
            // Check if the input is valid
            if (direction == 'H' || direction == 'V') {
                break; // Exit the loop if valid input is received
            } else {
                cout << "Invalid input. Please enter 'H' or 'V'." << endl;
            }
            // Clear the input buffer
            cin.clear();
        }
// Input validation to make sure row is char: 'A' - 'J' and column is integer 0-9
        while (x < 0 || x >= 10 || y < 0 || y > 10) {
            cout << "\nINVALID PLACEMENT! " << endl;
            cout << "Re-enter starting coordinates for ";
            cout << itr2[i].first << " length " << itr[i].first << " ship.\n";

            cin >> r >> y; // User input of rows and columns
            
            r = toupper(r); // Make row char uppercase 
            x = r - 'A';    // Make row integer for board 
            y = y;          
            cout << "Enter direction (H for horizontal, V for vertical): ";
            
            cin >> direction; // user input for ship orientation
            direction = toupper(direction);
            
       // Loop for input validation 
            while (true) {
                cout << "Enter direction (H for horizontal, V for vertical): ";
                cin >> direction;
                direction = toupper(direction);

                // Check if the input is valid
                if (direction == 'H' || direction == 'V') {
                    break; // Exit the loop if valid input is received
                } else {
                    cout << "Invalid input. Please enter 'H' or 'V'." << endl;
                }
                cin.clear();  // Clear the input buffer
            }
        }
// Check if ship placement is valid: not overlapping or over the board edge
        while (!(Player::board.isValidPlacement(Player::board.getGrid(), x, y, direction, itr[i].first))) {
            cout << "\nINVALID PLACEMENT! " << endl;
            cout << "Re-enter starting coordinates for ";
            cout << itr2[i].first << " length " << itr[i].first << " ship.\n";

            cin >> r>>y; // User input for row and column
            
            r = toupper(r); // Make row upper case 
            x = r - 'A';    // Make row into integer
            y = y;
            cout << "Enter direction (H for horizontal, V for vertical): ";
            cin >> direction;
            direction = toupper(direction); // Make uppercase 
        }
    // Place ships on board with correct length and orientation    
        for (int j = 0; j < itr[i].first; j++) { 
            if (direction == 'H' || direction == 'h') {
              // Fill board with correct ship symbol and orientation 
                board.getGrid()[x][y + j] = itr[i].second; 
              // Insert each ship's coordinates into map
                Player::ship.insertCoord(i, r, y + j, itr[i].first);
              // Insert each ship's orientation into map 
                Player::ship.addToMapNO(i,direction);
            } else if (direction == 'V' || direction == 'v') {
               // Fill board with correct ship symbol and orientation 
                board.getGrid()[x + j][y] = itr[i].second;
               // Insert each ship's coordinates into map
                Player::ship.insertCoord(i, r + j, y, itr[i].first);
               // Insert each ship's orientation into map  
                Player::ship.addToMapNO(i,direction);
            }
        } // for loop 79
// Display board after all player's ships have been placed 
        if (i == 4) {
            Player::board.displayBoard();
            cout << "\n\nAll " << Player::name << "'s ships coordinates: " << endl;
        // Display set of all ship coordinates
            Player::ship.printShipCoords();
        } // else 77
    }// for loop 52

}
// Bool function to determine if ships are still on board after each player turn to determine winner
bool::Player::hasLost() {
    char **board = Player::board.getGrid(); // Get respective player's board  
    for (int i = 0; i < B_SIZE; i++) {
        for (int j = 0; j < B_SIZE; j++) {
            if (board[i][j] == 'A') { // check for aircraft carrier 
                return false;
            } else if (board[i][j] == 'B') { // check for battleship
                return false;
            } else if (board[i][j] == 'C') { // check for carrier
                return false;
            } else if (board[i][j] == 'D') { // check for destroyer
                return false;
            } else if (board[i][j] == 'S') { // check for submarine
                return false;
            }
        }
    }
    return true;
}
// Function: Overloaded for switching players turns
void::Player::takeTurns(Player &opponent) {
     // Variables for Player choices: row, column, row as int and ship hits
    int x, y;  // Variables for user input for when they are taking turns
    char r;
    int hits = 0;

    // Get the appropriate board to update with symbols: hit, miss, etc
    char **board = opponent.board.getGrid();
    
    // 2D map with ships as key values that returns length and ship symbol
    map<int, pair<int, char>> &itr = Player::ship.getShips();
    // 2D map with ships as key values that returns ship name and orientation
    map<int, pair<string, char>> &itr2 = Player::ship.getShipNO();
    
    showHint(); // Show hint function and ask user if they need a hint
   
    cout << "\nEnter attack coordinates (e.g., A3): ";

    cin >> r >> y; // Get user input for row and column 
 
    r = toupper(r); // Make uppercase so it converts to correct integer value on board
    x = r - 'A';    // Make row char into appropriate integer 
    y = y;
   
    // Input validation for user input so that input is within ship board coordinates
  while (x < 0 || x >= 10 || y < 0 || y > 10 || (!isalpha(r))) {
            cout << "\nINVALID COORDINATES! " << endl;
            cout << "Re-enter coordinates: ";
         
            cin >> r >> y; // user input of rows and columns   
            r = toupper(r); // make uppercase for correct conversion 
            x = r - 'A';    // make row into integer for correct board coordinates
            y = y;
    } 
    cout << "You attack: " << static_cast<char> ('A' + x) << " " << y << " ";
    
   /* Check if computer attack choices are hit or miss on board
   *  Then update board accordingly to reflect which ship was hit or 
   *  which coordinate was missed with correct symbol(s)
   */
    if (board[x][y] == 'A') { // Check board to see if Aircraft carrier was hit 
        cout << "\nIt's a hit!\n";
        cout << "You sunk the " << itr2[4].first<<": length "<<itr[4].first;
        opponent.searchIndx(board, 0, 0, 'A'); // Recursively check board indices
        hits = Player::ship.Hits(); // Update ship hits
    } else if (board[x][y] == 'B') {  // Check board to see if Battleship was hit 
        cout << "\nIt's a hit!\n";
        cout << "You sunk the " << itr2[3].first<<": length "<<itr[3].first; 
        hits = Player::ship.Hits();  // Update ship hits
        opponent.searchIndx(board, 0, 0, 'B'); // Recursive function to check indices 
    } else if (board[x][y] == 'C') { // Check board to see if Carrier was hit
        cout << "\nIt's a hit!\n";
        cout << "You sunk the " << itr2[2].first<<": length "<<itr[2].first; 
        hits = Player::ship.Hits(); // Update ship hits
        opponent.searchIndx(board, 0, 0, 'C'); 
    } else if (board[x][y] == 'D') { // Check board to see if Destroyer was hit
        cout << "\nIt's a hit!\n";
        cout << "You sunk the " << itr2[0].first<<": length "<<itr[0].first;
        hits = Player::ship.Hits(); // Update ship hits
        opponent.searchIndx(board, 0, 0, 'D'); // Recursively check board for character 
    } else if (board[x][y] == 'S') { // Check board to see if Submarine was hit
        cout << "\nIt's a hit!\n";
        cout << "You sunk the " << itr2[1].first<<": length "<<itr[1].first;
        hits = Player::ship.Hits(); // Update ship hits
        opponent.searchIndx(board, 0, 0, 'S');  // Recursively check board for target character
    } else if (board[x][y] == '~') { // Otherwise miss update with miss character 
        cout << "\nIt's a miss.\n";
        board[x][y] = 'O';
    }
}

// Recursive function to check indices of 2D array 
void::Player::searchIndx(char**& board, int row, int col, char target) {
    // Base case: Check if we've reached beyond the array bounds
    if (row >= B_SIZE) {
        return;
    }
    // Check if the character matches the target character
    if (board[row][col] == target) {
        // cout << "Character '" << target << "' found at [" << row << "][" << col << "]." << endl;
         board[row][col] = 'X';
    }
    // Check the next index
    if (col + 1 < B_SIZE) {
        searchIndx(board, row, col + 1, target); // Move to the next column in the same row
    } else {
        searchIndx(board, row + 1, 0, target); // Move to the next row
    }
}

// Function that shows the player a hint: shows computer's ship coordinates
void::Player::showHint(){
 char userInput;
// Loop to check if user wants a hint
    while (true) {
        cout<<"Would you like a hint? "<<endl;
        cout << "Please enter 'y' or 'n': ";
        cin >> userInput;
        userInput = toupper(userInput); // Convert to upppercase
        cin.ignore(100,'\n');
   // If they want a hint display Computer's ships coordinates
        if (userInput == 'Y' ){
            cout<<"Computer's ship coordinates: "<<endl;
            Coordinates::printCoords();
            break;
        } else {
            return;
        }
    }
}

