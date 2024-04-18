#include <iostream>
#include <vector>

using  namespace std;

class heap_queue
{
public:
    heap_queue() = default;
    heap_queue(const vector<int> &m_nums);
    ~heap_queue();

    int top();
    void pop();
    void push(int num);
    void heapify(int i);
    void print_nums();

private:
    int m_size;
    int m_capacity;
    vector<int> m_nums;
};