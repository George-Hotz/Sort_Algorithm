#include <iostream>
#include <vector>
using  namespace std;

void print_nums(vector<int> &nums){
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << ' ';
    }
    cout << endl;
}

//维护大根堆
void heapify(vector<int> &nums, int len, int i){
    int largest = i;
    int l_son = i * 2 + 1;
    int r_son = i * 2 + 2;
    if(nums[largest] < nums[l_son] && l_son < len){
        largest = l_son;
    } 
    if(nums[largest] < nums[r_son] && r_son < len){
        largest = r_son;
    } 
    if(largest != i){
        swap(nums[largest], nums[i]);
        heapify(nums, len, largest);
    }
}


//时间复杂度：O(nlogn)

//稳定性：不稳定
void heap_sort(vector<int> &nums){
    int len = nums.size();
    int idx = ((len - 1) - 1) / 2;    //下标为i的节点的父节点为 (i-1)/2

    //建堆
    for(idx; idx >= 0; idx--){
        heapify(nums, len, idx);
    }

    //排序
    for(int i = len -1; i > 0; i--){
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }

}

int main(){

    vector<int> nums = {5,3,7,2,9,1,4,6};

    print_nums(nums);
    
    heap_sort(nums);

    print_nums(nums);
    return 0;
}