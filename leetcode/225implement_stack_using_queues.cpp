#include <queue>

class MyStack {
public:
  /** Initialize your data structure here. */
  MyStack() {
    top_ele = 0;
  }

  /** Push element x onto stack. */
  void push(int x) {
    top_ele = x;
    if (!queue2.empty()) {
      queue2.push(x);
    } else {
      queue1.push(x);
    }
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int res = top_ele;
    if (queue1.empty()) {
      if (queue2.empty()) {
        return 0;
      }

      while(!queue2.empty()) {
        if (queue2.size() > 1) {
          top_ele = queue2.front();
          queue1.push(top_ele);
        }
        queue2.pop();
      }
    } else {
      while(!queue1.empty()) {
        if (queue1.size() > 1) {
          top_ele = queue1.front();
          queue2.push(top_ele);
        }
        queue1.pop();
      }
    }
    return res;
  }

  /** Get the top element. */
  int top() {
    return top_ele;
  }

  /** Returns whether the stack is empty. */
  bool empty() {
    return (queue1.empty() && queue2.empty());
  }

private:
  std::queue<int> queue1;
  std::queue<int> queue2;
  int top_ele;
};

class MyStack2 {
public:
  /** Initialize your data structure here. */
  MyStack2() {
    top_ele = 0;
  }

  /** Push element x onto stack. */
  void push(int x) {
    top_ele = x;
    if (queue1.empty()) {
      queue1.push(x);
      while (!queue2.empty()) {
        queue1.push(queue2.front());
        queue2.pop();
      }
    } else {
      queue2.push(x);
      while(!queue1.empty()) {
        queue2.push(queue1.front());
        queue1.pop();
      }
    }
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    if (empty()) {return 0;}
    int res = 0;
    if (!queue1.empty()) {
      res = queue1.front();
      queue1.pop();
      top_ele = queue1.front();
    } else {
      res = queue2.front();
      queue2.pop();
      top_ele = queue2.front();
    }

    return res;
  }

  /** Get the top element. */
  int top() {
    return top_ele;
  }

  /** Returns whether the stack is empty. */
  bool empty() {
    return (queue1.empty() && queue2.empty());
  }

private:
  std::queue<int> queue1;
  std::queue<int> queue2;
  int top_ele;
};

class MyStack3 {
public:
  /** Initialize your data structure here. */
  MyStack3() {
  }

  /** Push element x onto stack. */
  void push(int x) {
    queue1.push(x);
    int i = 0;
    while(i < (queue1.size() - 1)) {
      queue1.push(queue1.front());
      queue1.pop();
      i++;
    }
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    if (queue1.empty())
      return 0;
    int res = queue1.front();
    queue1.pop();
    return res;
  }

  /** Get the top element. */
  int top() {
    return queue1.front();
  }

  /** Returns whether the stack is empty. */
  bool empty() {
    return queue1.empty();
  }

private:
  std::queue<int> queue1;
};
