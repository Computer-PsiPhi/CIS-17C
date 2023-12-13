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

const int NUM_PLAYERS = 26;

class Scoreboard {
private:
    string players[NUM_PLAYERS];
    int scores[NUM_PLAYERS];
    int currentSize;


public:
    Scoreboard();

    Scoreboard(const string names[], const int values[], int size);

    void displayScores() const;

    void merge(string names[], int scores[], int low, int mid, int high);

    void mergeSort(string names[], int scores[], int low, int high);

    void sortScores();

    virtual ~Scoreboard();
};

#endif /* SCOREBOARD_H */

