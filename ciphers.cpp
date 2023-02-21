/*
 * ciphers.cpp
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
#include "polybius.h"
#include <iostream>
#include <string>


using namespace std;

void ciphers() {
    

    
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
    cin >> message;
    // get key or keyword from user
    cout << endl << "What is your key: ";
    if(cipher == "CAESAR" || cipher == "C") {
        cin >> key;
    }
    else {
        cin >> keyword;
        
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
  
    if(direction == false) {
        cout << "The decrypted message is: " << finalMessage << endl;
    }
    else {
        cout << "The encrypted message is: " << finalMessage << endl;
    }
    return;
}
