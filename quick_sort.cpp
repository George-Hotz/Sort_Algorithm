#include <iostream>
#include <vector>
#include <map>
using  namespace std;


void print_nums(vector<int> &nums){
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << ' ';
    }
    cout << endl;
}


//单排
int split_1(vector<int> &nums, int start, int end){
    int index = (rand() % (end - start + 1)) + start;
    int pivot = nums[index];
    
    swap(nums[index], nums[end]);

    int slow = start;    //慢指针
    int fast = start;    //快指针
    for(fast; fast<end; fast++){
        //把小于pivot的靠在左边一起
        if(nums[fast] < pivot){
            swap(nums[fast], nums[slow++]);
        }
    }

    swap(nums[slow], nums[end]);
    return slow;
}

void quick_sort(vector<int> &nums, int start, int end){
    if(start < end){
        int mid = split_1(nums, start, end);
        quick_sort(nums, start, mid-1);
        quick_sort(nums, mid+1, end);
    }
}


int main(){
    vector<int> nums = {5,3,7,2,9,1,4,6};
    print_nums(nums);

    quick_sort(nums, 0, nums.size()-1);

    print_nums(nums);
    return 0;
}


