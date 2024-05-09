//
// Created by dgy on 2024/4/21.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j]) {
                    if (j == i || j == i + 1) {
                        ++result;
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) {
                        ++result;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s = "abc";
    cout << solution.countSubstrings(s);
}