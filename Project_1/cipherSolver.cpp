#include "cipherSolver.h"
#include<iostream>

using namespace std;

cipherSolver::cipherSolver(const string &incipherText){
    cipherText = incipherText;
    totalCount = 0;
    for (int i = 0; i < 26; i++){
        lettCount[i] = 0;
    }
    clearSubs();
}

void cipherSolver::calcFreq(){
    totalCount = 0;
    for (int i = 0; i < 26; i++){
        lettCount[i] = 0;
    }
    for(int i = 0; i < cipherText.length(); i++){
        char c = cipherText[i];
        if(c >= 'a' && c <= 'z'){
            lettCount[c - 'a']++;
            totalCount++;
        }
    }
}
void cipherSolver::setSubs(char cipherChar, char subChar){
    if(cipherChar >= 'a' && cipherChar <= 'z'){
        subsKey[cipherChar - 'a'] = subChar;
    }
}
void cipherSolver::clearSubs(){
    for(int i = 0; i < 26; i++){
        subsKey[i] = '-';
    }
}
void cipherSolver::printcomparisonTable() const{
    double standardEnglishFreq[26] = {0.0817, 0.0150, 0.0278, 0.0425, 0.1270, 0.0223, 0.0202, 0.0609, 
        0.0697, 0.0015, 0.0077, 0.0403, 0.0241, 0.0675, 0.0751, 0.0193, 0.0010, 0.0599, 0.0633, 0.0906, 
        0.0276, 0.0098, 0.0236, 0.0015, 0.0197, 0.0007};

    cout << "Letter\t Cipher Freq\t EnglishFreq\n";
    for(int i = 0; i < 26;i++){
        char letter = 'a' +i;
        double cipherFreq = (totalCount >0) ? (double)lettCount[i] / totalCount : 0.0;
        double englishFreq = standardEnglishFreq[i];
        cout << letter << "\t " << cipherFreq << "\t " << englishFreq << endl;
    }
}
void cipherSolver::printdecodedText() const{
    cout << "Decoded Text: ";
    for(int i = 0; i < cipherText.length(); i++){
        char c = cipherText[i];
        if(c >= 'a' && c <= 'z'){
            int index = c - 'a';
            if(subsKey[index] != '-'){
            cout << subsKey[index];
            }
            else{
                cout << c;
            }
        } else {
            cout << c;
        }
    }
    cout << endl;
}