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

void testShiftAlphaCharacter();
void testRemoveNonAlphas();
void testCharToInt();
void testRemoveDuplicate();
void testCaesarCipher();
void testVigenereCipher();
void testMixKey();

void startTests() {
    testShiftAlphaCharacter();
    testRemoveNonAlphas();
    testCharToInt();
    testRemoveDuplicate();
    testCaesarCipher();
    testVigenereCipher();
    testMixKey();
    // Repeat for all other functions to be tested

    return;
}

void testShiftAlphaCharacter() {
    cout << "Now testing function ShiftAlphaCharacter()" << endl;
    cout << "Expected: 'a', Actual: '" << shiftAlphaCharacter('a', 0) << "'" << endl;
    cout << "Expected: 'b', Actual: '" << shiftAlphaCharacter('a', 1) << "'" << endl;
    cout << "Expected: 'd', Actual: '" << shiftAlphaCharacter('b', 2) << "'" << endl;
    cout << "Expected: 'c', Actual: '" << shiftAlphaCharacter('z', 3) << "'" << endl;
    cout << "Expected: 'z', Actual: '" << shiftAlphaCharacter('a', -1) << "'" << endl;
    cout << "Expected: 'z', Actual: '" << shiftAlphaCharacter('a', -27) << "'" << endl;
    cout << "Expected: 'b', Actual: '" << shiftAlphaCharacter('a', -103) << "'" << endl;

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
    cout << "Expected: 'ABC', Actual: '" << removeDuplicate("AABBCC") << "'" << endl;
    cout << "Expected: '805', Actual: '" << removeDuplicate("80085") << "'" << endl;
    cout << "Expected: '1AN', Actual: '" << removeDuplicate("1AA1NN") << "'" << endl;
    cout << "Expected: 'A', Actual: '" << removeDuplicate("AAAAAAAAA") << "'" << endl;
    cout << "Expected: 'ASLDF', Actual: '" << removeDuplicate("ASASLSDFDF") << "'" << endl;
    cout << "Expected: 'A', Actual: '" << removeDuplicate("AAA") << "'" << endl;
    return;
}

void testCharToInt() {
    cout << "Now testing function CharToInt()" << endl;
    cout << "Expected: 0, Actual: '" << charToInt('0') << "'" << endl;
    cout << "Expected: 9, Actual: '" << charToInt('9') << "'" << endl;
    cout << "Expected: 1, Actual: '" << charToInt('1') << "'" << endl;
}

void testCaesarCipher() {
    cout << "Now testing function CaesarCipher()" << endl;
    cout << "Expected: 'bananas', Actual: '" << caesarCipher("azmzmzr", 1, true) << "'" << endl;
    cout << "Expected: 'uif gph jt Dpnjoh', Actual: '" << caesarCipher("the fog is Coming", 1, true) << "'" << endl;
    cout << "Expected: 'the fog is Coming', Actual: '" << caesarCipher("uif gph jt Dpnjoh", 1, false) << "'" << endl;
    cout << "Expected: 'Cuuj cu qj jxu Tyqw qj 11 f.c.', Actual: '" << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << "'" << endl;
}

void testVigenereCipher() {
    cout << "Now testing function VigenereCipher()" << endl;
    cout << "Expected: 'Euyb dv ee lxy Lzrk ll 11 f.g.', Actual: '" << vigenereCipher("Meet me at the Diag at 11 p.m.", "squirrel", true) << "'" << endl;
    cout << "Expected: 'hieasfw', Actual: '" << vigenereCipher("bananas", "giraffe", true) << "'" << endl;
    cout << "Expected: 'jsxd zahl', Actual: '" << vigenereCipher("deez nuts", "gotem", true) << "'" << endl;
    cout << "Expected: '911 what is up', Actual: '" << vigenereCipher("911 cvtx uy ii", "gotem", false) << "'" << endl;
  
    
}

void testMixKey() {
    cout << "Now testing function MixKey()" << endl;
    cout << "Expected: '', Actual: '" << mixKey("amazing") << "'" << endl;
    cout << "Expected: '', Actual: '" << mixKey("23045sposnv") << "'" << endl;
    cout << "Expected: '', Actual: '" << mixKey("aaaaapwj32rn") << "'" << endl;
}


void testFillGrid() {
    cout << "Now testing function FilGrid()" << endl;
}
