//
// Created by dgy on 2024/4/21.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
    bool dfs(const vector<vector<char>>& board, const string& word, vector<vector<bool>>& visited, int x, int y, int index) {
        if (index == word.size()) {
            return true;
        }
        for (int i = 0; i < 4; ++i) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= board.size() || nexty < 0 || nexty >= board[0].size()) continue;
            if (visited[nextx][nexty]) continue;
            if (board[nextx][nexty] == word[index]) {
                visited[nextx][nexty] = true;
                if (dfs(board, word, visited, nextx, nexty, index + 1)) {
                    return true;
                }
                visited[nextx][nexty] = false;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (dfs(board, word, visited, i, j, 1)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout << solution.exist(board, word);
}