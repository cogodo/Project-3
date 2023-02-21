/*
 * caesar.cpp
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

#include "caesar.h"
#include <iostream>

char shiftAlphaCharacter(char c, int n) {
    string lowerAlphabet = "abcdefghijklmnopqrstuvwxyz";
    string upperAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char newChar = ' ';
    if(islower(c)) {
        for(int i = 0; i < 26; i++) {
            if(c == lowerAlphabet.at(i)) {
                if(n < 0) {
                    newChar = lowerAlphabet.at(26 - (abs(n + i) % 26));
                    break;
                }
                newChar = lowerAlphabet.at((n + i) % 26);
                break;
            }
        }
    }
    if(isupper(c)) {
        for(int i = 0; i < 26; i++) {
            if(c == upperAlphabet.at(i)) {
                if(n < 0) {
                    newChar = upperAlphabet.at(26 - (abs(n + i) % 26));
                    break;
                }
                newChar = upperAlphabet.at((n + i) % 26);
                break;
            }
        }
    }
   
    return newChar;
}

string caesarCipher(string original, int key, bool encrypt) {
    
    if(encrypt == true) {
        for(int i = 0; i < original.length(); i++) {
            if(isalpha(original.at(i))) {
                original.at(i) = shiftAlphaCharacter(original.at(i), key);
            }
        }
    }
    if(encrypt == false) {
        for(int j = 0; j < original.length(); j++) {
            if(isalpha(original.at(j))) {
                original.at(j) = shiftAlphaCharacter(original.at(j), (26 - (key % 26)));
            }
        }
    }
   
    return original;
}
