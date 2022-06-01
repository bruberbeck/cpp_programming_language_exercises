//
//  chapter6.hpp
//  The C++ Programming Language Exercises
//
//  Created by Feyzi Yılankıran on 9.08.2019.
//  Copyright © 2019 Feyzi Yılankıran. All rights reserved.
//

#ifndef chapter6_hpp
#define chapter6_hpp

#include <string>
#include <iostream>

extern char ch;
extern std::string s;
extern int counter;
extern const double pi;
extern int error_number;

extern const char* name;
extern const char* season[];
extern std::vector<std::string> people;

struct Date;
int day(Date *p);
namespace me {
    double sqrt(double);
    extern int a;
}
template <typename T> T abs(T a);

constexpr int fac(int n) {
    return n < 2 ? 1 : n * fac(n - 1);
}

enum class Beer;

int helloWorld();
void isCharSigned();
void printSizeOfTypes();
void printCharacters();
void printNumericLimits();
void loopThroughArbitraryValues();

#endif /* chapter6_hpp */
