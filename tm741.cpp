//
// Created by dgy on 2024/5/7.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n * 2 - 1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        dp[0][0][0] = grid[0][0];
        for (int k = 1; k < n * 2 - 1; ++k) {
            for (int x1 = max(k - n + 1, 0); x1 <= min(k, n - 1); ++x1) {
                int y1 = k - x1;
                if (grid[x1][y1] == -1) {
                    continue;
                }
                for (int x2 = x1; x2 <= min(k, n - 1); ++x2) {
                    int y2 = k - x2;
                    if (grid[x2][y2] == -1) {
                        continue;
                    }
                    int result = dp[k - 1][x1][x2];
                    if (x1) {
                        result = max(result, dp[k - 1][x1 - 1][x2]);
                    }
                    if (x2) {
                        result = max(result, dp[k - 1][x1][x2 - 1]);
                    }
                    if (x1 && x2) {
                        result = max(result, dp[k - 1][x1 - 1][x2 -1]);
                    }
                    result += grid[x1][y1];
                    if (x2 != x1) {
                        result += grid[x2][y2];
                    }
                    dp[k][x1][x2] = result;
                }
            }
        }
        return max(dp.back().back().back(), 0);
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{0,1,-1},{1,0,-1},{1,1,1}};
    int result = solution.cherryPickup(grid);
    cout << result;
}