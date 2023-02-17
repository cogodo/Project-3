/*
 * test.cpp
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

void testRemoveDuplicate();
void testRemoveNonAlphas();
void startTests() {

    testRemoveNonAlphas();
    testRemoveDuplicate();
    // Repeat for all other functions to be tested

    return;
}


void  testRemoveNonAlphas() {
    cout << "Now testing function RemoveNonAlphas()" << endl;
    cout << "Expected: 'abc', Actual: '" << removeNonAlphas("a1b2c3 ") << "'" << endl;
    cout << "Expected: '', Actual: '" << removeNonAlphas("1234567  ") << "'" << endl;
    cout << "Expected: 'xylophone', Actual: '" << removeNonAlphas("xylophone") << "'" << endl;
    
    return;
}

void testRemoveDuplicate() {
    cout << "Now testing function RemoveDuplicate()" << endl;
    cout << "Expected: 'abc', Actual: '" << removeDuplicate("aabbcc") << "'" << endl;
    cout << "Expected: '805', Actual: '" << removeDuplicate("80085") << "'" << endl;
    cout << "Expected: ' 1an', Actual: '" << removeDuplicate(" 1aa1nn ") << "'" << endl;
    return;
}
