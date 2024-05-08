//
// Created by dgy on 2024/5/7.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> mem(n, vector<vector<int>>(m, vector<int>(m, -1)));
        function<int(int, int,int)> dfs = [&](int i, int j, int k) -> int {
            if (i == n || j < 0 || j >= m || k < 0 || k >= m) {
                return 0;
            }
            int& res = mem[i][j][k];
            if (res != -1) {
                return res;
            }
            for (int j2 = j - 1; j2 <= j + 1; j2++) {
                for (int k2 = k - 1; k2 <= k + 1; k2++) {
                    res = max(res, dfs(i + 1, j2, k2));
                }
            }
            res += grid[i][j] + (k != j ? grid[i][k] : 0);
            return res;
        };
        return dfs(0, 0, m - 1);
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    int result = solution.cherryPickup(grid);
    cout << result;
}