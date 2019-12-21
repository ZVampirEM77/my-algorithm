class Solution {
public:
    int expandAroundCenter(std::string s, int left, int right)
    {
        while(left >=0 && right < s.length())
        {
            if (s[left] == s[right]) {
                left --;
                right ++;
            } else {
                break;
            }
        }
        
        return (right - left - 1);
    }
    
    string longestPalindrome(string s) {
        int max = 0, start = 0;
        int len = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            len = std::max(len1, len2);
            if (max <= len) {
                max = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, max);
    }
};


class Solution {
public:
    string preparestring(string s) {
        string res;
        int res_index = 0;
        res.append(1, '$');
        for (int i = 0; i < s.length(); i++) {
            res.append(1, '#');
            res.append(1, s[i]);
        }
        res.append(1, '#');
        res.append(1, '$');
        return res;
    }

    string longestPalindrome(string s) {
        int max_index = 0, max_range = 0;
        int start = 0, end = 0;
        int max_start = 0, max_len = 0;
        string prepared_str = preparestring(s);
        int n = prepared_str.length();
        int *p = new int[n] ();
        for(int j = 1; j < prepared_str.length(); j++) {
            if (j >= max_range) {
                start = j;
                end = j;
                while (prepared_str[start] == prepared_str[end] && prepared_str[start] != '$' ) {
                    p[j] += 1;
                    start--;
                    end ++;
                }
            } else {
                p[j] = std::min(p[2 * max_index - j], max_range - j + 1);
                start = j - p[j];
                end = j + p[j];
                while (prepared_str[start] == prepared_str[end] && prepared_str[start] != '$') {
                    p[j] += 1;
                    start--;
                    end++;
                }
            }

            if (p[j] > max_len) {
                max_len = p[j];
                max_start = (j - max_len) / 2;
            }

            if (p[j] > max_range - j + 1) {
                max_index = j;
                max_range = j + p[j] - 1;
            }
        }

        return s.substr(max_start, max_len - 1);
    }
};
