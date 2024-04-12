#include <iostream>
#include <vector>
using  namespace std;

void print_nums(vector<int> &nums){
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << ' ';
    }
    cout << endl;
}

//时间复杂度：O(n^2)，最好O(n)
//空间复杂度：O(1)
//稳定性：稳定
void insert_sort(vector<int> &nums, const char* mode){
    int len = nums.size();
    if(mode == "swap"){      //数组元素交换的方式移动
        for(int i=1; i<len; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[j+1] < nums[j]){
                    swap(nums[j+1], nums[j]);
                }
            }
        }
    }

    if(mode == "cover"){     //数组元素覆盖的方式移动
        for(int i=1; i<len; i++){
            int key = nums[i];
            int j = i - 1;
            while(j >= 0 && nums[j] > key){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = key;
        }
    }

}


int main(){
    vector<int> nums = {5,3,7,2,9,1,4,6};
    print_nums(nums);

    insert_sort(nums, "cover");

    print_nums(nums);
    return 0;
}
