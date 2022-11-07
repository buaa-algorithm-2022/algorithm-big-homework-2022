//
// Created by Junlin Bian on 2022/11/7.
//

#ifndef ALGORITHM_BIG_HOMEWORK_2022_RANDOM_H
#define ALGORITHM_BIG_HOMEWORK_2022_RANDOM_H

#include <vector>
#include <iostream>
#include <random>
#include <cstdlib>

BigInteger rand_bigint(int bitsLimit);

std::vector<BigInteger> rand_bigint_arr(int capacity, int bitsLimit = 99) {
    std::srand(time(0));
    std::vector<BigInteger> res;
    for (int i = 0; i < std::max(0, capacity); ++i)
        res.push_back(rand_bigint(bitsLimit));
    return res;
}

BigInteger rand_bigint(int bitsLimit) {
    int bits = rand() % bitsLimit + 1; // [1, bitLimit]
    std::vector<char> chs(bits);
    for (int i = 0; i < bits; ++i) {
        chs[bits-i-1] = rand() % 10 + '0'; // [0, 9)
    }
    chs[0] = (rand() % 9 + 1) + '0';
    return BigInteger(chs);
}

#endif //ALGORITHM_BIG_HOMEWORK_2022_RANDOM_H
