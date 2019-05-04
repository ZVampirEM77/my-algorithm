class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        std::string x_str = std::to_string(x);
        for (int i = 0, j = x_str.length() - 1; i <= j; i++, j--) {
            if (x_str[i] != x_str[j]) {
                return false;
            }
        }
        
        return true;
    }
};
