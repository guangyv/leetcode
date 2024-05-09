//
// Created by dgy on 2024/4/21.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<string> result;
    string path;
    void backtracking(string& path, int n, int index, int cnt) {
        if (cnt == n) {
            result.push_back(path);
        }
        for (int i = index; i < n * 2; ++i) {
            if (i - cnt > cnt){
                return;
            }
            path[i] = '(';
            backtracking(path, n, i + 1, cnt + 1);
            path[i] = ')';
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        result.clear();
        path = string(n * 2, ')');
        backtracking(path, n, 0, 0);
        return result;
    }
};

int main() {
    Solution solution;
    int n = 0;
    vector<string> result = solution.generateParenthesis(n);
    for (string& str : result) {
        cout << str << endl;
    }
}