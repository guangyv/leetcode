//
// Created by dgy on 2024/5/11.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        int slow = 2, fast = 2;
        while (fast < nums.size()) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,1,1,2,2,3};
    int size = solution.removeDuplicates(nums);
    for (int i = 0; i < size; ++i) {
        cout << nums[i] << ' ';
    }
}