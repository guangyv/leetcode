//
// Created by dgy on 2024/5/10.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p = 0, q = nums.size() - 1;
        for (int i = 0; i <= q; ++i) {
            if (nums[i] == 0) {
                swap(nums[p], nums[i]);
                ++p;
            } else if (nums[i] == 2) {
                swap(nums[q], nums[i]);
                --q;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,0,2,1,1,0};
    solution.sortColors(nums);
    for (int num : nums) {
        cout << num << ' ';
    }
}