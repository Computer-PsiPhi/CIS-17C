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

void clearScreen(){
cout << "\033c";
}

void clearScreenChoice(){
    char choice = 0;
    cout<<"\n";
cout << "Do you want to clear screen(Y/N)?"<<endl;
cin>>choice;
choice = toupper(choice);

if (choice == 'Y')
{
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

    // Display the rules in stored in a .txt file 
    for (const char& words : text) {
      //  cout << words;
    }
    cout << '\n';

    clearScreenChoice();
    
    Game game;
    
    game.setupGame();
  
   //  clearScreen();
    game.playGame();
    
    
   
   
   // cout<<"hits "<<h;
//   char** playerGrid = bo.getGrid();
   
   int a=1;
   int b=2;
   char c='V';
   int d =3;
   

   
//   cout<<boolalpha;
//   // char Grid[][B_SIZE], int r, int c ,char o, int size
//  cout<< bo.isValidPlacement(playerGrid , a, b, c, d);
//  
 // p.placeShips();
  
 // p.display(playerGrid);
// p.takeTurns(comp);
  
  //bo.displayBoard();
  
 // comp.takeTurns(p);
//  comp.placeShips();
//  comp.takeTurns(p);
//  comp.takeTurns(p);
//  
  

    // Create a Coordinate object
   // Coordinates myCoordinate;
//    myCoordinate.addCoordsToSet('A',9);
//    myCoordinate.addCoordsToSet('J',5); 
    
//    Coordinates coords[5];
//    
//    
//    for(int i =0; i <1; i++){
//        coords[i].getUserInput();
//       // cout<<coords[i].getCol()<<endl;
//    }
//
//    
//        char a[5];
//      int i = 0; 
//    // Get all rows and print them
//    set<char> allRows = Coordinates::getAllRows();
//    
//    cout << "All Rows: ";
//    for (set<char>::iterator it = allRows.begin(); it != allRows.end(); ++it) {
//       cout << *it << " ";
//      
//     a[i] = *it;//
//     
//       //  cout<<"rray: ["<<a[i]<<"]"<<endl;
//        
//                i++;
//               
//    }
//    cout << "\n";
//    
//        // Get all columns and print them
//    set<int> allColumns = Coordinates::getAllColumns();
//    cout << "All Columns: ";
//    for (set<int>::iterator it = allColumns.begin(); it != allColumns.end(); ++it) {
//        cout << *it << " ";
//    }
//    cout << "\n";
//    
////
//
//   Coordinates anotherCoordinate('A', 7);
////
////
//
////    cout << "All Coordinates: ";
////    Coordinates::printCoords();
////
//// //    Check if specific coordinates are present
////    set<pair<char, int>> checkCoords;
////    checkCoords.insert(make_pair('A', 4));
////    checkCoords.insert(make_pair('A', 9));
////
////    cout << "Coordinates {'A', 4} and {'A', 9} are ";
////    if (anotherCoordinate.inputInSet('A',7)) {
////        cout << "present in the set.\n";
////    } else {
////        cout << "not present in the set.\n";
////    }
////
////    // Add coordinates to the set without creating an object
////    Coordinates::addCoordsToSet('B', 3);
////    Coordinates::addCoordsToSet('C', 7);
////
////    // Print all coordinates after adding 
////    cout << "All Coordinates after adding without an object: ";
////    Coordinates::printCoords();
////
////    // Get the first and second coordinates in the set
////    pair<char,int> arry[5] = {Coordinates::getFirstCoord()};
////    
////    for(int i=0; i<2; i++){
////        cout<<"array[] "<<arry[i].first;
////    }
////    
//////    pair<char, int> firstCoord= Coordinates::getFirstCoord();
//////    pair<char, int> secondCoord = Coordinates::getSecondCoord();
//////
//////    cout << "First Coordinate in the set: (" << firstCoord.first << ", " << firstCoord.second << ")\n";
//////    cout << "Second Coordinate in the set: (" << secondCoord.first << ", " << secondCoord.second << ")\n";
//////
//////   
////      //  Coordinates::getUserInput();
////       // Coordinates::getUserInput();
////
////        // Print 
//////        cout << "All Coordinates after adding user input: ";
//////        Coordinates::printCoords();
//////        
////        for (set<pair<char, int>>::iterator it = myCoordinate.getAllCoords().begin(); it != myCoordinate.getAllCoords().end(); ++it) {
////            cout<< "108: ( " << it->first << ", " << it->second << ") ";
////            
////              //  cout<<" FOUND! "<<endl;
////        }
////        cout << "\n";
////    
////     char userRow;
////    int userCol;
////    cout << "Enter row : ";
////    cin >> userRow;
////    cout << "Enter col: ";
////    cin >> userCol;
////
////    if (Coordinates::inputInSet(userRow, userCol)) {
////        cout << "Entered coordinates are present in the set.\n";
////    } else {
////        cout << "Entered coordinates are not present in the set.\n";
////    }
//
//    
//   
//    
//    //s1[0].setPostion();
//     
//      
//      Ship s;
//     
//      
//     
//      
//     // s.setPostion();
//      
//     // s.insertCoordinate(1,'T',5);
//     
//      s.addToMapNO(4,'V');
//      
//   //    map<int, pair<Coordinates, Coordinates::CompareCoordinates>> &shipItr = s.getShipMap();
//     
//       
////    unordered_map<int, set<pair<char, int>>>& shipCoords = s.getShipCoords();
////    shipCoords[3].insert(make_pair('A', 6));
////    shipCoords[3].insert(make_pair('B', 6));
////      shipCoords[3].insert(make_pair('C', 6));
////    shipCoords[3].insert(make_pair('D', 6));
////    
////    shipCoords[4].insert(make_pair('A', 1));
////    shipCoords[4].insert(make_pair('A', 2));
////     shipCoords[4].insert(make_pair('A', 3));
////    shipCoords[4].insert(make_pair('A', 4));
////    shipCoords[4].insert(make_pair('A', 5));
////   
////    
//    
//   
//    cout<<endl;
//       
// 
//      
//      unordered_map<int,set<pair<char, int>> > &sIt = s.getShipCoords();
//      
//  
//      
//
//      
//       s.printShipCoords();
//      // map for <size,symbol>
//     map<int, pair<int, char>> &itr = s.getShips();
//      
//      // map for <string name, char orientation>;
//      map<int, pair<string,char>> &iter =s.getShipNO();
//      iter[0].second='H';
//    //  it[0].first = 'J';
//     // it[0].second=5;
//    //  it[0].first = 'J';
//     // it[0].second = 6;
//      cout<<" name: "<<iter[0].first<<" orientation "<<iter[0].second;
//      cout<<" Size "<<itr[0].first<<" symbol: "<<itr[0].second;
//    
//    
//  
//    
//       
//  
//   
//     
//           cout << "Ship Information:" << endl;
//    for (int i = 0; i < itr[i].first; ++i) {
//        itr[i];
//     //   int shipKey = i;
//        int shipSize = itr[i].first;
//        char shipCharacter = itr[i].second;
//        
//    }
//
//           if(iter[4].second == 'V'){
//               cout<<"Orientation is "<<iter[4].second<<endl;
//           }
//           
////    char l = itr[0].second;
////
////    cout<<"c is "<<l-'A'<<endl;
////    
//    Coordinates::addCoordsToSet('J',3);
//    Coordinates::printCoords();
//    
//      int c;
//           char r;
//    
////         for(int i=0; i<1; i++){
////         
////           cout<<"Enter row ";
////           cin>>r;
////           cout<<"Enter column: ";
////           cin>>c;
////            if (Coordinates::inputInSet(r, c)) {
////        cout << "Entered coordinates are present in the set.\n";
////    } else {
////        cout << "Entered coordinates are not present in the set.\n";
////    }
////    
////       }
////    
//            Coordinates::printCoords();
//    
//    if (Coordinates::inputInSet(r, c)) {
//        cout << "Entered coordinates are present in the set.\n";
//    } else {
//        cout << "Entered coordinates are not present in the set.\n";
//    }
//    
////    for (set<pair<char, int>, Coordinates::CompareCoordinates>::iterator it = Ship::getAllShipCoords().begin(); it != Ship::getAllShipCoords().end(); ++it) {
////        cout << "(" << it->first << ", " << it->second << ") ";
////    }
////    cout << "\n";
////  
//            s.getShipName(4);
//
//    //s.displayMap(s.getShips());
//    cout<<"after line 178 ";
// 
//    s.displayMapNO(s.getShipNO());
//   
//    //Aircraft Carrier (occupies 5 spaces), Battleship (4), Cruiser (3), Submarine (3), and Destroyer (2).  
//    cout<<itr[0].first<<endl;
//    s.insertCoord(0, 'A', 3,itr[0].first);
//    s.insertCoord(0, 'A', 4,itr[0].first);
//      s.insertCoord(0, 'A', 5,itr[0].first);
//      
//    s.insertCoord(2, 'R', 9, itr[2].first);
//    s.insertCoord(2, 'Q', 9, itr[2].first);
//    s.insertCoord(2, 'S', 9, itr[2].first);
//    s.insertCoord(2, 'T', 3, itr[2].first); // Adding another coordinate to key 2
//    
//      s.insertCoord(3, 'W', 5, itr[3].first);
//     s.insertCoord(3, 'F', 5, itr[3].first);
//    s.insertCoord(3, 'B', 5, itr[3].first);
//    s.insertCoord(3, 'C', 5, itr[3].first);
//    s.insertCoord(3, 'D', 5, itr[3].first); // Adding another coordinate to key 2
//
// s.insertCoord(1, 'Z', 9, itr[1].first);
//    s.insertCoord(1, 'Z', 10, itr[1].first);
//    s.insertCoord(1, 'Z', 19, itr[1].first);
//    s.insertCoord(1, 'Z', 13, itr[1].first); // Adding another coordinate to key 2

   // Ship s;
//  s.printShipCoords();
//   
//    cout<<"line 294"<<endl;
//    
//    Ship* shipPtr = &s;
//    unordered_map<int, set<pair<char, int>>>* shipCoordsPtr = &shipPtr->getShipCoords();
//
//    for (unordered_map<int, set<pair<char, int>>>::iterator iter = shipCoordsPtr->begin(); iter != shipCoordsPtr->end(); ++iter) {
//        int key = iter->first;
//        set<pair<char, int>>* coordinatesSetPtr = &iter->second;
//
//        cout << "Ship: " << s.getShipName(key) << " Coordinates: ";
//        for (set<pair<char, int>>::iterator coordIter = coordinatesSetPtr->begin(); coordIter != coordinatesSetPtr->end(); ++coordIter) {
//            cout << "(" << coordIter->first << ", " << coordIter->second << ") ";
//        }
//        cout << "\n";
//    }
//// 
//  
    return 0;
}

