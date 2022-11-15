#include <vector>
#include <algorithm>

#include "../utils/BigInteger.h"
#include "../utils/Random.h"
#include "../utils/Validation.h"
#include "../utils/Sortable.h"

using namespace std;

class MergeSort: public Sortable {
public:
    void sort(vector<BigInteger>& arr) {
        int n = arr.size();
        //分配一个辅助数组
        vector<BigInteger> tempArr = vector<BigInteger>(arr);
        msort(arr,tempArr,0,n-1);
    }

    std::string toName() const {
        return "MergeSort";
    }

private:
    void merge(vector<BigInteger>& arr, vector<BigInteger>& tempArr, int left, int mid, int right) {
        //标记左半区第一个未排序的元素
        int l_pos = left;
        //标记右半区第一个未排序的元素
        int r_pos = mid + 1;
        //临时数组元素的下标
        int pos = left;
        //合并
        while(l_pos<=mid && r_pos<=right){
            if(arr[l_pos]<=arr[r_pos])
                tempArr[pos++] = arr[l_pos++];
            else
                tempArr[pos++] = arr[r_pos++];
        }
        //合并左半区剩余的元素
        while(l_pos<=mid)
            tempArr[pos++] = arr[l_pos++];
        //合并右半区剩余的元素
        while(r_pos<=right)
            tempArr[pos++] = arr[r_pos++];
        //把临时数组中的元素复制回原来的数组
        while(left<=right){
            arr[left] = tempArr[left];
            left++;
        }
    }

    void msort(vector<BigInteger>& arr, vector<BigInteger>& tempArr, int left, int right) {
        //1、递归退出条件
        if(left==right) return;
        //2、对子问题进行分治
        int mid = (left + right)/2;
        msort(arr,tempArr,left,mid);//递归划分左半区域
        msort(arr,tempArr,mid+1,right);//递归划分右半区域
        //3、 合并结果，并返回
        return merge(arr,tempArr,left,mid,right);
    }

};

//int main() {
//    auto nums = rand_bigint_arr(20);
//    cout << "Before:" << nums << endl;
//    checkIsInOrder(nums);
//
//    MergeSort().sort(nums);
//    cout << "After:" << nums << endl;
//    checkIsInOrder(nums);
//    return 0;
//}