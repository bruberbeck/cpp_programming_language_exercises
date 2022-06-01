//
//  chapter 4.cpp
//  C++ Programming Language Exercises
//
//  Created by Feyzi Yılankıran on 12.07.2019.
//  Copyright © 2019 Feyzi Yılankıran. All rights reserved.
//

#include "chapter4.hpp"
#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>

using namespace std;

void inputOutputNameAge() {
    cout << "Name and age: " << flush;
    string name;
    int age;
    cin >> name >> age;

    cout << name << " " << age << endl;
}

void initializeVectorInt() {
    vector<int> v { 5, 9, -1, 200, 0 };
    for_each(v.begin(), v.end(), [](int i) { cout << i << ' '; });
    cout << endl;
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int i) { cout << i << ' '; });
    cout << endl;
}

void initializeVectorString() {
    vector<string> v { "Kant", "Plato", "Aristotle", "Kierkegard", "Hume" };
    for_each(v.begin(), v.end(), [](string i) { cout << i << ' '; });
    cout << endl;
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](string i) { cout << i << ' '; });
    cout << endl;
}

void writeIntegersToOfstream() {
    ofstream out("output");
    for (int i = 0; i < 1000; ++i) {
        out << i << " ";
    }
    out.close();
}

void readIntegersFromIfstream() {
    ifstream in("output");
    int i;
    while (in) {
        in >> i;
        cout << i << " ";
    }
    in.close();
    remove("output");
}
