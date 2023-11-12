/* File:   Computer.cpp
 * Author: Noel Perez
 * Created on November 1, 2023, 6:34 PM
 */
#include "Computer.h"

Computer::Computer() {
}

Computer::Computer(const Computer& orig) {
}

Computer::~Computer() {
}

void Computer::makeRandOrientation(int l, list<char>& list){
        srand(static_cast<unsigned>(time(0)));
        forward_list<char> fList;
        
    for (int i = 0; i < l; ++i) {
        char direction = (rand() % 2 == 0) ? 'H' : 'V';
        fList.push_front((rand() % 2 == 0) ? 'H' : 'V');
    }
    // Merge two list
    merge(list.begin(), list.end(), fList.begin(), fList.end(), list.begin());
        
    forward_list<char>::iterator it = fList.begin();
    cout << "First Element: " << *it << "\n";

    // Move iterator to the second element
    it++;
    cout << "Second Element: " << *it << "\n";     
 
}

queue<int> Computer::getRandCols(){
   
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

stack<char> Computer::getRandRows(){
        int numElements=1000;

        stack<char> rw;// = new stack<char>();
        stack<char> s;// = new stack<char>();
        list<char> a; 
        list<char> otherList;
        list<char>::reverse_iterator it;     
        char data[] = {'A','B','C','D','E','F','G','H','I','J'};
        
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
       rw.push(rand()%10+65);
      }
             
    return rw;
};