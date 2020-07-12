#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        heap_size = k;
        for (auto iter : nums) {
            add(iter);
        }
    }
    
    int add(int val) {
        if (mini_heap.size() < heap_size) {
            mini_heap.push(val);
        } else if (mini_heap.top() < val) {
            mini_heap.pop();
            mini_heap.push(val);
        }

        return mini_heap.top();
    }

private:
    std::priority_queue<int, vector<int>, greater<int>> mini_heap;
    int heap_size;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {
    std::vector<int> init_nums = {4, 5, 8, 2};
    KthLargest * ins = new KthLargest(3, init_nums);

    std::cout << "add(3) " << ins->add(3) << std::endl;
    std::cout << "add(5) " << ins->add(5) << std::endl;
    std::cout << "add(10) " << ins->add(10) << std::endl;
    std::cout << "add(9) " << ins->add(9) << std::endl;
    std::cout << "add(4) " << ins->add(4) << std::endl;

    return 0;
}