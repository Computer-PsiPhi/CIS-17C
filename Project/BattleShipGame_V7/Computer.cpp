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

void Computer::makeRandOrientation(int l, list<char>& list) {
    srand(static_cast<unsigned> (time(0)));
    forward_list<char> fList;

    for (int i = 0; i < l; ++i) {
        char direction = (rand() % 2 == 0) ? 'H' : 'V';
        fList.push_front((rand() % 2 == 0) ? 'H' : 'V');
    }
    // Merge two list
    merge(list.begin(), list.end(), fList.begin(), fList.end(), back_inserter(list));

   // std::list<char>::iterator it = list.begin();
   // cout << "First Element: " << *it << "\n";
    //
    //    // Move iterator to the second element
    //    it++;
    //    cout << "Second Element: " << *it << "\n";     
}
// Get random rows from a queue for computer 

queue<int> Computer::getRandCols() {

    int numElements = 1000;
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

// Get random rows from a stack for computer

stack<char> Computer::getRandRows() {
    int numElements = 1000;

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
        a.push_back(rand() % 10 + 65);
        rw.push(a.front());
        rw.push(*it);
        rw.push(rand() % 10 + 65);
    }

    return rw;
};

void::Computer::placeShips() {
    srand(static_cast<unsigned> (time(0)));
    char **compBoard = board.getGrid();
    int i = 0;
    int size = 10000;
    
    list<char> orientation;
    stack<char> randRow;
    queue<int> randCol;





    randRow = getRandRows(); //randomRows();
    randCol = getRandCols();

    makeRandOrientation(size, orientation);


    std::list<char>::iterator it = orientation.begin();


    char direction = *it;

    while (i < randomChoice) {
        randRow.pop();
        randCol.pop();
        it++;
        i++;
    }


    //   compBoard[0][0]='P';
    //   cout<<"Line 46 board.display "<<endl;
    //   board.displayBoard();
    //   
    //   cout<<"line48 Computer::boad.display "<<endl;
    //   Computer::board.displayBoard();
    //   
    for (int i = 0; i < 5; i++) {
       // board.displayBoard();
        char r = randRow.top();

        int y = randCol.front();
     //   cout << "\nrow is " << r << endl;
       // cout << "col is " << y << endl;
        randRow.pop();
        randCol.pop();
        it++;
        int x; // y;
        // char r;
        // r = direction;
     //   cout << "in while " << direction << endl;

        map<int, pair<int, char>> &itr = Computer::ship.getShips();
        map<int, pair<string, char>> &itr2 = Computer::ship.getShipNO();

        // map<int, pair<int, char>> &itr = s.getShips();
        // map<int, pair<string, char>> &itr2 = s.getShipNO();

        //  display(board);
        //   Computer::board.displayBoard();

        cout << endl;
        cout << "\nPlacing " << itr2[i].first << " length " << itr[i].first << " ship.\n";

    //    cout << "\nEnter starting coordinates (e.g., A3): ";

        // cin >> r>>y;
        r = toupper(r);
        x = r - 'A';
       // cout << "x is: " << x << endl;
        y = y;
     //   cout << "y is " << y << endl;

        // Keep prompting until a valid input is provided
        while (true) {

          //  cout << "in while " << direction << endl;
         //   cout << "Enter direction (H for horizontal, V for vertical): ";
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
//            cout << "\nrow is " << r << endl;
//            cout << "col is " << y << endl;
            randRow.pop();
            randCol.pop();
            it++;



//            cout << "\nINVALID PLACEMENT! " << endl;
//            cout << "Re-enter starting coordinates for ";
//            cout << itr2[i].first << " length " << itr[i].first << " ship.\n";

            //cin >> r>>y;
            r = toupper(r);

            x = r - 'A';
         //   cout << "x is: " << x << endl;
            y = y;
//            cout << "y is " << y << endl;
//            cout << "Enter direction (H for horizontal, V for vertical): ";
            //  cin >> direction;
            direction = toupper(direction);

            while (true) {
                randRow.pop();
                randCol.pop();
                it++;
           //     cout << "Enter direction (H for horizontal, V for vertical): ";
                //   cin >> direction;
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

    board.displayBoard();
    cout<<endl;


}

void::Computer::takeTurns(Player &opponent) {
    int x, y;
    char r;
    int hits = 0;
    char **board = Computer::board.getGrid();
    
    //char **board = opponent.board.getGrid();
    board[0][0] = 'K';

   Computer::board.displayBoard();
   cout<<endl;
    // opponent.board.displayBoard();

    //Player::ship.Hits();
  //  do {
        cout<<"\nIn computr turn fucn line 328: "<<endl;
      //  Computer::board.displayBoard();
        
      //  cout<<"IN computer take turn func "<<endl;
       // int size = 10000;
     
       // list<char> orientation;
        stack<char> randRow;
        queue<int> randCol;


        randRow = getRandRows(); //randomRows();
        randCol = getRandCols();
        
        int i=0;
        while ( i < randomChoice) {
        randRow.pop();
        randCol.pop();
        i++;
        }
 randRow.pop();
        randCol.pop();
        //makeRandOrientation(size, orientation);


       // std::list<char>::iterator it = orientation.begin();


       // char direction = *it;
        
         r = randRow.top();

        y = randCol.front();
      //  cout << "\nrow is " << r << endl;
      //  cout << "col is " << y << endl;
       
      //  it++;
        cout<<endl;
       cout << "\nEnter attack coordinates (e.g., A3): ";

      //  cin >> r >> y;
 cout << "Computer attack " <<  r <<" " << y << ". ";
        x = r - 'A';
        y = y;

//        cout << "x is: " << x ;
//        cout << " y is " << y << endl;


    //} while (board[x][y] == 'O' || board[x][y] == 'O');
   

    if (board[x][y] == 'A') {
        cout << "\nIt's a hit!\n";
        hits = Player::ship.Hits();
        //opponent.ship.isShipAtCoord(i,r,y) = 'X';
       // Computer::board.getGrid();
    } else if (board[x][y] == 'B') {
        cout << "\nIt's a hit!\n";
        board[x][y] = 'X';
        hits = Player::ship.Hits();
       // Computer::board.displayBoard();
    } else if (board[x][y] == 'C') {
        cout << "\nIt's a hit!\n";
        board[x][y] = 'X';
        hits = Player::ship.Hits();
    } else if (board[x][y] == 'D') {
        cout << "\nIt's a hit!\n";
        board[x][y] = 'X';
        hits = Player::ship.Hits();
       // Computer::board.displayBoard();
        //opponent.board.displayBoard();
    } else if (board[x][y] == 'S') {
        cout << "\nIt's a hit!\n";
        board[x][y] = 'X';
        hits = Player::ship.Hits();
      //  Computer::board.displayBoard();
        //  opponent.board.displayBoard();
    } else if (board[x][y] == '~') {
        cout << "\nIt's a miss.\n";
        board[x][y] = 'O';
       // Computer::board.displayBoard();
        // opponent.board.displayBoard();
    }
  //  } while (board[x][y] == '~' || board[x][y] == '~');
    
    cout<<endl;
    Computer::board.displayBoard();
}