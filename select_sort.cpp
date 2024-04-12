#include <iostream>
#include <vector>
using  namespace std;

void print_nums(vector<int> &nums){
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << ' ';
    }
    cout << endl;
}

//时间复杂度：O(n^2)
//空间复杂度：O(1)
//稳定性：稳定
void select_sort(vector<int> &nums){
    int len = nums.size();
    for(int i=0; i<len; i++){
        int min_val = nums[i];
        int min_idx = i;
        for(int j=i+1; j<len; j++){
            //每次选出一个新的最小值，和对应下标
            if(nums[j] < min_val){
                min_val = nums[j];
                min_idx = j;
            }
        }
        swap(nums[min_idx], nums[i]);
    }
}

int main(){
    vector<int> nums = {5,3,7,2,9,1,4,6};
    print_nums(nums);

    select_sort(nums);

    print_nums(nums);
    return 0;
}