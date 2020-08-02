#include <iostream>
#include <vector>
#include <deque>
#include <set>

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    if (nums.empty() || nums.size() < k) {
        return std::vector<int>();
    }

    std::vector<int> res;
    std::deque<int> window;

    for (int i = 0; i < nums.size(); i++) {
        int ele_val = nums[i];
        if (i >= k && window[0] <= i - k) {
            window.pop_front();
        }

        while (!window.empty() && nums[window.back()] <= ele_val) {
            window.pop_back();
        }

        window.push_back(i);

        if (i >= k - 1) {
            res.push_back(nums[window[0]]);
        }
    }

    return res;
}

std::vector<int> maxSlidingWindow2(std::vector<int>& nums, int k) {
    if (nums.empty() || nums.size() < k) {
        return std::vector<int>();
    }

    std::vector<int> res;
    std::multiset<int> window;

    for (int i = 0; i < nums.size(); i++) {
        if (i < k - 1) {
            window.insert(nums[i]);
        } else {
            if (i > k - 1) {
                window.erase(window.find(nums[i - k]));
            }

            window.insert(nums[i]);
            res.push_back(*(window.rbegin()));
        }
    }

    return res;
}