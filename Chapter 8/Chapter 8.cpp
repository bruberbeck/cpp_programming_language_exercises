//
//  Chapter 8.cpp
//  The C++ Programming Language Exercises
//
//  Created by Feyzi Yılankıran on 31.12.2019.
//  Copyright © 2019 Feyzi Yılankıran. All rights reserved.
//

#include "Chapter 8.hpp"

#include <iomanip>
#include <iostream>

using namespace std;

void rewriteTheForStatement() {
    const int max_length = 10;
    char input_line[max_length] = { '?', '?', 'b', 'c', '?', 'd', '?', 'e', 'f', '?' };
    int quest_count = 0;
    
    for (int i = 0; i != max_length; i++)
        if (input_line[i] == '?')
            quest_count++;
    
    cout << setw(20) << left << "<for>" << "Quest count: " << quest_count << endl;
    
    quest_count = 0;
    int k = 0;
    while (k < max_length) {
        if (input_line[k] == '?')
            quest_count++;
        ++k;
    }
    cout << setw(20) << left << "<while>" << "Quest count: " << quest_count << endl;
    
    quest_count = 0;
    char *pch = input_line;
    while (pch != input_line + max_length) {
        if (*pch == '?') {
            quest_count++;
        }
        ++pch;
    }
    cout << setw(20) << left << "<pointer>" << "Quest count: " << quest_count << endl;
    
    quest_count = 0;
    for (auto ch : input_line) {
        if (ch == '?') {
            quest_count++;
        }
    }
    cout << setw(20) << left << "<range-for>" << "Quest count: " << quest_count << endl;
}

void compilerErrors(int a, int b) {
    if (a = 3)
        ;
    
    if (a&077 == 0)
        ;
    
    for (int i = 0; i < 10;) {
        ;
    }
}

void send(int* to, int* from, int count)
{
    // Duff’s device. Helpful comment deliberately deleted.
    int n = (count + 7) / 8;
    switch (count % 8) {
        case 0: while (--n > 0) { *to++ = *from++;
            cout << "x" << endl;
        case 7:     *to++ = *from++;
        case 6:     *to++ = *from++;
        case 5:     *to++ = *from++;
        case 4:     *to++ = *from++;
        case 3:     *to++ = *from++;
        case 2:     *to++ = *from++;
        case 1:     *to++ = *from++;
        }
    }
}

void duffsDevice() {
    int to[24]{};
    int from[24] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int count = 8;
    send(to, from, count);
    
    cout << "Duff's device" << endl;
    cout << "=============" << endl;
    for (int i = 0; i < count; ++i) {
        cout << to[i];
        if (i != count - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}
