#include <iostream>
#include <string>
#include <algorithm>

    int palindromicStringlength(const std::string &s, int left, int right) {
        int l = left, r = right;
        while (l >=0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
    
        return r - l - 1;
    }

    std::string longestPalindrome(std::string s) {
        if (s.length() <= 1) {
            return s;
        }
    
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = palindromicStringlength(s, i, i);
            int len2 = palindromicStringlength(s, i, i + 1);
            int max_len = std::max(len1, len2);
            if (max_len > end - start + 1) {
                start = i - (max_len - 1) / 2;
                end = i + max_len / 2;
            }
        }
    
        return s.substr(start, end - start + 1);
    }

    std::string longestPalindrome(std::string s) {
        int str_len = s.length();
        if (str_len <= 1) {
            return s;
        }

        std::string longest_palindrome_substr;
        bool **is_palind_matrix = new bool*[str_len];
        for (int i = 0; i < str_len; i++) {
            is_palind_matrix[i] = new bool[str_len];
        }
        for (int i = str_len - 1; i>=0; i--) {
            for (int j = i; j < str_len; j++) {
                is_palind_matrix[i][j] = (s[i] == s[j] && (j - i < 3 || is_palind_matrix[i + 1][j - 1]));

                if (is_palind_matrix[i][j] && (j - i + 1) > longest_palindrome_substr.length()) {
                    longest_palindrome_substr = s.substr(i, j - i + 1);
                }
            }
        }

        return longest_palindrome_substr;
    }