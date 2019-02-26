class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        for (int i = 0; i < s.length(); i++) {
            string substr(1, s[i]);
            for (int j = i + 1; j < s.length(); j++) {
                if (substr.find_first_of(s[j]) == string::npos) {
                    substr += s[j];
                } else {
                    break;
                }
            }
            if (substr.length() > max_length) {
                max_length = substr.length();
            }
        }
        return max_length;
    }
};
