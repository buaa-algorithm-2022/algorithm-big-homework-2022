//
// Created by Jaylen Bian on 2022/11/7.
//

#include <vector>
#include <algorithm>

#include "BigInteger.h"
//#include "BigInteger.cpp"
#include "Random.h"
#include "Validation.h"

using namespace std;

class BubbleSort {
public:
    void sort(vector<BigInteger>& arr) {
        size_t n = arr.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (arr[i] > arr[j])
                    swap(arr[i], arr[j]);
            }
        }
    }
};

int main() {
    auto nums = rand_bigint_arr(20);
    cout << "Before:" << nums << endl;
    checkIsInOrder(nums);

    BubbleSort().sort(nums);
    cout << "After:" << nums << endl;
    checkIsInOrder(nums);
    return 0;
}