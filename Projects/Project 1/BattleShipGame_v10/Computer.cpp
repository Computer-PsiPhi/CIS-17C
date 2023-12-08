/* File:   Computer.cpp
 * Author: Noel Perez
 * Created on November 1, 2023, 6:34 PM
 * NOTE: Need to add validation for grid that already has an 'X' so that
 * user can't get guess same spot twice
 */
#include "Computer.h"
#include <ctime>

// Default constructor with random seed generator simulating random computer choice
Computer::Computer() {
    srand(static_cast<unsigned> (time(0)));
    randomChoice = rand() % 15;
}
// Destructor 
Computer::~Computer() {
}

// Function for generating random ship orientation choices for the computer
void Computer::makeRandOrientation(int l, list<char>& list) {
    srand(static_cast<unsigned> (time(0)));
    forward_list<char> fList; // declare forward list 

    for (int i = 0; i < l; ++i) {
        char direction = (rand() % 2 == 0) ? 'H' : 'V'; // Fill randomly with H or V
        fList.push_front((rand() % 2 == 0) ? 'H' : 'V'); // Fill randomly with H or V
        fList.push_front(direction);
    }
    // Merge two list
    merge(list.begin(), list.end(), fList.begin(), fList.end(), back_inserter(list));
    // List is passed by reference so merged list will be used in program 
}

// Function get random rows from a queue for computer 
queue<int> Computer::getRandCols() {

    int numElements = 5000; // Number of elements to fill containers
    queue<int> qCol;  // queue to hold random column values
    queue<int> q;   // queue to hold random column values which will be transferred over
    set<int> setCol; // set to hold queue elements

    int *num = new int[numElements]; // dynamic array to transfer random elements
    setCol.find(qCol.front()); // Find the front of the queue

    set<int>::iterator it; // iterator declaration 

    // Randomly fill containers
    for (int i = 0; i < numElements; i++) {
        num[i] = rand() % 10;
        int random = rand() % 100;
        qCol.push(rand() % 10);
        setCol.insert(random);
        q.push(rand() % 10);
    }
    qCol.swap(q); // swap the two quees
    // Consolidate all random values and pop onto queue that will returned and used 
    for (int i = 0; i < numElements; i++) {
        it = find(setCol.begin(), setCol.end(), q.front());
        qCol.push(num[*it]);
        q.pop();
    }
    delete []num; // release dynamically allocated memory 
    return qCol; // return queue
};

// Function to get random rows from a stack for computer ship placement and choices
stack<char> Computer::getRandRows() {
    int numElements = 5000;

    stack<char> rw; // declare stack 
    stack<char> s; // declare other stack to transfer elements
    list<char> a;   // declare list for randomization 
    list<char> otherList; // declare other list to transfer list elements
    list<char>::reverse_iterator it; // declaration of reverse iterator 
    // Array with ideal elements
    char data[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Copy ALGORITHM STL: Copy array into list
    copy(data, data + 10, inserter(otherList, otherList.begin()));

    // Fill containers with random values A-J
    for (int i = 0; i < numElements; i++) {
        char r1 = rand() % 10 + 65;
        char r2 = rand() % 10 + 65;
        char r3 = rand() % 10 + 65;
        a.push_front(r3);
        s.push(r1);
        rw.push(r2);
        // Delete elements if the two stacks are the same 
        while (s.top() == rw.top()) {
            if (!s.empty()) {
                s.pop();
                rw.pop();
                a.clear();
                otherList.clear();
            }
            // Randomize elements
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
    // Fill stack that will be returned with more random elements A-J
    for (it = a.rbegin(); it != a.rend(); it++) {
        *it=rand()%10+65;
        a.push_back(*it);
        rw.push(a.front());
        rw.push(*it);
        rw.push(rand() % 10 + 65);
    }
    return rw; // Return stack 
};

// Function that places Computer's ships correctly
void::Computer::placeShips() {
    srand(static_cast<unsigned> (time(0))); // random seed
    char **compBoard = board.getGrid(); // get appropriate players board for ships
    int t = 0; // used for randomizing
    int size = 10000; // total number of orientation elements needed for game 

    list<char> orientation; // list for random ship orientations that computer will use 
    stack<char> randRow;  // stack for holding random row choices for computer 
    queue<int> randCol;   // queue for holding random column choices for computer 

    randRow = getRandRows();  // function call to get random stack values
    randCol = getRandCols();  // function call to get random queue values 

    makeRandOrientation(size, orientation);  // function call to fill list with random orientations 

    std::list<char>::iterator it = orientation.begin(); // iterator for list 

    char direction = *it; // de-reference iterator 

    // Randomize by incrementing and popping 
    while (t < randomChoice) {
        randRow.pop();
        randCol.pop();
       // it++;
        t++;
    }

    // Place all 5 ships 
    for (int i = 0; i < 5; i++) {
        char r = randRow.top();
        int y = randCol.front();
      
        randRow.pop(); // pop off value after using
        randCol.pop(); // pop off value after assignment 
        it++;          // increase iterator 
        int x;          // var for row as integer value
      
        // 2D map with pair of integers and characters as values
        // Key maps to ships length and board symbol
        map<int, pair<int, char>> &itr = Computer::ship.getShips();
        
        // 2D map with pair of string and characters as values
        // Key maps to ships name and orientation on the board
        map<int, pair<string, char>> &itr2 = Computer::ship.getShipNO();

        cout << "\nPlacing " << itr2[i].first << " length " << itr[i].first << " ship.\n";
       // cin >> r>>y;
        r = toupper(r); // Make char uppercase
        x = r - 'A';    // Make char into integer value for board 
        y = y;          

        // Input validation for computer
        // Keep prompting until a valid input is provided
        while (true) {
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
        // Input validation so input is within board size 
        while (x < 0 || x >= 10 || y < 0 || y > 10) {
            r = randRow.top(); // get random row choice from stack
            y = randCol.front(); // get random column choice from queue
          
            randRow.pop();  // pop off value after assignment
            randCol.pop();  // pop off vlaue after assignment 
            it++;           // increase iterator to next element
            //cin >> r>>y;
            r = toupper(r); // make uppercase
            x = r - 'A';    // make row char into integer 
            y = y;
            direction = toupper(direction); // make sure upper-case 
    // Input validation for making sure computer only chooses horizontal or vertical ship orientations
            while (true) {
                randRow.pop(); // pop off after use
                randCol.pop(); // pop off after use
                it++;           // move iterator to next element
                direction = toupper(direction);  // make sure orientation is uppercase 
                
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
  // Place ships on board as long as computer has chosen valid coordinates, orientation, and is within board size
        while (!(Computer::board.isValidPlacement(compBoard, x, y, direction, itr[i].first))) {
            r = randRow.top(); // get random row from stack
            y = randCol.front();    // get random column from queue
       
            randRow.pop();      // pop value off after assignment
            randCol.pop();      // pop element off after assignment 
            it++;               // increment iterator onto next element
            direction = *it;    // de-reference iterator and assign value to orientation variable 
            // cin >> r>>y;
            r = toupper(r);     // make sure char is uppercase
            x = r - 'A';        // make row char into integer value with 0-9
            y = y;
            //  cout << "Enter direction (H for horizontal, V for vertical): ";
            //  cin >> direction;
            direction = toupper(direction); // make sure upper case 
        }
  // Place ships on board with correct orientation and correct ship length       
        for (int j = 0; j < itr[i].first; j++) {
            if (direction == 'H' || direction == 'h') {
                compBoard[x][y + j] = itr[i].second; // Fill board with correct ship symbol horizontally
                Coordinates::addCoordsToSet(r,y+j);     // Add computer's choices into Coordinate object set
            } else if (direction == 'V' || direction == 'v') {
                compBoard[x + j][y] = itr[i].second; // Fill board with correct ship symbol vertically
                Coordinates::addCoordsToSet(r+j,y); // Add computer's ships coordinates into Coordinate object set
            }
        } // for loop 79
    }// for loop 52
 //   board.displayBoard(); // Display after Computer sets board. Un-comment to see Computer Board
}

// Function that will simulate the computer taking turns with the player. Creates random choices for computer
// and checks board if computer choice was a hit or miss. Updates board with correct symbol accordingly
void::Computer::takeTurns(Player &opponent) {
    // Variables for computer choices: row, column, row as int and ship hits
    int x, y; 
    char r;
    int hits = 0;
    
    // Get the appropriate board to update with symbols: hit, miss, etc
    char **board = opponent.getBoard(); 
    
    // 2D map with ships as key values that returns length and ship symbol
    map<int, pair<int, char>> &itr = Player::ship.getShips();
    // 2D map with ships as key values that returns ship name and orientation 
    map<int, pair<string, char>> &itr2 = Player::ship.getShipNO();

    stack<char> randRow; // declare stack for random row choices 
    queue<int> randCol; // declare queue for random column choices

    randRow = getRandRows();  // get the stack that generates random rows
    randCol = getRandCols();  // get the queue that generates the random columns

    // Pop off and advance iterator randomly through the containers for more randomization 
    int i = 0;
    while (i < randomChoice) {
        randRow.pop();
        randCol.pop();
        i++;
    }
    // pop off more elements
    randRow.pop();
    randCol.pop();

   // cout << "\nEnter attack coordinates (e.g., A3): "; //TEST - Uncomment to test input
   // cin >> r >> y;  // TEST Uncomment to test input
    r = randRow.top(); // assign random row element to row variable so it can be used in program
    x = r - 'A';        // make the row char into integer for board use
    y = randCol.back(); // get column element from back of queue 
    cout << "Computer attacks: " << r << " " << y; // Output computer's attack choices 

   /* Check if computer attack choices are hit or miss on board
   *  Then update board accordingly to reflect which ship was hit or 
   *  which coordinate was missed with correct symbol(s)
   */
    if (board[x][y] == 'A') { // Check board to see if Aircraft carrier was hit 
        cout << "\nIt's a hit!\n";
        cout<<itr2[4].first<<": length "<<itr[4].first<<" is sunk!"<<endl;
        hits = Player::ship.Hits(); // update ship hits
        for(int i=0; i<B_SIZE; i++){
            for(int j=0; j<B_SIZE; j++){
                if(board[i][j] == 'A'){ // If coordinate has ship update with hit
                   board[i][j]='X';
                }
            }
        }
    } else if (board[x][y] == 'B') { // Check board to see if Battleship was hit 
        cout << "\nIt's a hit!\n";
        cout<<itr2[3].first<<": length "<<itr[3].first<<" is sunk!"<<endl;
        hits = Player::ship.Hits(); // update ship hits
        for(int i=0; i<B_SIZE; i++){
            for(int j=0; j<B_SIZE; j++){
                if(board[i][j] == 'B'){ // If coordinate has ship update with hit
                    board[i][j]='X';
                }
            }
        } 
    } else if (board[x][y] == 'C') { // Check board to see if Carrier was hit 
        cout << "\nIt's a hit!\n";
        cout<<itr2[2].first<<": length "<<itr[2].first<<" is sunk!"<<endl;
        hits = Player::ship.Hits(); // update ship hits
        for(int i=0; i<B_SIZE; i++){
            for(int j=0; j<B_SIZE; j++){
                if(board[i][j] == 'C'){ // If coordinate has ship update with hit
                    board[i][j]='X';
                }
            }
        }
    } else if (board[x][y] == 'D') { // Check board to see if Destroyer was hit
        cout << "\nIt's a hit!\n";
         cout<<itr2[0].first<<": length "<<itr[0].first<<" is sunk!"<<endl;
         hits = Player::ship.Hits();  // update ship hits
           for(int i=0; i<B_SIZE; i++){
            for(int j=0; j<B_SIZE; j++){
                if(board[i][j] == 'D'){ // If coordinate has ship update with hit
                    board[i][j]='X';
                }
            }
        }
    } else if (board[x][y] == 'S') { // Check board to see if Submarine was hit
        cout << "\nIt's a hit!\n";
        cout<<itr2[1].first<<": length "<<itr[1].first<<" is sunk!"<<endl;
        hits = Player::ship.Hits();  // update ship hits
        for(int i=0; i<B_SIZE; i++){
            for(int j=0; j<B_SIZE; j++){
                if(board[i][j] == 'S'){ // If coordinate has ship update with hit
                    board[i][j]='X';
                }
            }
        }
    } else if (board[x][y] == '~') { // Coordinate has no ship  
        cout << "\nIt's a miss.\n";
        board[x][y] = 'O';          // Update with miss symbol
    }
   // opponent.display(board);
}
