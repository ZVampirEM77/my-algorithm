class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> res;
        for (std::vector<int>::iterator iter = nums.begin();
             iter < nums.end(); iter++) {
            int may_result = target - *iter;
            auto result_iter = std::find(iter + 1, nums.end(), may_result);
            if (result_iter != nums.end())
            {
                int one_index = std::distance(nums.begin(), iter);
                int another_index = std::distance(nums.begin(), result_iter);
                res.push_back(one_index);
                res.push_back(another_index);
            }
        }
        return res;
    }
};
