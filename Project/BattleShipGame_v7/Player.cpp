/* File:   Player.cpp
 * Author: Noel Perez
 * Created on October 29, 2023, 9:18 PM
 */
#include "Player.h"
#include "Board.h"
#include <cctype>
using namespace std;

//Player::Player() {    
//}
//Player::Player() : board {
//} 

//Player::Player(const Player& orig) {
//}

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
    
    //Player::board.getGrid();

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
// Place player ships
//void::Player::placeShips(char **board, Ship s) {
//
//    cout << name << "Place your ships " << endl;
//
//    for (int i = 0; i < 5; i++) {
//        int x, y;
//        char r;
//        char direction;
//
//        map<int, pair<int, char>> &itr = s.getShips();
//        map<int, pair<string, char>> &itr2 = s.getShipNO();
//
//        display(board);
//
//        cout << endl;
//        cout << "\nPlacing " << itr2[i].first << " length " << itr[i].first << " ship.\n";
//
//        cout << "\nEnter starting coordinates (e.g., A3): ";
//        
//        cin >> r>>y;
//        r = toupper(r);
//        x = r - 'A';
//        cout << "x is: " << x << endl;
//        y = y;
//        cout << "y is " << y << endl;
//
//        // Keep prompting until a valid input is provided
//        while (true) {
//            cout << "Enter direction (H for horizontal, V for vertical): ";
//            cin >> direction;
//            direction = toupper(direction);
//
//            // Check if the input is valid
//            if (direction == 'H' || direction == 'V') {
//                break; // Exit the loop if valid input is received
//            } else {
//                cout << "Invalid input. Please enter 'H' or 'V'." << std::endl;
//            }
//
//            // Clear the input buffer
//            cin.clear();
//        }
//
//        while (x < 0 || x >= 10 || y < 0 || y > 10) {
//
//            cout << "\nINVALID PLACEMENT! " << endl;
//            cout << "Re-enter starting coordinates for ";
//            cout << itr2[i].first << " length " << itr[i].first << " ship.\n";
//
//            cin >> r>>y;
//            r = toupper(r);
//
//            x = r - 'A';
//            cout << "x is: " << x << endl;
//            y = y;
//            cout << "y is " << y << endl;
//            cout << "Enter direction (H for horizontal, V for vertical): ";
//            cin >> direction;
//            direction = toupper(direction);
//            while (true) {
//                cout << "Enter direction (H for horizontal, V for vertical): ";
//                cin >> direction;
//                direction = toupper(direction);
//
//                // Check if the input is valid
//                if (direction == 'H' || direction == 'V') {
//                    break; // Exit the loop if valid input is received
//                } else {
//                    cout << "Invalid input. Please enter 'H' or 'V'." << std::endl;
//                }
//                // Clear the input buffer
//                cin.clear();
//            }
//        }
//
//        while (!(Player::board.isValidPlacement(board, x, y, direction, itr[i].first))) {
//            cout << "2nd whie";
//
//            cout << "\nINVALID PLACEMENT! " << endl;
//            cout << "Re-enter starting coordinates for ";
//            cout << itr2[i].first << " length " << itr[i].first << " ship.\n";
//
//            cin >> r>>y;
//            r = toupper(r);
//
//            x = r - 'A';
//            cout << "x is: " << x << endl;
//            y = y;
//            cout << "y is " << y << endl;
//            cout << "Enter direction (H for horizontal, V for vertical): ";
//            cin >> direction;
//            direction = toupper(direction);
//        }
//        for (int j = 0; j < itr[i].first; j++) {
//            if (direction == 'H' || direction == 'h') {
//                board[x][y + j] = itr[i].second;
//                 s.insertCoord(i,r,y+j,itr[i].first);
//                 s.printShipCoords();
//            } else if (direction == 'V' || direction == 'v') {
//                board[x + j][y] = itr[i].second;
//                 s.insertCoord(i,r+j,y,itr[i].first);
//            }
//        } // for loop 79
//
//        if(i==4){
//            display(board);
//        } //}// else 77
//    }// for loop 52
//}

void::Player::placeShips() {
 // char **board = Player::board.getGrid();
     
    cout << name << ", Place your ships!" << endl;

    for (int i = 0; i < 5; i++) {
        int x, y;
        char r;
        char direction;

        map<int, pair<int, char>> &itr = Player::ship.getShips();
        map<int, pair<string, char>> &itr2 = Player::ship.getShipNO();

        display(Player::board.getGrid());

        cout << endl;
        cout << "\nPlacing " << itr2[i].first << " length " << itr[i].first << " ship.\n";

        cout << "\nEnter starting coordinates (e.g., A3): ";
        
        cin >> r>>y;
        r = toupper(r);
        x = r - 'A';
        cout << "x is: " << x << endl;
        y = y;
        cout << "y is " << y << endl;

        // Keep prompting until a valid input is provided
        while (true) {
            cout << "Enter direction (H for horizontal, V for vertical): ";
            cin >> direction;
            direction = toupper(direction);

            // Check if the input is valid
            if (direction == 'H' || direction == 'V') {
                break; // Exit the loop if valid input is received
            } else {
                cout << "Invalid input. Please enter 'H' or 'V'." << std::endl;
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
            cout << "x is: " << x << endl;
            y = y;
            cout << "y is " << y << endl;
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
                    cout << "Invalid input. Please enter 'H' or 'V'." << std::endl;
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
            cout << "x is: " << x << endl;
            y = y;
            cout << "y is " << y << endl;
            cout << "Enter direction (H for horizontal, V for vertical): ";
            cin >> direction;
            direction = toupper(direction);
        }
        for (int j = 0; j < itr[i].first; j++) {
            if (direction == 'H' || direction == 'h') {
                board.getGrid()[x][y + j] = itr[i].second;
                 Player::ship.insertCoord(i,r,y+j,itr[i].first);
                 Player::ship.printShipCoords();
            } else if (direction == 'V' || direction == 'v') {
                board.getGrid()[x + j][y] = itr[i].second;
                 Player::ship.insertCoord(i,r+j,y,itr[i].first);
            }
        } // for loop 79

        if(i==4){
            display(Player::board.getGrid());
        } //}// else 77
    }// for loop 52
   
}

//void::Player::takeTurns(Player &opponent){
//    int x, y;
//    char r;
//    int hits=0;
//   
//    char **board = opponent.board.getGrid();
//    board[0][0] = 'S';
// 
//    Player::ship.Hits();
//    do
//    {
//       cout << "Enter attack coordinates (e.g., A3): ";
//       
//      cin >> r >> y;
//
//      x = r - 'A';
//      y = y;      
//      
//         cout << "x is: " << x << endl;
//
//     cout << "y is " << y << endl;
//
//    } while(hits<6); //(board[r][y] == '~' || board[r][y] == '~');
//    cout << "You attack " << static_cast<char>('A' + x) << y << ". ";
//
//    if (board[r][y] == 'A')
//    {
//        cout << "It's a hit!\n";
//       hits= Player::ship.Hits();
//       //opponent.ship.isShipAtCoord(i,r,y) = 'X';
//    }
//    else if (board[r][y] == 'B')
//    {
//        cout << "It's a hit!\n";
//       board[r][y] = 'X';
//        hits= Player::ship.Hits();
//    }
//    else if (board[r][y] == 'C')
//    {
//        cout << "It's a hit!\n";
//       board[r][y] = 'X';
//        hits= Player::ship.Hits();
//    }
//    else if (board[r][y] == 'D')
//    {
//        cout << "It's a hit!\n";
//       board[r][y] = 'X';
//        hits= Player::ship.Hits();
//    }
//    else if (board[r][y] == 'S')
//    {
//       cout << "It's a hit!\n";
//       board[r][y] = 'X';
//        hits= Player::ship.Hits();
//    }
//    else
//    {
//        cout << "It's a miss.\n";
//        board[r][y] = '~';
//    }
//}

bool::Player::hasLost()
{
    char **board = Player::board.getGrid();
            
    for (int i = 0; i < B_SIZE; i++)
    {
        for (int j = 0; j < B_SIZE; j++)
        {
            if (board[i][j] == 'A')
            {
                return false;
            }
            else if (board[i][j] == 'B')
            {
                return false;
            }
            else if (board[i][j] == 'C')
            {
                return false;
            }
            else if (board[i][j] == 'D')
            {
                return false;
            }
            else if (board[i][j] == 'S')
            {
                return false;
            }
        }
    }
    return true;
}


// edit
void::Player::takeTurns(Player &opponent){
    int x, y;
    char r;
    int hits=0;
   
   char **board = opponent.board.getGrid();
    board[0][0] = 'S';
    
    opponent.board.displayBoard();
 
    //Player::ship.Hits();
    do
    {
       cout << "Enter attack coordinates (e.g., A3): ";
       
      cin >> r >> y;

      x = r - 'A';
      y = y;      
      
         cout << "x is: " << x << endl;

     cout << "y is " << y << endl;

   } while(board[x][y] == '~' || board[x][y] =='X');
    cout << "You attack " << static_cast<char>('A' + x) << y << ". ";

    if (board[x][y] == 'A')
    {
        cout << "It's a hit!\n";
       hits= Player::ship.Hits();
       //opponent.ship.isShipAtCoord(i,r,y) = 'X';
    }
    else if (board[x][y] == 'B')
    {
        cout << "It's a hit!\n";
       board[x][y] = 'X';
        hits= Player::ship.Hits();
    }
    else if (board[x][y] == 'C')
    {
        cout << "It's a hit!\n";
       board[x][y] = 'X';
        hits= Player::ship.Hits();
    }
    else if (board[x][y] == 'D')
    {
        cout << "It's a hit!\n";
       board[x][y] = 'X';
        hits= Player::ship.Hits();
        opponent.board.displayBoard();
    }
    else if (board[x][y] == 'S')
    {
       cout << "It's a hit!\n";
       board[x][y] = 'X';
        hits= Player::ship.Hits();
        opponent.board.displayBoard();
    }
     else if (board[x][y] == '~')
    {
        cout << "It's a miss.\n";
        board[x][y] = 'O';
        opponent.board.displayBoard();
    }
    //} while(opponent.board[x][y] == '~');
}