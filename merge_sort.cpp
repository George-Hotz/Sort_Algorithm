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


void merge(vector<int> &nums, vector<int> &tmp, int left, int mid, int right){
    int l_idx = left;
    int r_idx = mid + 1;
    int t_idx = 0;
    
    while(l_idx <= mid && r_idx <= right){
        if(nums[l_idx] < nums[r_idx]){
            tmp.push_back(nums[l_idx++]);
        }
        if(nums[l_idx] > nums[r_idx]){
            tmp.push_back(nums[r_idx++]);
        }
    }

    while(l_idx <= mid){
        tmp.push_back(nums[l_idx++]);
    }

    while(r_idx <= right){
        tmp.push_back(nums[r_idx++]);
    }

    for(int i=left; i<=right; i++){
        nums[i] = tmp[t_idx++];
    }
    tmp.clear();
}


void merge_sort(vector<int> &nums, vector<int> &tmp, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        merge_sort(nums, tmp, left, mid);
        merge_sort(nums, tmp, mid+1, right);
        merge(nums, tmp, left, mid, right);
    }
}


int main(){
    vector<int> nums = {5,3,7,2,9,1,4,6};
    vector<int> tmp;

    print_nums(nums);

    merge_sort(nums, tmp, 0, nums.size()-1);

    print_nums(nums);
    return 0;
}


