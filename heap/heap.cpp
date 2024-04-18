#include <iostream>
#include <vector>
#include "heap.h"

using  namespace std;

heap_queue::heap_queue(const vector<int> &nums)
{
    this->m_nums = nums;
    this->m_size = nums.size();
    this->m_capacity = nums.capacity();
    if(m_size){
        int idx = ((m_size - 1) - 1) / 2;    
        //建堆
        for(idx; idx >= 0; idx--){
            heapify(idx);
        }
    }
}

heap_queue::~heap_queue()
{

}


//维护小根堆
void heap_queue::heapify(int i){
    int smallest = i;
    int l_son = i * 2 + 1;
    int r_son = i * 2 + 2;

    if(m_nums[smallest] > m_nums[l_son] && l_son < m_size){
        smallest = l_son;
    } 
    if(m_nums[smallest] > m_nums[r_son] && r_son < m_size){
        smallest = r_son;
    } 
    if(smallest != i){
        swap(m_nums[smallest], m_nums[i]);
        heapify(smallest);
    }
}

int heap_queue::top(){
    return m_nums[0];
}

void heap_queue::pop(){
    if(!m_size){
        return;
    }

    // for(int i=1; i<m_size; i++){
    //     m_nums[i-1] = m_nums[i];
    // }
    // m_size--;
    // m_nums.pop_back();
    // heapify(0);

    m_nums[0] = m_nums[--m_size];
    m_nums.pop_back();
    heapify(0);
    

}

void heap_queue::push(int num){
    if(m_capacity <= m_size){
        m_nums.resize(2*m_capacity);
        m_capacity *= 2;
    }

    m_nums[m_size] = num;

    int son = m_size++;
    int parent = (son - 1)/2;

    for(int i=parent; i>=0 ; i--){
        heapify(i);
    }
}


void heap_queue::print_nums(){
    for(int i=0; i<m_size; i++){
        cout << m_nums[i] << ' ';
    }
    cout << endl;
}


