/* File:   Computer.cpp
 * Author: Noel Perez
 * Created on November 1, 2023, 6:34 PM
 */

#include "Computer.h"
#include <ctime>

Computer::Computer() {
    srand(static_cast<unsigned> (time(0)));
    randomChoice = rand() % 15;
}

Computer::Computer(const Computer& orig) {
}

Computer::~Computer() {
}

// Function for generating random ship orientation choices for the computer
void Computer::makeRandOrientation(int l, list<char>& list) {
    srand(static_cast<unsigned> (time(0)));
    forward_list<char> fList;

    for (int i = 0; i < l; ++i) {
        char direction = (rand() % 2 == 0) ? 'H' : 'V';
        fList.push_front((rand() % 2 == 0) ? 'H' : 'V');
    }
    // Merge two list
    merge(list.begin(), list.end(), fList.begin(), fList.end(), back_inserter(list));
}

// Function get random rows from a queue for computer 
queue<int> Computer::getRandCols() {

    int numElements = 5000;
    queue<int> qCol;
    queue<int> q;
    set<int> setCol;

    int *num = new int[numElements];
    setCol.find(qCol.front());

    set<int>::iterator it;

    for (int i = 0; i < numElements; i++) {
        num[i] = rand() % 10;
        int random = rand() % 100;
        qCol.push(rand() % 10);
        setCol.insert(random);
        q.push(rand() % 10);
    }
    qCol.swap(q);

    for (int i = 0; i < numElements; i++) {
        it = find(setCol.begin(), setCol.end(), q.front());
        qCol.push(num[*it]);
        q.pop();
    }
    delete []num;
    return qCol;
};

// Function Get random rows from a stack for computer ship placement and choices
stack<char> Computer::getRandRows() {
    int numElements = 5000;

    stack<char> rw; // = new stack<char>();
    stack<char> s; // = new stack<char>();
    list<char> a;
    list<char> otherList;
    list<char>::reverse_iterator it;
    char data[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    copy(data, data + 10, inserter(otherList, otherList.begin()));

    for (int i = 0; i < numElements; i++) {
        char r1 = rand() % 10 + 65;
        char r2 = rand() % 10 + 65;
        char r3 = rand() % 10 + 65;
        a.push_front(r3);
        s.push(r1);
        rw.push(r2);

        while (s.top() == rw.top()) {
            if (!s.empty()) {
                s.pop();
                rw.pop();
                a.clear();
                otherList.clear();
            }
            while (otherList.size() < 10)
                otherList.push_front(rand() % 10 + 65);
            while (rw.empty() || s.empty()) {
                s.push(rand() % 10 + 65);
                rw.push(rand() % 10 + 65);
                a.push_front(rand() % 10 + 65);
                otherList.push_front(rand() % 10 + 65);
            }
        }
    }
    for (it = a.rbegin(); it != a.rend(); it++) {
        *it=rand()%10+65;
        a.push_back(*it);
        rw.push(a.front());
        rw.push(*it);
        rw.push(rand() % 10 + 65);
    }
    return rw;
};

void::Computer::placeShips() {
    srand(static_cast<unsigned> (time(0)));
    char **compBoard = board.getGrid();
    int t = 0;
    int size = 10000;

    list<char> orientation;
    stack<char> randRow;
    queue<int> randCol;

    randRow = getRandRows(); 
    randCol = getRandCols();

    makeRandOrientation(size, orientation);

    std::list<char>::iterator it = orientation.begin();

    char direction = *it;

    while (t < randomChoice) {
        randRow.pop();
        randCol.pop();
        it++;
        t++;
    }


    for (int i = 0; i < 5; i++) {
        char r = randRow.top();
        int y = randCol.front();
      
        randRow.pop();
        randCol.pop();
        it++;
        int x; 
        // char r;
        // r = direction;

        map<int, pair<int, char>> &itr = Computer::ship.getShips();
        map<int, pair<string, char>> &itr2 = Computer::ship.getShipNO();

        cout << endl;
        cout << "\nPlacing " << itr2[i].first << " length " << itr[i].first << " ship.\n";

       // cin >> r>>y;
        r = toupper(r);
        x = r - 'A';
        // cout << "x is: " << x << endl;
        y = y;
        //   cout << "y is " << y << endl;

        // Keep prompting until a valid input is provided
        while (true) {
            //  cout << "Enter direction (H for horizontal, V for vertical): ";
            //  cin >> direction;
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

            r = randRow.top();
            y = randCol.front();
          
            randRow.pop();
            randCol.pop();
            it++;
            //cin >> r>>y;
            r = toupper(r);
            x = r - 'A';
            y = y;
            // cout << "Enter direction (H for horizontal, V for vertical): ";
            //  cin >> direction;
            direction = toupper(direction);

            while (true) {
                randRow.pop();
                randCol.pop();
                it++;
                //  cout << "Enter direction (H for horizontal, V for vertical): ";
                //  cin >> direction;
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
        //    cout << boolalpha << endl;
        //    cout << !(Computer::board.isValidPlacement(compBoard, x, y, direction, itr[i].first));
        while (!(Computer::board.isValidPlacement(compBoard, x, y, direction, itr[i].first))) {


            r = randRow.top();

            y = randCol.front();
            //   cout << "\nrow is " << r << endl;
            //  cout << "col is " << y << endl;
            randRow.pop();
            randCol.pop();
            it++;
            direction = *it;
            //  cout << "2nd while";

            //  cout << "\nINVALID PLACEMENT! " << endl;
            //  cout << "Re-enter starting coordinates for ";
            //   cout << itr2[i].first << " length " << itr[i].first << " ship.\n";

            // cin >> r>>y;
            r = toupper(r);

            x = r - 'A';
            //   cout << "x is: " << x << endl;
            y = y;
            //   cout << "y is " << y << endl;
            //   cout << "Enter direction (H for horizontal, V for vertical): ";
            //  cin >> direction;
            direction = toupper(direction);
        }
        for (int j = 0; j < itr[i].first; j++) {
            if (direction == 'H' || direction == 'h') {
                compBoard[x][y + j] = itr[i].second;
                //    s.insertCoord(i,r,y+j,itr[i].first);
                //   s.printShipCoords();
            } else if (direction == 'V' || direction == 'v') {
                compBoard[x + j][y] = itr[i].second;
                //    s.insertCoord(i,r+j,y,itr[i].first);
            }
        } // for loop 79

        if (i == 4) {
            //     display(board);
        } //}// else 77
    }// for loop 52

    board.displayBoard(); // Display after setting
    cout << endl;

}

void::Computer::takeTurns(Player &opponent) {
    int x, y;
    char r;
    int hits = 0;
    // char **board = Computer::board.getGrid();
    char **board = opponent.getBoard();
     map<int, pair<int, char>> &itr = Player::ship.getShips();
     map<int, pair<string, char>> &itr2 = Player::ship.getShipNO();

    //char **board = opponent.board.getGrid();
    //  cout<<"Computer.board.displayBoard line 323 "<<endl;
    // Computer::board.displayBoard();
    // cout<<"PLAYER::board.displayBoard() line 327;"<<endl;
    // Player::board.displayBoard();
    // opponent.board.displayBoard();
    
    //Player::ship.Hits();
    //  do {
    //  cout<<"\nIn Computer turn func line 328: "<<endl;
    //  Computer::board.displayBoard();

    //  cout<<"IN computer take turn func "<<endl;
    // int size = 10000;

    // list<char> orientation;
    stack<char> randRow;
    queue<int> randCol;

    randRow = getRandRows(); //randomRows();
    randCol = getRandCols();

    int i = 0;
    while (i < randomChoice) {
        randRow.pop();
        randCol.pop();
        i++;
    }
    randRow.pop();
    randCol.pop();


  //  r = randRow.top(); // UN COMMMENT

  //  y = randCol.front();  // UN COMMENT
    // cout << "\nrow is " << r << endl;
    //  cout << "col is " << y << endl;

    //  it++;

    cout << "\nEnter attack coordinates (e.g., A3): "; //TEST

      cin >> r >> y;  // TEST
    cout << "Computer attack: " << r << " " << y << " ";
    x = r - 'A';
    y = y;

    //        cout << "x is: " << x ;
    //        cout << " y is " << y << endl;


    //} while (board[x][y] == 'O' || board[x][y] == 'O');


    if (board[x][y] == 'A') {
        cout << "\nIt's a hit!\n";
        cout<<itr2[4].first<<", length"<<itr[4].first<<" is sunk!"<<endl;
        hits = Player::ship.Hits();
        for(int i=0; i<B_SIZE; i++){
            for(int j=0; j<B_SIZE; j++){
                if(board[i][j] == 'A'){
                   board[i][j]='X';
                }
            }
        }
        //opponent.ship.isShipAtCoord(i,r,y) = 'X';
    } else if (board[x][y] == 'B') {
        cout << "\nIt's a hit!\n";
        cout<<itr2[3].first<<", length"<<itr[3].first<<" is sunk!"<<endl;
        hits = Player::ship.Hits();
        for(int i=0; i<B_SIZE; i++){
            for(int j=0; j<B_SIZE; j++){
                if(board[i][j] == 'B'){
                    board[i][j]='X';
                }
            }
        }
    } else if (board[x][y] == 'C') {
        cout << "\nIt's a hit!\n";
        hits = Player::ship.Hits();
        for(int i=0; i<B_SIZE; i++){
            for(int j=0; j<B_SIZE; j++){
                if(board[i][j] == 'C'){
                    board[i][j]='X';
                }
            }
        }
    } else if (board[x][y] == 'D') {
        cout << "\nIt's a hit!\n";
      //  opponent.searchIndx(board, 0, 0,'D');
           for(int i=0; i<B_SIZE; i++){
            for(int j=0; j<B_SIZE; j++){
                if(board[i][j] == 'D'){
                    board[i][j]='X';
                }
            }
        }
    } else if (board[x][y] == 'S') {
        cout << "\nIt's a hit!\n";
        hits = Player::ship.Hits();
        for(int i=0; i<B_SIZE; i++){
            for(int j=0; j<B_SIZE; j++){
                if(board[i][j] == 'S'){
                    board[i][j]='X';
                }
            }
        }
    } else if (board[x][y] == '~') {
        cout << "\nIt's a miss.\n";
        board[x][y] = 'O';
        // Computer::board.displayBoard();
        // opponent.board.displayBoard();
    }
    //  } while (board[x][y] == '~' || board[x][y] == '~');


    // Computer::board.displayBoard();
    //cout<<"CALLED THE COMPUTER TAKE TURNS FUNCTION "<<endl;
   // opponent.display(board);
}

//// Function
//void::Computer::searchIndx(char**& board, int row, int col, char target) {
//      
//    // Base case: Check if we've reached beyond the array bounds
//    if (row >= B_SIZE) {
//        return;
//    }
//
//    // Check if the character matches the target character
//    if (board[row][col] == target) {
//       
//      
//        cout << "Character '" << target << "' found at [" << row << "][" << col << "]." << endl;
//        for(int i=0; i<B_SIZE; i++){
//            for(int j=0; j<B_SIZE; j++){
//                   board[row][col] = 'X';
//            }
//        }
//        
//       return;
//    }
//
//    // Check the next index
//    if (col + 1 < B_SIZE) {
//        searchIndx(board, row, col + 1, target); // Move to the next column in the same row
//    } else {
//        searchIndx(board, row + 1, 0, target); // Move to the next row
//    }
//}