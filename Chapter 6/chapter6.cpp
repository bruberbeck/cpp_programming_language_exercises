//
//  chapter6.cpp
//  The C++ Programming Language Exercises
//
//  Created by Feyzi Yılankıran on 9.08.2019.
//  Copyright © 2019 Feyzi Yılankıran. All rights reserved.
//

#include "chapter6.hpp"

#include <limits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

char ch = 'a';
string s = "meow";
auto counter = 10;
const double pi { 3.1415926535897 };
int error_number = -2;

const char* name = "Njal";
const char* season[] = { "spring", "summer", "fall", "winter" };
vector<string> people { name, "Skharphedin", "Gunnar" };

const unsigned long long arbitraryValues = 0x0C8A4A4;

struct Date { int d, m, y; };
int day(Date *p) { return p->d; }

double me::sqrt(double val) {
    return std::sqrt(val);
}
int me::a = 18;

template <typename T> T abs(T a) {
    return a < 0 ? -a : a;
}

int helloWorld() {
    cout << "Hello world!\n" << flush;
    return 0;
}

void isCharSigned() {
    cout << "Is char signed: " << boolalpha << (((int) (char) -1) < 0) << endl;
}

template <typename T> void printSizeOf() {
    cout << "sizeof(" << typeid(T).name() << "): " << sizeof(T) << endl;
}

void printSizeOfTypes() {
    printSizeOf<bool>();
    cout << endl;
    
    printSizeOf<char>();
    printSizeOf<unsigned char>();
    printSizeOf<signed char>();
    printSizeOf<wchar_t>();
    printSizeOf<char16_t>();
    printSizeOf<char32_t>();
    cout << endl;
    
    printSizeOf<short int>();
    printSizeOf<int>();
    printSizeOf<long int>();
    printSizeOf<long long int>();
    cout << endl;
    
    printSizeOf<float>();
    printSizeOf<double>();
    printSizeOf<long double>();
    cout << endl;
    
    printSizeOf<struct Date*>();
    printSizeOf<void *>();
    printSizeOf<int (*)(int, double, Date*)>();
    cout << endl;
    
    printSizeOf<Beer>();
    cout << endl;
}

void printCharacters() {
    const char* alphaChars = "abcdefghijklmnopqrstuwvyz";
    const char* numChars = "0123456789";
    const char* printChars = " \t\n.,/\\'\";:]}[{±§!@#$%ˆ&*()_+|˜`";
    void (*print)(const char*) = [](const char* chars) {
        for (int i = 0; chars[i]; ++i) {
            char ch = chars[i];
            int chNum = (int) ch;
            cout << "<" << ch << "> " << setw(3) << dec << chNum << " | " << setw(3) << hex << chNum << endl;
        }
    };
    
    print(alphaChars);
    cout << endl;
    
    print(numChars);
    cout << endl;
    
    print(printChars);
}

template <typename T> void printLimit() {
    cout << setw(1) << typeid(T).name() << ": " << setw(20) << +numeric_limits<T>::min() << " " << setw(20) << +numeric_limits<T>::max() << " " << setw(2) << sizeof(T) << " " << setw(2) << alignof(T) << endl;
}

void printNumericLimits() {
    printLimit<bool>();
    printLimit<char>();
    printLimit<short>();
    printLimit<int>();
    printLimit<unsigned>();
    printLimit<long>();
    printLimit<unsigned long>();
    printLimit<long long>();
    printLimit<unsigned long long>();
    printLimit<float>();
    printLimit<double>();
    printLimit<long double>();
}

void loopThroughArbitraryValues() {
    for (int i = 0; i < 5; ++i) {
        cout << ((arbitraryValues >> 5 * i) & 0x1F) << endl;
    }
}
