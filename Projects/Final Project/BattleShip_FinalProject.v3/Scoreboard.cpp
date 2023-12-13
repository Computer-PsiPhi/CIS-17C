/* 
 * File:   Scoreboard.cpp
 * Author: Noel Perez
 * Created on December 6, 2023, 7:30 PM
 */

#include "Scoreboard.h"

Scoreboard::Scoreboard() {
};

Scoreboard::Scoreboard(const string names[], const int values[], int size) {

    currentSize = size;
    for (int i = 0; i < size; ++i) {
        players[i] = names[i];
        scores[i] = values[i];
    }

}

Scoreboard::~Scoreboard() {
};

void::Scoreboard::displayScores() const {

    int maxPW = 0;
    int maxSW = 0;

    // maximum widths for player names and scores
    for (int i = 0; i < currentSize; ++i) {
        if (players[i].length() > maxPW) {
            maxPW = players[i].length();
        }
        int scoreWidth = to_string(scores[i]).length();
        if (scoreWidth > maxSW) {
            maxSW = scoreWidth;
        }
    }

    // table padding
    const int padding = 5; // Padding between columns
    int totalW = maxPW + maxSW + padding;

    // table header
    cout << endl;
    cout << setw(maxPW + 24) << right << "Player" << setw(padding + 20) << right << setw(30) << " Score" << endl;
    cout << string(90, '-') << setw(totalW + 22) << setfill(' ') << endl;

    // Display player names and scores
    for (int i = 0; i < currentSize; ++i) {
        cout << setw(maxPW + 24) << right << players[i] << setw(padding + 10) << right << " " << setw(maxSW + 10) << right << scores[i] << endl;
    }
}

void::Scoreboard::merge(string names[], int scores[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    string leftNames[n1];
    string rightNames[n2];
    int leftScores[n1];
    int rightScores[n2];

    for (int i = 0; i < n1; i++) {
        leftNames[i] = names[low + i];
        leftScores[i] = scores[low + i];
    }
    for (int j = 0; j < n2; j++) {
        rightNames[j] = names[mid + 1 + j];
        rightScores[j] = scores[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (leftNames[i] <= rightNames[j]) {
            names[k] = leftNames[i];
            scores[k] = leftScores[i];
            ++i;
        } else {
            names[k] = rightNames[j];
            scores[k] = rightScores[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        names[k] = leftNames[i];
        scores[k] = leftScores[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        names[k] = rightNames[j];
        scores[k] = rightScores[j];
        ++j;
        ++k;
    }
}

void::Scoreboard::mergeSort(string names[], int scores[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(names, scores, low, mid);
        mergeSort(names, scores, mid + 1, high);
        merge(names, scores, low, mid, high);
    }
}

void::Scoreboard::sortScores() {
    mergeSort(players, scores, 0, currentSize - 1);
}
