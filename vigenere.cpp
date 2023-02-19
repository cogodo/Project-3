/*
 * vigenere.cpp
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
#include "caesar.h"
#include "vigenere.h"
#include <iostream>

string vigenereCipher(string original, string keyword, bool encrypt) {
    string message = original;
    string alterKeyword = removeNonAlphas(keyword);
    string upperAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int p;
    int keyCharNum = 0;

    alterKeyword = toUpperCase(alterKeyword);
    
// Creating keyword chain
    string key = "";
    for(int k = 0; k < message.length(); k++) {
       
            key.append(1, alterKeyword.at(k % alterKeyword.length()));
        
    }
    for(int a = 0; a < message.length(); a++) {
        if(isalpha(message.at(a)) == false) {
            key.insert(a, " ");
          
        }
    }
    
    if(encrypt == true) {
        for(int i = 0; i < message.length(); i++) {
            if(isalpha(message.at(i))) {
                for(p = 0; p < 26; p++) {
                    if(key.at(i) == upperAlphabet.at(p)) {
                        keyCharNum = p;
                        break;
                    }
                }
                message.at(i) = shiftAlphaCharacter(message.at(i), keyCharNum);
            }
        }
    }
    if(encrypt == false) {
        for(int j = 0; j < message.length(); j++) {
            if(isalpha(message.at(j))) {
                for(p = 0; p < 26; p++) {
                    if(key.at(j) == upperAlphabet.at(p)) {
                        keyCharNum = p;
                        break;
                    }
                }
                message.at(j) = shiftAlphaCharacter(message.at(j), (26 - keyCharNum));
            }
        }
    }

    return message;
}
