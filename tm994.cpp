//
// Created by dgy on 2024/4/20.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int xinxian = 0;
        queue<pair<int, int>> fulan;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ++xinxian;
                } else if (grid[i][j] == 2) {
                    fulan.push({i, j});
                }
            }
        }
        int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
        int time = -1;
        while (!fulan.empty()) {
            int size = fulan.size();
            ++time;
            for (int i = 0; i < size; ++i) {
                int curx = fulan.front().first;
                int cury = fulan.front().second;
                fulan.pop();
                for (int i = 0; i < 4; ++i) {
                    int nextx = curx + dir[i][0];
                    int nexty = cury + dir[i][1];
                    if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) {
                        continue;
                    }
                    if (grid[nextx][nexty] == 1) {
                        grid[nextx][nexty] = 2;
                        fulan.push({nextx, nexty});
                        --xinxian;
                    }
                }
            }
        }
        return time;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int result = solution.orangesRotting(grid);
    cout << result;
}