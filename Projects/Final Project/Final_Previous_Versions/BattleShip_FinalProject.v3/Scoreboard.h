/* 
 * File:   Scoreboard.h
 * Author: Noel Perez
 * Created on December 6, 2023, 7:30 PM
 */

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <string>
#include <iomanip>
#include <algorithm>
#include <iostream>

using namespace std;

const int NUM_PLAYERS = 26; // max number of players in scoreboard 

class Scoreboard {
private:
    string players[NUM_PLAYERS]; // array of strings for players
    int scores[NUM_PLAYERS];    // array of integers for player's scores
    int currentSize;           // size variable in case more players are added 


public:
    Scoreboard(); // default constructor 

    // 3 parameter constructor 
    Scoreboard(const string names[], const int values[], int size);

    // Print scoreboard object 
    void displayScores() const;

    // MergeSort auxiliary function that does the merge: used to alphabetically sort player names
    void merge(string names[], int scores[], int low, int mid, int high);

    // Recursive MergeSort Function 
    void mergeSort(string names[], int scores[], int low, int high);

    // Helper function to call merge sort 
    void sortScores();

    // Destructor 
    virtual ~Scoreboard();
};

#endif /* SCOREBOARD_H */

