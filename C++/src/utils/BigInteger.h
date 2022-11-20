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
    bool m_isNegative;

public:
    explicit BigInteger() : m_content("0"), m_isNegative(false) {};
    explicit BigInteger(std::string& str) { parse(str); };
    explicit BigInteger(std::string& str, bool isNegative) : m_content(str), m_isNegative(isNegative) {};
    explicit BigInteger(std::vector<char>& chs, bool isNegative) : m_content(std::string(chs.begin(), chs.end())), m_isNegative(isNegative) {};
    explicit BigInteger(std::vector<int>& nums, bool isNegative) : m_content(std::string(nums.begin(), nums.end())), m_isNegative(isNegative) {};

    std::string getContent() const {
        return m_content;
    };
    void parse(std::string str) {
        if (str.substr(0, 1) == "-") {
            m_isNegative = true;
            m_content = str.substr(1);
        } else {
            m_isNegative = false;
            m_content = str;
        }
    }
    bool isNegative() const { return m_content != "0" && m_isNegative; };

    friend bool operator == (const BigInteger& lhs, const BigInteger& rhs);
    friend bool operator < (const BigInteger& lhs, const BigInteger& rhs);
    friend bool operator > (const BigInteger& lhs, const BigInteger& rhs);
    friend bool operator <= (const BigInteger& lhs, const BigInteger& rhs);
    friend bool operator >= (const BigInteger& lhs, const BigInteger& rhs);
};

bool operator == (const BigInteger& lhs, const BigInteger& rhs) {
    if (lhs.m_content == "0" && rhs.m_content == "0")
        return true;
    return lhs.m_content == rhs.m_content && lhs.isNegative() == rhs.isNegative();
}

bool operator < (const BigInteger& lhs, const BigInteger& rhs) {
    if (lhs == rhs) return false;
    if (lhs.m_content.size() == rhs.m_content.size()) {
        if (lhs.isNegative() && rhs.isNegative())
            return lhs.m_content > rhs.m_content;
        else if (!lhs.isNegative() && !rhs.isNegative())
            return lhs.m_content < rhs.m_content;
        return lhs.isNegative();
    } else if (lhs.isNegative() && rhs.isNegative()) {
        return lhs.m_content.size() > rhs.m_content.size();
    } else if (!lhs.isNegative() && !rhs.isNegative()) {
        return lhs.m_content.size() < rhs.m_content.size();
    } else {
        return lhs.isNegative();
    }
}

bool operator > (const BigInteger& lhs, const BigInteger& rhs) {
    return operator<(rhs, lhs);
}

bool operator >= (const BigInteger& lhs, const BigInteger& rhs) {
    return operator<(rhs, lhs) || operator==(lhs, rhs);
}

bool operator <= (const BigInteger& lhs, const BigInteger& rhs) {
    return operator<(lhs, rhs) || operator==(lhs, rhs);
}

#endif //ALGORITHM_BIG_HOMEWORK_2022_BIGINTEGER_H
