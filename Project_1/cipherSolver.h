#ifndef CIPHER_SOLVER_H
#define CIPHER_SOLVER_H

#include<string>
#include<vector>
using namespace std;

class cipherSolver{
    private: 
       string cipherText; //cipher text needed to decode
       int lettCount[26]; //26 letters in alphabet
       char subsKey[26]; //decoding key for substitution cipher
       int totalCount; //total number of letters in cipher text
    public:
        cipherSolver(const string &cipherText); //constructor
        void calcFreq(); //calculate frequency of letters
        void setSubs(char cipherChar, char subChar); //test char with subsituted key according to frequency
        void clearSubs(); 
        void printcomparisonTable() const;
        void printdecodedText() const; 
};
#endif // CIPHER_SOLVER_H