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

//时间复杂度：O(n)
//空间复杂度：O(n)
//稳定性：稳定
void count_sort(vector<int> &nums){
    int len = nums.size();
    map<int, int> cnt_map;
    for(auto num : nums){
        cnt_map[num]++;
    }
    int idx = 0;
    auto it = cnt_map.begin();
    for(it; it != cnt_map.end(); it++){
        int val = it->first;
        int len = it->second;
        for(int i=0; i<len; i++){
            nums[idx++] = val;
        }
    }
}


int main(){
    vector<int> nums = {5,3,7,2,9,1,4,6};
    print_nums(nums);

    count_sort(nums);

    print_nums(nums);
    return 0;
}