//
//  chapter7.cpp
//  The C++ Programming Language Exercises
//
//  Created by Feyzi Yılankıran on 10.12.2019.
//  Copyright © 2019 Feyzi Yılankıran. All rights reserved.
//

#include "chapter7.hpp"

#include <cstring>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

void readASequenceOfWordsFromInput() {
    string strBuffer{};
    vector<string> strs{};
    cout << "Enter some words please..." << endl;
    while (true) {
        cin >> strBuffer;
        if (strBuffer == "Quit") {
            break;
        }
        
        strs.push_back(string(strBuffer));
    }
    
    sort(strs.begin(), strs.end());
    vector<string>::iterator newEnd = unique(strs.begin(), strs.end());
    strs.resize(distance(strs.begin(), newEnd));
    
    cout << endl << "===========================" << endl << endl << "Here are your unique words..." << endl;
    
    for (auto str : strs) {
        cout << str << endl;
    }
    cout << endl;
}

void countNumberOfOccurencesOfAPairOfLetters() {
    char pairOfLetters[2] = {};
    cout << "Please enter a pair of letters that will be counted: " << flush;
    cin >> pairOfLetters;
    cout << "Please provide the input that these letters will be searched in: " << flush;
    string input{};
    cin >> input;
    
    int strCount{};
    for (int i = 0; i < input.size() - 1; ++i) {
        if (input[i] == pairOfLetters[0] && input[i + 1] == pairOfLetters[1]) {
            ++strCount;
        }
    }
    
    int cStyleCount{};
    const char *cstr = input.c_str();
    for (int i = 0; cstr[i + 1] != '\0'; ++i) {
        if (cstr[i] == pairOfLetters[0] && cstr[i + 1] == pairOfLetters[1]) {
            ++cStyleCount;
        }
    }
    
    cout << endl << "string count: " << setw(20) << left << strCount << endl;
    cout << "c style count: " << setw(20) << left << cStyleCount << endl;
}

void runSomeTestsToSeeIfCompilerGeneratesEquivalentCode() {
    int val{10};
    int iarr[10]{};
    int *pi{&val};
    
    *pi = 20;
}
