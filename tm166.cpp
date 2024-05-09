//
// Created by dgy on 2024/5/7.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        int n = frame.size(), m = frame[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = frame[0][0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i - 1][0] + frame[i][0];
        }
        for (int j = 1; j < m; ++j) {
            dp[0][j] += dp[0][j - 1] + frame[0][j];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + frame[i][j];
            }
        }
        return dp[n - 1][m - 1];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> frame = {{1,2,5},{3,2,1}};
    int result = solution.jewelleryValue(frame);
    cout << result;
}