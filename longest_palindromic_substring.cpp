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
