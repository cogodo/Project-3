/*
 * polybius.cpp
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


#include "polybius.h"
#include <string>
using namespace std;

string mixKey(string key) {
    
    removeDuplicate(key);
    string revisedKey = "";
    for (int i = 0; i < key.length(); i++) {
        if(isalnum(key.at(i))) {
            revisedKey.append(key.at(i), 1);
        }
    }
    string newList = ALNUM;
    newList.insert(0, revisedKey);
    removeDuplicate(newList);
    
     //Stub
    return newList;
}

void fillGrid(char grid[SIZE][SIZE], string content) {
    int k = 0;
            for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                grid[i][j] = content[k];
                k++;
        }
    }
    
    return;
}

string findInGrid(char c, char grid[SIZE][SIZE]) {
    
    
    //Stub
    return "";
}

string polybiusSquare(char grid[SIZE][SIZE], string key, string original, bool encrypt) {
    
    
  // Stub
    return "";
}
