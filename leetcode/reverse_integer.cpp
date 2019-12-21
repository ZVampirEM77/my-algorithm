class Solution {
public:
    int reverse(int x) {
        const int range = (1 << 31) * (-1);
        string positive_limit = std::to_string(range * (-1) - 1);
        string negative_limit = std::to_string(range);
        string s = std::to_string(x);
        string limit = x >= 0 ? positive_limit : negative_limit;
        
        string reversed_res;
        string lable = x >= 0 ? "" : "-";
        string orig_str = x >= 0 ? s : s.substr(1);
        reversed_res.append(orig_str.rbegin(), orig_str.rend());
        reversed_res.insert(0, lable);
        
        if (reversed_res.length() > limit.length() ||
            ((reversed_res.length() == limit.length()) &&
              reversed_res > limit)) {
            return 0;
        }
        
        int res = std::stoi(reversed_res);
        
        return res;
    }
};

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        do {
            res = res * 10 + x % 10;
            x /= 10;
        } while (x);

        return (res < INT_MIN || res > INT_MAX) ? 0 : res;
    }
};
