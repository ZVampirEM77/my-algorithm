#include <iostream>
#include <stack>

class MyQueue {
public:
  /** Initialize your data structure here. */
  MyQueue() {
  }

  /** Push element x to the back of queue. */
  void push(int x) {
    input_stack.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int res = peek();
    output_stack.pop();
    return res;
  }

  /** Get the front element. */
  int peek() {
    if (output_stack.empty()) {
      if (input_stack.empty()) {
        return 0;
      }

      while (!input_stack.empty()) {
        output_stack.push(input_stack.top());
        input_stack.pop();
      }
    }

    return output_stack.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    return (input_stack.empty() && output_stack.empty());
  }

private:
  std::stack<int> input_stack;
  std::stack<int> output_stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
