#include<iostream>
#include<vector>
#include<fstream>

#include "../DataGenerator.cpp"

using namespace std;


int partition(vector<int> &L, int low, int high) 
{
	int temp = L[low];
	int pivotkey = L[low];
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

void QuickSort(vector<int> &L, int low, int high)
{
    if(low < high)
    {
        int pivotloc = partition(L, low, high);
        QuickSort(L, low, pivotloc - 1);
        QuickSort(L, pivotloc + 1, high);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> data;
    loadNormData(data, "quick_sort_data.txt");
    QuickSort(data, 0, data.size());
    writeNormResult(data, "quick_sort_result.txt");
    return 0;
}
