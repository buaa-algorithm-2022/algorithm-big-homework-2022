#include <vector>
#include <algorithm>

#include "../utils/BigInteger.h"
#include "../utils/Random.h"
#include "../utils/Validation.h"
#include "../utils/Sortable.h"

using namespace std;

class SelectionSort: public Sortable {
public:
    void sort(vector<BigInteger>& arr) {
        int i,j,d,temp;
        int n = arr.size();
        for(i=0;i<n-1;i++){
            //假设值最小元素为未排序的第一个元素
            d=i;
            //寻找真正值最小元素，记录其位置d
            for(j=i+1;j<n;j++)
                if(arr[j]<arr[d])
                    d=j;
            //值最小元素与未排序的第一个元素交换位置
            if(d!=i){
                swap(arr[i], arr[d]);
            }
        }
    }

    std::string toName() const {
        return "SelectionSort";
    }
};

//int main() {
//    auto nums = rand_bigint_arr(20);
//    cout << "Before:" << nums << endl;
//    checkIsInOrder(nums);
//
//    SelectionSort().sort(nums);
//    cout << "After:" << nums << endl;
//    checkIsInOrder(nums);
//    return 0;
//}