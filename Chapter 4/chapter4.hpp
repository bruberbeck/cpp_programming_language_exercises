//
//  chapter 2.hpp
//  C++ Programming Language Exercises
//
//  Created by Feyzi Yılankıran on 12.07.2019.
//  Copyright © 2019 Feyzi Yılankıran. All rights reserved.
//

#ifndef chapter4_hpp
#define chapter4_hpp

#include <stdio.h>
#include <iostream>

void inputOutputNameAge();
void initializeVectorInt();
void initializeVectorString();
void writeIntegersToOfstream();
void readIntegersFromIfstream();

template<typename T, typename U>
std::ostream& operator <<(std::ostream& os, const std::pair<T, U>& pr) {
    return os << "First: " << pr.first << " Second:" << pr.second;
}

template<typename T, typename U>
std::istream& operator >>(std::istream& is, std::pair<T, U>& pr) {
    return is >> pr.first >> pr.second;
}

#endif /* chapter4_hpp */
