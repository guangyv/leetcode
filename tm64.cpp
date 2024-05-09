//
// Created by dgy on 2024/4/21.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0) {
                    grid[i][j] = grid[i][j - 1] + grid[i][j];
                } else if (j == 0) {
                    grid[i][j] = grid[i - 1][j] + grid[i][j];
                } else {
                    grid[i][j] = min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j];
                }
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << solution.minPathSum(grid);
}