#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> counter1, counter2;
        for (const auto & c : s) {
            counter1[c] += 1;
        }

        for (const auto & c : t) {
            counter2[c] += 1;
        }

        return counter1 == counter2;
    }

#define ARRAY_SIZE 26
    bool isAnagram2(string s, string t) {
        int counter1[ARRAY_SIZE] = {0};
        int counter2[ARRAY_SIZE] = {0};
        for (const auto & c : s) {
            counter1[c - 'a'] += 1;
        }

        for (const auto & c : t) {
            counter2[c - 'a'] += 1;
        }

        bool is_equal = true;
        int comp_idx = 0;

        while (is_equal && comp_idx < ARRAY_SIZE) {
            if (counter1[comp_idx] != counter2[comp_idx]) {
                is_equal = false;
            }

            comp_idx++;
        }

        return is_equal;
    }
};