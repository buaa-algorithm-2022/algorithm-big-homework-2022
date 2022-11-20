//
// Created by Junlin Bian on 2022/11/7.
//

#ifndef ALGORITHM_BIG_HOMEWORK_2022_VALIDATION_H
#define ALGORITHM_BIG_HOMEWORK_2022_VALIDATION_H

#include <iostream>
#include <string>

#include "BigInteger.h"

template <typename T>
std::ostream& operator <<(std::ostream& out, const std::vector<T>& arr) {
    out << "["; bool first = true;
    for (auto& ele : arr) { out << (first ? "" : ", "); out << ele; first = 0;} out << "]";
    return out;
}

std::ostream& operator<<(std::ostream& os, const BigInteger& bigInteger) {
    os << (bigInteger.isNegative() ? "-" : "") + bigInteger.getContent();
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

using hash_t = size_t;
constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;

hash_t hash_run_time(const char* str) {
    hash_t ret = basis;
    while (*str) {
        ret ^= *str;
        ret *= prime;
        str++;
    }
    return ret;
}

constexpr hash_t hash_compile_time(const char* str, hash_t last_value = basis) {
    return *str ? hash_compile_time(str + 1, (*str ^ last_value) * prime) : last_value;
}

constexpr hash_t operator "" _hash(const char* p, size_t) {
    return hash_compile_time(p);
}

#endif //ALGORITHM_BIG_HOMEWORK_2022_VALIDATION_H
