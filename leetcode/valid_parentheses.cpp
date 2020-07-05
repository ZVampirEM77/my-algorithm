#include <unordered_map>

class Solution {
public:
  bool isValid(std::string s) {
    if (s.empty()) {
      return true;
    }

    char * stack = new char[s.size()];
    int stack_peek = -1;
    std::unordered_map<char, char> parentheses_set = {{')', '('},
                                                      {'}', '{'},
                                                      {']', '['}};
    for(int i = 0; i < s.size(); i++) {
      char parentheses_ele = s.at(i);
      // positive parenthes
      if (parentheses_set.find(parentheses_ele) == parentheses_set.end()) {
        stack[++stack_peek] = parentheses_ele;
      } else {
        if (stack_peek >= 0 &&
            stack[stack_peek] == parentheses_set[parentheses_ele]) {
          stack_peek--;
        } else {
          return false;
        }
      }
    }

    return stack_peek==-1;
  }
};
