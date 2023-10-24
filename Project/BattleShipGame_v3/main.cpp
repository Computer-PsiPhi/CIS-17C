
/* 
 * File:   main.cpp
 * Author: 
 * Created on August 21, 2023, 5:46 PM
 */
#include <stack>
#include <ctime>
#include <list>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;

#include "Board.h"

queue<int> randomColumns(){
    
    int numElements=1000;
    
    queue<int> qCol;
    
    queue<int> q;
    
    set<int> setCol;
    
    int *num = new int[numElements]; 
    
    setCol.find(qCol.front());
    
    set<int>::iterator it;
    
    for(int i =0; i<numElements; i++){
        
       num[i] = rand()%10;
        
       int random = rand()%100;
        
       qCol.push(rand()%10);
       
       setCol.insert(random);
       
       q.push(rand()%10); 
    }
    
    qCol.swap(q);
      
    for(int i =0; i<numElements; i++){
        
        it = find(setCol.begin(), setCol.end(), q.front());
        qCol.push(num[*it]);
        q.pop();
    }
    
    delete []num;
    return qCol;
};

stack<char> randomRows(){

        int numElements=1000;

        stack<char> rw;// = new stack<char>();
        stack<char> s;// = new stack<char>();
        list<char> a; 
        
        list<char>::reverse_iterator it; 
        
        char data[] = {'A','B','C','D','E','F','G','H','I','J'};
        
        list<char> otherList;
        
        copy(data, data+10, inserter(otherList, otherList.begin()));
       
    for (int i = 0; i<numElements; i++){

            char r1 = rand()%10+65;

            char r2 = rand()%10+65;
            
            char r3 = rand()%10+65;
           
            a.push_front(r3);  
        
            s.push(r1);
        
            rw.push(r2);

        while(s.top() == rw.top() ){
            
            if(!s.empty()){
                    s.pop();
                    rw.pop();
                    a.clear();
                    otherList.clear();
            }
            while(otherList.size()<10)
                otherList.push_front(rand()%10+65);
            while( rw.empty() || s.empty()){
                s.push(rand()%10+65);
                rw.push(rand()%10+65);
                a.push_front(rand()%10+65);
                otherList.push_front(rand()%10+65);
            }
        }
    }
        
    for(it = a.rbegin(); it!= a.rend(); it++){
        a.push_back(rand()%10+65);
        rw.push(a.front());
        rw.push(*it); 
       // rw.push(rand()%10+65);
      }
             
    return rw;
};


char *fillOrientation( ){
    
    char *array = new char[100];// = new char[100];
    
    for(int i=0; i < 100; i++){
        if(i%2 == 0)
            array[i]='H';
        else
            array[i]='V';
    }
    
    delete []array;
    
    return array;
}

void clearScreen(){
    
cout << "\033c";

}

void clearScreenChoice(){
    char choice = 0;
    cout<<"\n";
cout << "Do you want to clear screen?"<<endl;
cin>>choice;
choice = toupper(choice);

if (choice == 'Y')
{
cout << "\033c";
}

cout << endl;
}

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));
    
    stack<char> randRow;
    queue<int> randCol;
   
    randRow = randomRows();
    randCol = randomColumns();
    
    char ort[10] = {'H','V','H','V','H','V','H','V','H','V',};
      
    cout<<" Hello can this be cleared ";
 
    clearScreenChoice();

     const int B_SIZE = 10;

    int shipLength[5] = {2,3,3,4,5};
    map<string,int> Map; 
        Map["Ship1"] = 2;
	Map["Ship2"] = 3;
	Map["Ship3"] = 3;
	Map["Ship4"] = 4;
	Map["Ship5"] = 5;
    
     char Grid[B_SIZE][B_SIZE];

   for(int r=0; r<B_SIZE; r++){
        
        for(int c=0; c<B_SIZE; c++){
            Grid[r][c] = '-';
        }
    } // 
     
     

     for (int i = 0 ; i < 5 ; i++){      
       for(int j = 0 ; j < B_SIZE ; j++){
         cout<<setw(5)<<j;
    }
    
    for(int i = 0; i < B_SIZE; i++){
        cout<<"\n";
        cout << static_cast<char>('A' + i) <<"|";
        for(int j = 0; j < B_SIZE; j++){
            cout<<"[ "<<Grid[i][j]<<" ]";       
        }
    }
       
         char row = randRow.top();
        // cout<<"row "<< row<<endl;
        
        int col = randCol.front();
       // cout<<" "<<"col "<<col<<endl;
        randRow.pop();
        randCol.pop();
//        char row;
//        int col;
        char direction=ort[i];

      //  display();
   
        cout << "\n\nPlacing " << shipLength[i] << "-length ship"<<endl;
        
        cout << "Enter starting coordinates (e.g., A3): ";
       
        //char
        cout<<"row "<<row;
        cout<<" col "<<col<<endl;
       // cin >>row >> col;
        
       char x = row - 'A';
       
       int y = col;
      // cout<<"y "<<y<<endl;
           
       cout<<"direction "<<direction<<endl;
       
        cout << "Enter direction (H for horizontal, V for vertical): \n";
      //  cin >> direction;
        

        for(int j = 0 ; j < shipLength[i] ; j++)
        {    
             if((direction == 'V' || direction == 'v')){
                 Grid[x+j][y] = 'S';
            //     // cout<<Grid[x][j+y];
             }
          
            //     Grid[x][y+j] = 'S';
           //  cout<<"y+j: "<<(y+j)<<endl;
                 else if((direction == 'H' || direction == 'h')){
            //  cout<<"x in grid "<<x<<endl;
               // cout<<"y+j in drid: "<<(y+j)<<endl;
                Grid[x][y+j] = 'S';   
            }
        }
    }
     
   //  clearScreen();

    for(int i = 0; i < B_SIZE; i++){
        cout<<"\n";
        
        cout << static_cast<char>('A' + i) <<"|";
        for(int j = 0; j < B_SIZE; j++){

            cout<<"[ "<<Grid[i][j]<<" ]";       
        }
    }
       
     
    return 0;
}

