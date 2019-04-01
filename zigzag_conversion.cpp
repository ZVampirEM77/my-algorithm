class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int *pos_array = new int[s.length()] {};
        bool increase = true;
        int row_num = 1;
        if (numRows == 1) {
            return s;
        }
        
        for (int i = 0; i < s.length(); i++) {
            pos_array[i] = row_num;
            
            if (row_num == numRows) {
                increase = false;
            } else if (row_num == 1) {
                increase = true;
            }
            
            if (increase) {
                row_num++;
            } else {
                row_num--;
            }
            
        }
        
        for (int i = 1; i <= numRows; i++) {
            for (int j = 0; j < s.length(); j++) {
                if (pos_array[j] == i) {
                    res.append(1, s[j]);
                }
            }
        }
        
        return res;
    }
};
