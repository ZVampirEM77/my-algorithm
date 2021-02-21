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

    int main() {
        std::string test_str = ")()())";
        std::cout << longestValidParentheses(test_str) << std::endl;

        return 0;
    }