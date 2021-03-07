#include <iostream>
#include <vector>

    int maxSubArray(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int max_sum = nums[0];
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (sum <= 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }

            if (sum >= max_sum) {
                max_sum = sum;
            }
        }

        return max_sum;
    }