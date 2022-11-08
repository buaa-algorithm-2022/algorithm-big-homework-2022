#include<iostream>
#include<vector>
#include<fstream>
#include <algorithm>


#include "../utils/BigInteger.h"
#include "../utils/Random.h"
#include "../utils/Validation.h"
#include "../utils/Sortable.h"

using namespace std;

class QuickSort: public Sortable {
public:
    int partition(vector<BigInteger> &L, int low, int high) 
    {
        BigInteger temp = L[low];
        BigInteger pivotkey = L[low];
        while(low < high)
        {
            while(low < high && L[high] >= pivotkey) --high;
            L[low] = L[high];
            while(low < high && L[low] <= pivotkey) ++low;
            L[high] = L[low];
        }
        L[low] = temp;
        return low;
    }

    void quickSort(vector<BigInteger> &L, int low, int high)
    {
        if(low < high)
        {
            int pivotloc = partition(L, low, high);
            quickSort(L, low, pivotloc - 1);
            quickSort(L, pivotloc + 1, high);
        }
    }

    void sort(vector<BigInteger> &L) {
        quickSort(L, 0, L.size() - 1);
    }

    std::string toName() const {
        return "QuickSort";
    }
};

// int main(int argc, char const *argv[])
// {
//     vector<int> data;
//     loadNormData(data, "quick_sort_data.txt");
//     QuickSort(data, 0, data.size() - 1);
//     writeNormResult(data, "quick_sort_result.txt");
//     return 0;
// }