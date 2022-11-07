//
// Created by Junlin Bian on 2022/11/7.
//

#ifndef ALGORITHM_BIG_HOMEWORK_2022_BIGINTEGER_H
#define ALGORITHM_BIG_HOMEWORK_2022_BIGINTEGER_H

#include <vector>
#include <string>

class BigInteger {
private:
    std::string m_content;

public:
    explicit BigInteger(std::string& str) : m_content(str) {};
    explicit BigInteger(std::vector<char>& chs) : m_content(std::string(chs.begin(), chs.end())) {};
    explicit BigInteger(std::vector<int>& nums) : m_content(std::string(nums.begin(), nums.end())) {};

    std::string getContent() const { return m_content; };

    friend bool operator == (const BigInteger& lhs, const BigInteger& rhs);
    friend bool operator < (const BigInteger& lhs, const BigInteger& rhs);
    friend bool operator > (const BigInteger& lhs, const BigInteger& rhs);
};

bool operator == (const BigInteger& lhs, const BigInteger& rhs) {
    return lhs.m_content == rhs.m_content;
}

bool operator < (const BigInteger& lhs, const BigInteger& rhs) {
    if (lhs.m_content.size() == rhs.m_content.size())
        return lhs.m_content < rhs.m_content;
    return lhs.m_content.size() < rhs.m_content.size();
}

bool operator > (const BigInteger& lhs, const BigInteger& rhs) {
    return operator<(rhs, lhs);
}

#endif //ALGORITHM_BIG_HOMEWORK_2022_BIGINTEGER_H
