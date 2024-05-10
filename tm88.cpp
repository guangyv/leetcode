//
// Created by dgy on 2024/5/10.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        for (int i = m + n - 1; i >= 0; --i) {
            if (p1 >= 0 && p2 >= 0) {
                if (nums1[p1] > nums2[p2]) {
                    nums1[i] = nums1[p1];
                    --p1;
                } else {
                    nums1[i] = nums2[p2];
                    --p2;
                }
            } else {
                if (p1 == -1) {
                    nums1[i] = nums2[p2];
                    --p2;
                } else if (p2 == -1) {
                    nums1[i] = nums1[p1];
                    --p1;
                }
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    solution.merge(nums1, m, nums2, n);
    for (auto num : nums1) {
        cout << num << ' ';
    }
}