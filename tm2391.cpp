//
// Created by dgy on 2024/5/11.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char, int> distance;
        int res = 0, cur_dis = 0;
        for (int i = 0; i < garbage.size(); ++i) {
            res += garbage[i].size();
            if (i > 0) {
                cur_dis += travel[i - 1];
            }
            for (auto c : garbage[i]) {
                distance[c] = cur_dis;
            }
        }
        for (auto &[k, v] : distance) {
            res += v;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<string> garbage = {"G","P","GP","GG"};
    vector<int> travel = {2,4,3};
    cout << solution.garbageCollection(garbage, travel);
}