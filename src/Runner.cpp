//
// Created by Jaylen Bian on 2022/11/7.
//

#include <vector>
#include <chrono>
#include <pthread/pthread.h>

#include "utils/Sortable.h"
#include "utils/Random.h"
#include "utils/Validation.h"
#include "algo/BubbleSort.cpp"
#include "algo/RadixSort.cpp"
#include "algo/QuickSort.cpp"
#include "algo/ShellSort.cpp"
#include "algo/SelectionSort.cpp"
#include "algo/MergeSort.cpp"

using namespace std;

void run_sort(Sortable* algo, vector<BigInteger>& arr) {
    chrono::steady_clock::time_point begin, end;
    cout << "\t--Start running: " << algo->toName() << endl;

    begin = chrono::steady_clock::now();
    algo->sort(arr);
    end = chrono::steady_clock::now();
    if (checkIsInOrder(arr, true, false)) {
        cout << "\t  Sorting finished, time cost: " << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << "ns" << endl;
    } else {
        cout << "\t  Sorting failed, check your implementation." << endl;
    }
}

int main() {
    vector<Sortable*> algos = {
        new BubbleSort(),
        new RadixSort(),
        new QuickSort(),
        new ShellSort(),
        new SelectionSort(),
        new MergeSort()
    };

    vector<int> numCounts = {(int)1e2, (int)1e3, (int)1e4};

    for (int i = 0; i < numCounts.size(); ++i) {
        cout << "Running round " << i+1 << ", datasize = " << numCounts[i] << endl;
        auto raw_nums = rand_bigint_arr(numCounts[i]);
        for (auto algo: algos) {
            auto nums = vector<BigInteger>(raw_nums.begin(), raw_nums.end());
            run_sort(algo, nums);
        }
    }

    return 0;
}