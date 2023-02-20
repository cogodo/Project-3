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
    
    string keyTemp = removeDuplicate(key);
    keyTemp = toUpperCase(keyTemp);
    string revisedKey = "";
    for (int i = 0; i < keyTemp.length(); i++) {
        if(isalnum(keyTemp.at(i))) {
            revisedKey.append(1, keyTemp.at(i));
        }
    }
    string newList = ALNUM;
    newList.insert(0, revisedKey);
    newList = removeDuplicate(newList);
    
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
    string answer = "";
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(c == grid[i][j]) {
                answer.append(1, static_cast<char>(i + 48));
                answer.append(1, static_cast<char>(j + 48));
                return answer;
            }
        }
    }
    //Stub
    return answer;
}

string polybiusSquare(char grid[SIZE][SIZE], string key, string original, bool encrypt) {
    
    string newKey = mixKey(key);
    string message = "";
    fillGrid(grid, newKey);
    if(encrypt) {
        message = original;
        for(int i = 0; i < message.length(); i++) {
            if(isalpha(message.at(i))) {
                message.replace(i, 1, findInGrid(message.at(i), grid));
            }
        }
    }
    else {
        message = original;
        string messageV2 = "";
        int charCount = 0;
        for(int f = 0; f < original.length(); f++) {
            if(isnumber(message.at(f))) {
                charCount++;
            }
            else {
                charCount = charCount + 2;
            }
        }
        charCount = charCount / 2;
        for(int j = 0; j < message.length() - 1; j++) {
                        if(isnumber(message.at(j))) {
                int row = message.at(j) - 48;
                            
                j++;
                int column = message.at(j) - 48;
                            char letter = char(grid[row][column]);
                            string convert(1, letter);
                messageV2.append(convert);
            }
            
        }
        return messageV2;
    }
    
  // Stub
    return message;
}
