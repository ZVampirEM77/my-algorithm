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


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {  // -121
            return false;
        } else if (x < 10) {  // 1
            return true;
        } else if (x % 10 == 0) {  // 21120
            return false;
        }

        int cmp_x = 0;
        while (x > cmp_x) {
            cmp_x = cmp_x * 10 + (x % 10);
            x = x / 10;
        }

        if (cmp_x > x) {
            if (x != 0 && (cmp_x / 10) == x) {  // 10
                return true;
            }
        } else if (cmp_x == x) {
            return true;
        }

        return false;
    }
};
