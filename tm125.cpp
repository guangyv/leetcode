//
// Created by dgy on 2024/5/11.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (!(isalpha(s[left]) || isdigit(s[left]))) {
                ++left;
                continue;
            } else if (!(isalpha(s[right]) || isdigit(s[right]))) {
                --right;
                continue;
            } else if (tolower(s[left]) == tolower(s[right])) {
                ++left;
                --right;
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s = "0P";
    cout << solution.isPalindrome(s);
}