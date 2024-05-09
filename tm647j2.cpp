//
// Created by dgy on 2024/4/21.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int extend(string s, int i, int j) {
        int res = 0;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i;
            ++j;
            ++res;
        }
        return res;
    }
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            result += extend(s, i, i);
            result += extend(s, i, i + 1);
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s = "abc";
    cout << solution.countSubstrings(s);
}