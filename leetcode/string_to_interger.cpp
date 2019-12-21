class Solution {
public:
    string discard_whitespace(string& orig_str) {
        size_t pos = orig_str.find_first_not_of(" ");
        if (pos != string::npos)
            return orig_str.substr(pos);
        else
            return "";
    }
    
    bool is_char_vaild(char x) {
        if ((x < 48 && x != 45 && x != 43) ||
            x > 57) {
            return false;
        } else {
            return true;
        }
    }
    
    int myAtoi(string str) {
        long long res = 0;
        int label = 1;
        string no_whitespace_str = discard_whitespace(str);
        if (no_whitespace_str.empty() || !is_char_vaild(no_whitespace_str[0])) {
            return 0;
        }
        
        if (no_whitespace_str[0] == '-') {
            label = -1;
        } else if (no_whitespace_str[0] == '+') {
            label = 1;
        } else {
            res = no_whitespace_str[0] - 48;
        }
        
        for (int i = 1; i < no_whitespace_str.length(); i++) {
            if (no_whitespace_str[i] >= 48 && no_whitespace_str[i] <= 57) {
                res = res * 10 + (no_whitespace_str[i] - 48);
                if (label == 1 && res > INT_MAX) {
                    return INT_MAX;
                } else if (label == -1 && (res * label) < INT_MIN) {
                    return INT_MIN;
                }
            } else {
                break;
            }
        }
        
        return res * label;
    }
};
