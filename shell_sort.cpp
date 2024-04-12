#include <iostream>
#include <vector>
using  namespace std;


void print_nums(vector<int> &nums){
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << ' ';
    }
    cout << endl;
}

//时间复杂度：平均情况O(n^(1.3))，最好情况O(n),最坏情况O(n^2)
//空间复杂度：O(1)
//稳定性：不稳定
void shell_sort(vector<int> &nums){
    int len = nums.size();
    for(int step = len/2; step > 0; step /= 2){    //步长
        for(int i=step; i<len; i += step){
            int key = nums[i];
            int j = i - step;
            while(j >= 0 && key < nums[j]){
                nums[j+step] = nums[j];
                j -= step;
            }
            nums[j+step] = key;
        }
    }
}


int main(){
    vector<int> nums = {5,3,7,2,9,1,4,6};
    print_nums(nums);

    shell_sort(nums);

    print_nums(nums);
    return 0;
}