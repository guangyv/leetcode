//
// Created by dgy on 2024/5/10.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                swap(nums[p], nums[i]);
                ++p;
            }
        }
        for (int i = p; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                swap(nums[p], nums[i]);
                ++p;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 0};
    solution.sortColors(nums);
    for (int num : nums) {
        cout << num << ' ';
    }
}