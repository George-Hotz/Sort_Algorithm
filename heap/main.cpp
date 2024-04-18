#include <iostream>
#include <vector>
#include "heap.h"
using  namespace std;

int main(){

    vector<int> nums = {5,3,7,2,9,1,4,6};

    heap_queue hp(nums);
    cout << "----------" <<endl;
    hp.print_nums();
    cout << "----------" <<endl;
    hp.pop();
    hp.print_nums();
    cout << "----------" <<endl;
    hp.pop();
    hp.print_nums();
    cout << "----------" <<endl;
    hp.pop();
    hp.print_nums();
    cout << "----------" <<endl;
    hp.push(4);
    hp.print_nums();
    cout << "----------" <<endl;
    hp.push(2);
    hp.print_nums();
    cout << "----------" <<endl;
    return 0;
}