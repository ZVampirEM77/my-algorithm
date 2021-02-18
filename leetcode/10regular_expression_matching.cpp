#include <iostream>
#include <string>


    bool isMatch(std::string s, std::string p) {
        if (p.empty()) {
            return s.empty();
        }
        // if first_matched is false, the recursive isMatch will not be called.
        bool first_matched = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (p.length() >= 2 && p[1] == '*') {
            // 1. first_matched is false, the first charactor is not matched
            // 2. first_matched is true, the first charactor is matched
            return (isMatch(s, p.substr(2)) ||
                    (first_matched && isMatch(s.substr(1), p)));
        } else {
            return first_matched && isMatch(s.substr(1), p.substr(1));
        }
    }

    // Dynamic Programming
    // dp[i][j] means the string(i:) and string[j:] is matched
    bool isMatch(std::string s, std::string p) {
        int s_len = s.length(), p_len = p.length();
        bool matched[s_len + 1][p_len + 1];
        memset(matched, 0, sizeof(bool) * (s_len + 1) * (p_len + 1));

        matched[s_len][p_len] = true;
        for (int i = s_len; i >= 0; i--) {
            for (int j = p_len - 1; j >= 0; j--) {
                bool is_matched = (i < s_len && (s[i] == p[j] || p[j] == '.'));
                if (j + 1 < p_len && p[j + 1] == '*') {
                    matched[i][j] = (matched[i][j + 2] || (is_matched && matched[i + 1][j]));
                } else {
                    matched[i][j] = (is_matched && matched[i + 1][j + 1]);
                }
            }
        }

        return matched[0][0];
    }