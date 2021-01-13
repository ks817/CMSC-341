/**************************************************************
 * File:    driver.cpp
 * Project: CMSC 341 - Project 3 - Word Frequency
 * Author : Kusum Sharma
 * Date   : 29-June-2020
 * Section: Lecture-01
 * E-mail:  ks17@umbc.edu
 *
 * HashedSplays Class implementation.
 *
 *************************************************************/
#include "HashedSplays.h"  // Includes constants

using namespace std;
const int ALPHABET_SIZE = 26;

int main(int argc, char *argv[]) {

    try {
        // Instatiate the main object
        HashedSplays wordFrequecy(ALPHABET_SIZE);
        // Build the trees
        wordFrequecy.FileReader(argv[1]);

        // Test methods to show hashed splay trees work
        wordFrequecy.PrintHashCounts();
        wordFrequecy.PrintTree(19); // Prints the "T" tree
        wordFrequecy.PrintTree("F");
        wordFrequecy.PrintTree("K"); // should be mpty running input1
        wordFrequecy.FindAll("The"); // should find all the's (ignoring case)
        cout << endl;
    }
    // Error catching
    catch (Exceptions &cException) {
        cout << "EXCEPTION: " << cException.GetMessage() << endl;
        return 1;
    }
    
    //Uncomment for number of seconds running.
    //cout << clock() / (float)(CLOCKS_PER_SEC) << endl;
    return 0;
}
