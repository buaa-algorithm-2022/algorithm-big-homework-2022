//
// Created by Jaylen Bian on 2022/11/7.
//

#include <iostream>
#include <vector>
#include <algorithm>

#include "../utils/BigInteger.h"
#include "../utils/Random.h"
#include "../utils/Validation.h"
#include "../utils/Sortable.h"

using namespace std;

class RadixSort: public Sortable {
public:
    void sort(vector<BigInteger>& arr) {
        size_t maxBit = 0, n = arr.size();
        for (auto ele: arr)
            maxBit = max(ele.getContent().length(), maxBit);

        int i, bitVal;
        vector<int> cnt(19); // [-9, 9]
        vector<BigInteger> bucket(arr.begin(), arr.end());

        for (int bit = 1; bit <= maxBit; ++bit) {
            for (int i = 0; i < 19; ++i)
                cnt[i] = 0;
            for (i = 0; i < n; ++i) {
                bitVal = getBitVal(arr[i], bit);
                cnt[bitVal]++;
            }
            for (i = 1; i < 19; ++i)
                cnt[i] += cnt[i-1];
            for (i = n-1; i >= 0; --i) {
                bitVal = getBitVal(arr[i], bit);
                bucket[cnt[bitVal]-1] = arr[i];
                cnt[bitVal]--;
            }
            for (i = 0; i < n; ++i)
                arr[i] = bucket[i];
        }
    }

    std::string toName() const {
        return "RadixSort";
    }

private:
    int getBitVal(BigInteger bigInteger, int bit) {
        const auto content = bigInteger.getContent();
        int rawVal = content.length() < bit ? 0 : (content[content.length() - bit] - '0');
        if (bigInteger.isNegative()) rawVal *= -1;
        return rawVal + 9;
    }
};

//int main() {
//    auto nums = rand_bigint_arr(100);
//    cout << "Before:" << nums << endl;
//    checkIsInOrder(nums);
//
//    RadixSort().sort(nums);
//    cout << "After:" << nums << endl;
//    checkIsInOrder(nums);
//    return 0;
//}