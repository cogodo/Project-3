/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Colin Gordon, Lee Fingar-Myers
 * cogo, leefm
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * The main program that displays choice selections. Specifically which cipher, whether to encrypt or decrypt, message, key, and encrypted message.
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>


using namespace std;

void ciphers() {
    
    
    string empty = "";
    string cipher = "";
    bool direction = "";
    string message = "";
    string keyword = "";
    string finalMessage = "";
    string encrypt = "";
    int key = 0;
    // ask user for cipher (Caesar, Vigenere, or Polybius)
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    cin >> cipher;
    cipher = toUpperCase(cipher);
    if(cipher != "CAESAR" && cipher != "C") {
        if(cipher != "VIGENERE" && cipher != "V") {
            if(cipher != "POLYBIUS" && cipher != "P") {
                cout << endl << "Invalid cipher!";
                return;
            }
            
        }
    }
    
    // ask user to encrypt or decrypt
    cout << endl << "Encrypt or decrypt: ";
    cin >> encrypt;
    getline(cin, empty);
    encrypt = toUpperCase(encrypt);
    if(encrypt == "ENCRYPT" || encrypt == "E") {
        direction = true;
    }
    else if(encrypt == "DECRYPT" || encrypt == "D") {
        direction = false;
    }
    else {
        cout << endl << "Invalid mode!";
        return;
    }
    // get message from user
    cout << endl << "Enter a message: ";
    getline(cin, message);
    if(cipher == "POLYBIUS" || cipher == "P") {
        for(int i = 0; i < message.length(); i++) {
            if(!isalnum(message.at(i)) && !isspace(message.at(i))) {
                cout << "Invalid message!";
                return;
            }
            if(toupper(message.at(i)) != message.at(i)) {
                cout << "Invalid message!";
                return;
            }
        }
    }
    // get key or keyword from user
    cout << endl << "What is your key: ";
    getline(cin, keyword);
    if(cipher == "CAESAR" || cipher == "C") {
        for(int k = 0; k < keyword.length();) {
            if(isdigit(keyword.at(k))) {
                k++;
            }
            else {
                cout << "Invalid key!";
                return;
            }
        }
        for(int l = 0; l < keyword.length(); l++) {
            key = key + (charToInt(keyword.at(l)));
        }
        key = stoi(keyword);
    }
    else {
        if(cipher == "VIGENERE" || cipher == "V") {
            int count = 0;
            int j = 0;
            for(j = 0; j < keyword.length(); j++) {
                if(!isalpha(keyword.at(j))) {
                    count++;
                }
            }
            if(count == j) {
                cout << "Invalid key!";
                return;
            }
        }
        if(cipher == "POLYBIUS" || cipher == "P") {
            for(int i = 0; i < keyword.length(); i++) {
                if(!isalnum(keyword.at(i))) {
                    cout << "Invalid key!";
                    return;
                }
                if(toupper(keyword.at(i)) != keyword.at(i)) {
                    cout << "Invalid key!";
                    return;
                }
                string testKey = removeDuplicate(keyword);
                if(keyword != testKey) {
                    cout << "Invalid key!";
                    return;
                }
            }
        }
    }
    
        // encrypt or decrypt message using selected cipher and key(word)
        cout << endl;
        if(cipher == "CAESAR" || cipher == "C") {
            finalMessage = caesarCipher(message, key, direction);
        }
        if(cipher == "VIGENERE" || cipher == "V") {
            finalMessage = vigenereCipher(message, keyword, direction);
        }
        if(cipher == "POLYBIUS" || cipher == "P") {
            char grid[6][6];
            fillGrid(grid, ALNUM);
            finalMessage = polybiusSquare(grid, keyword, message, direction);
        }
        // print encrypted/decrypted message
        
        if(!direction) {
            cout << "The decrypted message is: " << finalMessage;
        }
        else {
            cout << "The encrypted message is: " << finalMessage;
        }
        return;
    }
