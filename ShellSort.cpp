#include<vector>
#include<iostream>

using namespace std;

void ShellSort(vector<int> &L)
{
    int temp;
    for(int gap = L.size() / 2; gap >= 1; gap = gap / 2)
    {
        for(int i = gap; i < L.size(); ++i)
        {
            if(L[i] < L[i - gap])
            {
                temp = L[i];
                int j;
                for(j = i - gap; j >= 0 && temp < L[j]; j -= gap)
                {
                    L[j + gap] = L[j];
                }
                L[j + gap] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> test;
    test.push_back(9);
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(3);
    test.push_back(8);

    ShellSort(test);

    for (int i = 0; i < test.size(); i++)
    {
        cout << test[i] << " ";
    }
    cout << endl;
    return 0;
}
