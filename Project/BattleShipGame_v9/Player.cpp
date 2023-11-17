/* File:   Player.cpp
 * Author: Noel Perez
 * Created on October 29, 2023, 9:18 PM
 */
#include "Player.h"
#include "Board.h"
#include <cctype>
using namespace std;


Player::Player(){
} 

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
}

void::Player::placeShips() {
    // char **board = Player::board.getGrid();

    cout << name << ", Place your ships!" << endl;
    // MOVE BACK TO 5!
    for (int i = 0; i < 1; i++) {
        int x, y;
        char r;
        char direction;

        map<int, pair<int, char>> &itr = Player::ship.getShips();
        map<int, pair<string, char>> &itr2 = Player::ship.getShipNO();

        display(Player::board.getGrid());

        cout << endl;
        cout << "\nPlace " << itr2[i].first << " length " << itr[i].first << " ship.\n";

        cout << "\nEnter starting coordinates (e.g., A3): ";

        cin >> r>>y;
        r = toupper(r);
        x = r - 'A';
        //  cout << "x is: " << x << endl;
        y = y;
        //  cout << "y is " << y << endl;

        // Keep prompting until a valid input is provided
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

        while (x < 0 || x >= 10 || y < 0 || y > 10) {

            cout << "\nINVALID PLACEMENT! " << endl;
            cout << "Re-enter starting coordinates for ";
            cout << itr2[i].first << " length " << itr[i].first << " ship.\n";

            cin >> r>>y;
            r = toupper(r);

            x = r - 'A';
            //  cout << "x is: " << x << endl;
            y = y;
            //  cout << "y is " << y << endl;
            cout << "Enter direction (H for horizontal, V for vertical): ";
            cin >> direction;
            direction = toupper(direction);
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
        }

        while (!(Player::board.isValidPlacement(Player::board.getGrid(), x, y, direction, itr[i].first))) {
            cout << "2nd whie";

            cout << "\nINVALID PLACEMENT! " << endl;
            cout << "Re-enter starting coordinates for ";
            cout << itr2[i].first << " length " << itr[i].first << " ship.\n";

            cin >> r>>y;
            r = toupper(r);

            x = r - 'A';
            //  cout << "x is: " << x << endl;
            y = y;
            //  cout << "y is " << y << endl;
            cout << "Enter direction (H for horizontal, V for vertical): ";
            cin >> direction;
            direction = toupper(direction);
        }
        for (int j = 0; j < itr[i].first; j++) {
            if (direction == 'H' || direction == 'h') {
                board.getGrid()[x][y + j] = itr[i].second;
                Player::ship.insertCoord(i, r, y + j, itr[i].first);
                // Player::ship.printShipCoords();
            } else if (direction == 'V' || direction == 'v') {
                board.getGrid()[x + j][y] = itr[i].second;
                Player::ship.insertCoord(i, r + j, y, itr[i].first);
            }
        } // for loop 79

        if (i == 4) {

            Player::board.displayBoard();
            cout << "\n\nAll " << Player::name << " ships' coordinates:  " << endl;
            Player::ship.printShipCoords();
        } //}// else 77
    }// for loop 52

}

bool::Player::hasLost() {
    char **board = Player::board.getGrid();
    for (int i = 0; i < B_SIZE; i++) {
        for (int j = 0; j < B_SIZE; j++) {
            if (board[i][j] == 'A') {
                return false;
            } else if (board[i][j] == 'B') {
                return false;
            } else if (board[i][j] == 'C') {
                return false;
            } else if (board[i][j] == 'D') {
                return false;
            } else if (board[i][j] == 'S') {
                return false;
            }
        }
    }
    return true;
}


// Function
void::Player::takeTurns(Player &opponent) {
    int x, y;
    char r;
    int hits = 0;

    char **board = opponent.board.getGrid();

    map<int, pair<int, char>> &itr = Player::ship.getShips();
    map<int, pair<string, char>> &itr2 = Player::ship.getShipNO();
    //   board[0][0] = 'P';

    //  cout<<"in Player turn func LIne 391"<<endl;
    // opponent.board.displayBoard();

    // cout<<"Player take turn line 394 "<<endl;
    // Player::board.displayBoard();

    //Player::ship.Hits();
    //  do
    //  {
    //   cout<<"IN PLAYER TAKE TURN: "<<endl;
    cout << "\nEnter attack coordinates (e.g., A3): ";

    cin >> r >> y;
    r = toupper(r);

    x = r - 'A';
    y = y;

    //   cout << "x is: " << x << endl;

    //  cout << "y is " << y << endl;

    //   } while(board[x][y] == '~' || board[x][y] =='X');
    cout << "You attack: " << static_cast<char> ('A' + x) << " " << y << " ";

    if (board[x][y] == 'A') {
        cout << "\nIt's a hit!\n";
        cout << "You sunk the " << itr2[4].first;
        opponent.searchIndx(board, 0, 0, 'A');
    } else if (board[x][y] == 'B') {
        cout << "\nIt's a hit!\n";
        cout << "You sunk the " << itr2[3].first;
        hits = Player::ship.Hits();
        opponent.searchIndx(board, 0, 0, 'B');
    } else if (board[x][y] == 'C') {
        cout << "\nIt's a hit!\n";
        cout << "You sunk the " << itr2[2].first;
        hits = Player::ship.Hits();
        opponent.searchIndx(board, 0, 0, 'C');
    } else if (board[x][y] == 'D') {
        cout << "\nIt's a hit!\n";
        cout << "You sunk the " << itr2[0].first;
        hits = Player::ship.Hits();
        opponent.searchIndx(board, 0, 0, 'D');
    } else if (board[x][y] == 'S') {
        cout << "\nIt's a hit!\n";
        cout << "You sunk the " << itr2[1].first;
        hits = Player::ship.Hits();
        opponent.searchIndx(board, 0, 0, 'S');
    } else if (board[x][y] == '~') {
        cout << "\nIt's a miss.\n";
        board[x][y] = 'O';
    }
}

void::Player::searchIndx(char**& board, int row, int col, char target) {
    // Base case: Check if we've reached beyond the array bounds
    if (row >= B_SIZE) {
        return;
    }

    // Check if the character matches the target character
    if (board[row][col] == target) {
        // cout << "Character '" << target << "' found at [" << row << "][" << col << "]." << endl;
        for (int i = 0; i < B_SIZE; i++) {
            for (int j = 0; j < B_SIZE; j++) {
                board[row][col] = 'X';
            }
        }
    }

    // Check the next index
    if (col + 1 < B_SIZE) {
        searchIndx(board, row, col + 1, target); // Move to the next column in the same row
    } else {
        searchIndx(board, row + 1, 0, target); // Move to the next row
    }
}