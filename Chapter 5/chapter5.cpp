//
//  chapter5.cpp
//  The C++ Programming Language Exercises
//
//  Created by Feyzi Yılankıran on 13.07.2019.
//  Copyright © 2019 Feyzi Yılankıran. All rights reserved.
//

#include "chapter5.hpp"

#include <chrono>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <regex>
#include <set>
#include <thread>
#include <vector>

using namespace std;
using namespace std::chrono;

void threadOutputAtIntervals(int ms, string str) {
    int count = 10;
    while (--count) {
        cout << str;
        this_thread::sleep_for(milliseconds{ms});
    }
}

void oneThreadWriteHelloOneThreadWritesWorld() {
    const int interval = 1000;
    thread t1 { bind(threadOutputAtIntervals, interval, "Hello ") };
    this_thread::sleep_for(milliseconds(1));
    thread t2 { bind(threadOutputAtIntervals, interval, "World!\n") };
    
    t1.join();
    t2.join();
    cout << endl;
}

vector<int> timeALoopLoop() {
    int i = 0;
    int max = numeric_limits<int>::max();
    vector<int> retVal;
    
    while (++i != max) {
        retVal.push_back(i);
    }
    
    return retVal;
}

void timeALoop() {
    auto start = high_resolution_clock::now();
    cout << timeALoopLoop().size() << endl;
    auto end = high_resolution_clock::now();
    
    cout << "Duration: " << duration_cast<milliseconds>(end - start).count() << "msec" << endl;
}

void repeatTheHistogramDrawing() {
    auto die = bind(normal_distribution<double>{100.0, 5.0}, default_random_engine{});
    multiset<double> values;
    
    for (int i = 0; i < 15000; ++i) {
        values.insert(die());
    }
    
    int min = round(*values.begin());
    vector<int> histogram(40);
    
    for (auto d : values) {
        int intVal = round(d) - min;
        ++histogram[intVal];
    }
    
    cout << "Histogram: " << endl;
    cout << histogram.size()     << endl;
    for (int i = 0; i < histogram.size(); ++i) {
        cout << i + 1 << ": ";
        int starCount = histogram[i] / 15;
        
        for (int j = 0; j < starCount; ++j) {
            cout << '*';
        }
        cout << endl;
    }
}

void regexToFindAllDecimalNumbersInAFile() {
    ofstream output("output");
    output << R"(RegE123.232xr wa4243s creat25352ed by g2662skinner.com, and is proudly hosted by Media Temple.\
        14437617.2141\
        Edit the Expression & Text to see matches. Roll over matches or the expression for details. PCRE & Javascript flavors of RegEx are supported.\
        The side ba1453453r includes a Cheatsheet, fu1346l Reference, and Help. You can also Save & Share with the Community, and view patterns you cr13733717eate or favorite in 1My Patterns.146\
        61\
        Explore results with the Tools below. Repl14ace & L137ist output custom r371371esults. Details lists capture g17373oups. Explain describes your expression in plain English.17)";
    output.close();
    
    ifstream input("output");
    regex pat(R"(\d+(\.\d+:?)?)");
    
    for (string line; getline(input, line);) {
        smatch matches;
        string str = line;
        while (regex_search(str, matches, pat)) {
            cout << *matches.begin() << ' ';
            str = matches.suffix().str();
        }
    }
    input.close();
    
    remove("output");
    cout << endl;
}
