#include<vector>
#include<iostream>

#include "../DataGenerator.cpp"

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
    vector<int> data;
    loadNormData(data, "shell_sort_data.txt");
    ShellSort(data);
    writeNormResult(data, "shell_sort_result.txt");
    return 0;
}
