//
// Created by Junlin Bian on 2022/11/7.
//

#ifndef ALGORITHM_BIG_HOMEWORK_2022_VALIDATION_H
#define ALGORITHM_BIG_HOMEWORK_2022_VALIDATION_H

#include <iostream>

#include "BigInteger.h"

template <typename T>
std::ostream& operator <<(std::ostream& out, const std::vector<T>& arr) {
    out << "["; bool first = true;
    for (auto& ele : arr) { out << (first ? "" : ", "); out << ele; first = 0;} out << "]";
    return out;
}

std::ostream& operator<<(std::ostream& os, const BigInteger& bigInteger) {
    os << bigInteger.getContent();
    return os;
}

template <typename T>
bool checkIsInOrder(std::vector<T>& arr, bool ascent = true, bool log = true) {
    bool res = true;
    for (int i = 0; i < arr.size()-1; ++i) {
        if ((ascent && arr[i] > arr[i+1]) || (!ascent && arr[i] < arr[i+1])) {
            res = false;
            break;
        }
    }
    if (log)
        std::cout << "Is in order: " << (res ? "YES" : "NO") << std::endl;
    return res;
}

#endif //ALGORITHM_BIG_HOMEWORK_2022_VALIDATION_H
