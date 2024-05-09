//
// Created by dgy on 2024/4/21.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        vector<int> maxNums(nums), minNums(nums);
        for (int i = 1; i < nums.size(); ++i) {
            maxNums[i] = max({nums[i], maxNums[i - 1] * nums[i], minNums[i - 1] * nums[i]});
            result = max(result, maxNums[i]);
            minNums[i] = min({nums[i], maxNums[i - 1] * nums[i], minNums[i - 1] * nums[i]});
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,3,-2,4};
    cout << solution.maxProduct(nums);
}