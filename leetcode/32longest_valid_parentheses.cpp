#include <iostream>
#include <string>
#include <stack>

    bool isValid(std::string s) {
        std::stack<char> char_stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                char_stack.push('(');
            } else {
                if (!char_stack.empty() && char_stack.top() == '(') {
                    char_stack.pop();
                } else {
                    return false;
                }
            }
        }

        return char_stack.empty();
    }
    
    int longestValidParentheses(std::string s) {
        int max_len = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 2; j <= s.length(); j = j + 2) {
                int str_len = j - i;
                if (isValid(s.substr(i, str_len))) {
                    if (max_len < str_len) {
                        max_len = str_len;
                    }
                } 
            }
        }

        return max_len;
    }

    int longestValidParentheses(std::string s) {
        int max_len = 0;
        int str_len = s.length();
        int *valid_len = new int[str_len];
        for (int i = 0; i < str_len; i++) {
            valid_len[i] = 0;
        }

        for (int i = 1; i < str_len; i++) {
            if (s[i] == '(') {
                continue;
            }

            if (s[i - 1] == '(') {
                valid_len[i] = (i - 2 >= 0 ? valid_len[i - 2] : 0) + 2;
            } else {
                if (i - valid_len[i - 1] > 0 && s[i - valid_len[i - 1] - 1] == '(') {
                    valid_len[i] = valid_len[i - 1] +
                                   (i - valid_len[i - 1] - 2 >= 0 ? valid_len[i - valid_len[i - 1] - 2] : 0) + 2;
                }
            }
            std::cout << "i = " << i << std::endl;
            if (max_len < valid_len[i]) {
                max_len = valid_len[i];
            }
        }

        return max_len;
    }

    int longestValidParentheses(std::string s) {
        int max_len = 0;
        std::stack<int> index_stack;
        index_stack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                index_stack.push(i);
            } else {
                index_stack.pop();
                // if index_stack is empty, the palindrome is valid
                if (index_stack.empty()) {
                    index_stack.push(i);
                    continue;
                }

                int pair_index = index_stack.top();
                if (max_len < i - pair_index) {
                    max_len = i - pair_index;
                }
            }
        }

        return max_len;
    }

    int longestValidParentheses(std::string s) {
        int left = 0;
        int right = 0;
        int max_len = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }

            if (left == right) {
                if (max_len < 2 * right) {
                    max_len = 2 * right;
                }
            } else if (right > left) {
                left = 0;
                right = 0;
            }
        }

        left = 0;
        right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }

            if (left == right) {
                if (max_len < 2 * left) {
                    max_len = 2 * left;
                }
            } else if (left > right) {
                left = 0;
                right = 0;
            }
        }

        return max_len;
    }

    int main() {
        std::string test_str = ")()())";
        std::cout << longestValidParentheses(test_str) << std::endl;

        return 0;
    }