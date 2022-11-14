//
// Created by Jaylen Bian on 2022/11/7.
//

#include <vector>
#include <chrono>
#include <pthread/pthread.h>
#include <thread>

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

void run_sort_multitheaded(vector<Sortable*>& algos, vector<BigInteger>& arr) {
    int len = arr.size();
    int maxThreadCount = min(arr.size(), algos.size());
    int segmentLength = len / maxThreadCount, startOffset;

    chrono::steady_clock::time_point begin, end;
    cout << "\t--Start running: " << algos[0]->toName() << " with " << maxThreadCount << " threads" << endl;
    begin = chrono::steady_clock::now();

    vector<vector<BigInteger>> segments(maxThreadCount);
    vector<thread> threads(maxThreadCount);
    for (int i = 0; i < maxThreadCount; ++i) {
        startOffset = i*segmentLength;
        if (i == maxThreadCount-1)
            segments[i] = vector<BigInteger>(arr.begin()+startOffset, arr.begin()+len);
        else
            segments[i] = vector<BigInteger>(arr.begin()+startOffset, arr.begin()+min(startOffset+segmentLength, len));
        threads[i] = thread(&Sortable::sort, algos[i], std::ref(segments[i]));
    }
    for (auto &thread: threads)
        thread.join();
    vector<int> idx (maxThreadCount, 0);
    int p;
    for (int i = 0; i < len; ++i) {
        int minIdx = -1;
        for (int j = 0; j < maxThreadCount; ++j) {
            p = idx[j];
            if (p < segments[j].size()) {
                if (minIdx == -1 || segments[minIdx][idx[minIdx]] > segments[j][p]) {
                    minIdx = j;
                }
            }
        }
        arr[i] = segments[minIdx][idx[minIdx]++];
    }

    end = chrono::steady_clock::now();
    if (checkIsInOrder(arr, true, false)) {
        cout << "\t  Sorting finished, time cost: " << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << "ns" << endl;
    } else {
        cout << "\t  Sorting failed, check your implementation." << endl;
    }
}

int main() {
    unsigned long const hardware_threads = thread::hardware_concurrency();
    const unsigned long MAX_THREAD_COUNT = 5;
    unsigned long THREAD_COUNT = min(MAX_THREAD_COUNT, hardware_threads != 0 ? hardware_threads : 4);
    vector<vector<Sortable*>> algoLists = {
        vector<Sortable*>(MAX_THREAD_COUNT, new BubbleSort()),
        vector<Sortable*>(MAX_THREAD_COUNT, new RadixSort()),
        vector<Sortable*>(MAX_THREAD_COUNT, new QuickSort()),
        vector<Sortable*>(MAX_THREAD_COUNT, new ShellSort()),
        vector<Sortable*>(MAX_THREAD_COUNT, new SelectionSort()),
        vector<Sortable*>(MAX_THREAD_COUNT, new MergeSort())
    };

    vector<int> numCounts = {(int)1e2, (int)1e3, (int)1e4};

    for (int i = 0; i < numCounts.size(); ++i) {
        cout << "Running round " << i+1 << ", datasize = " << numCounts[i] << endl;
        auto raw_nums = rand_bigint_arr(numCounts[i]);
        for (auto algos: algoLists) {
            auto nums = vector<BigInteger>(raw_nums.begin(), raw_nums.end());
            run_sort(algos[0], nums);

            auto nums_multithread = vector<BigInteger>(raw_nums.begin(), raw_nums.end());
            run_sort_multitheaded(algos, nums_multithread);
        }
    }

    return 0;
}