/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * <#Names#>Colin Gordon, Lee Fingar-Myers
 * <#Uniqnames#>cogo, leefm
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * <#description#>
 */

#include "utility.h"
#include <iostream>


string toUpperCase(string original) {
    // TODO: implement
    for(int i = 0; i < original.length(); i++) {
        original[i] = toupper(original[i]);
    }
    // returning a string to avoid compile error
    return original;
}

string removeNonAlphas(string original) {
    // TODO: implement
    string newString;
        for(int i = 0; i < original.length();) {
            if(isalpha(original.at(i))) {
                newString.append(1, original.at(i));
                i++;
            }
            else {
                newString.append("");
                i++;
            }
    }
    // returning a string to avoid compile error
    return newString;
}


string removeDuplicate(string original) {
    // TODO: implement
    string extra = original;
        for(int i = 0; i < original.length(); i++) {
        char temp = original.at(i);
        for(int x = i + 1; x < original.length() - i; ++x) {
            if(temp == original.at(x)) {
                extra.erase(x, 1);
            }
        }
    }

    // returning a string to avoid compile error
    return extra;
}


int charToInt(char original) {
    // TODO: implement
    int newVal = static_cast<int>(original);

    // returning 0 to avoid compile error
    return newVal;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
