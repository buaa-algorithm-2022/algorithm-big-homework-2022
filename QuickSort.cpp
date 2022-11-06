#include<iostream>
#include<vector>

using namespace std;


int partition(vector<int> &L, int low, int high) 
{
	int temp = L[low];
	int pivotkey = L[low];
	while(low < high){
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
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(3);
    test.push_back(9);
    test.push_back(8);

    cout << test.size() << endl;
    QuickSort(test, 0, test.size() - 1);
    for (int i = 0; i < test.size(); i++)
    {
        cout << test[i] << " ";
    }
    cout << endl;
    
    return 0;
}
