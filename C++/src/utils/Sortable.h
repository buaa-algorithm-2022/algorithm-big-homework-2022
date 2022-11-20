//
// Created by Jaylen Bian on 2022/11/7.
//

#ifndef ALGORITHM_BIG_HOMEWORK_2022_SORTABLE_H
#define ALGORITHM_BIG_HOMEWORK_2022_SORTABLE_H

#include <vector>
#include <string>

#include "BigInteger.h"

class Sortable {
public:
    virtual void sort(std::vector<BigInteger>& arr) = 0;
    virtual std::string toName() const = 0;
};

#endif //ALGORITHM_BIG_HOMEWORK_2022_SORTABLE_H
