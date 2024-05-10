//
// Created by dgy on 2024/5/10.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int left = 0;
        while (left < nums.size() && nums[left] == 0) {
            ++left;
        }
        int right = left + 1;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                swap(nums[left], nums[right]);
                ++left;
            }
            ++right;
        }
        while (left < nums.size() && nums[left] == 1) {
            ++left;
        }
        right = left + 1;
        while (right < nums.size()) {
            if (nums[right] == 1) {
                swap(nums[left], nums[right]);
                ++left;
            }
            ++right;
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