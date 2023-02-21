/*
 * test.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Colin Gordon, Lee Fingar-Myers
 * cogo, leefm
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
void testFillGrid();
void testFindInGrid();
void testPolybiusSquare();

void startTests() {
    testShiftAlphaCharacter();
    testRemoveNonAlphas();
    testCharToInt();
    testRemoveDuplicate();
    testCaesarCipher();
    testVigenereCipher();
    testMixKey();
    testFillGrid();
    testFindInGrid();
    testPolybiusSquare();
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
    cout << "Expected: '', Actual: '" << mixKey("TRAIN798") << "'" << endl;
    cout << "Expected: '', Actual: '" << mixKey("GL914SVXM23") << "'" << endl;
    cout << "Expected: '', Actual: '" << mixKey("123456789GLMTWQ") << "'" << endl;
    cout << "Expected: '', Actual: '" << mixKey("RM43FE7QP") << "'" << endl;
}


void testFillGrid() {
    char grid[6][6];
    string content;
    cout << "Now testing function FillGrid()" << endl;
    cout << "Expected: '', Actual: '";
    fillGrid(grid, "smiles");
    cout << "'" << endl;

}


void testFindInGrid() {
    char grid[6][6];
    fillGrid(grid, ALNUM);
    cout << "Now testing function FindInGrid()" << endl;
    printGrid(grid);
    cout << "Expected: '00', Actual: '" << findInGrid('A', grid) << "'" << endl;
    cout << "Expected: '24', Actual: '" << findInGrid('Q', grid) << "'" << endl;
    cout << "Expected: '45', Actual: '" << findInGrid('3', grid) << "'" << endl;
}

void testPolybiusSquare() {
    char grid[6][6];
    fillGrid(grid, ALNUM);
    printGrid(grid);
    cout << "Now testing function PolybiusSquare()" << endl;
    cout << "Expected: '', Actual: '" << polybiusSquare(grid, "GOKU", "GOD BLESS AMERICA", true) << "'" << endl;
    cout << "Expected: '', Actual: '" << polybiusSquare(grid, "GOKU", "000111 0521123131 04221230151004", false) << "'" << endl;
    cout << "Expected: '', Actual: '" << polybiusSquare(grid, "LAWPLUS", "SHOUTING FEUD", true) << "'" << endl;
    cout << "Expected: '', Actual: '" << polybiusSquare(grid, "YEHAW", "HOWDY TO YOU", true) << "'" << endl;
    cout << "Expected: '', Actual: '" << polybiusSquare(grid, "STUER", "DID I", true) << "'" << endl;
}
