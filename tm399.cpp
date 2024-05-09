//
// Created by dgy on 2024/4/22.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<string, unordered_map<string, double>> graph;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        vector<double> result(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i) {
            string start = queries[i][0];
            string end = queries[i][1];
            if (graph.count(start) == 0 || graph.count(end) == 0) {
                continue;
            }
            if (start == end) {
                result[i] = 1.0;
                continue;
            }
            queue<pair<string, double>> que;
            que.push({start, 1.0});
            while (!que.empty()) {
                
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0,3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    solution.calcEquation(equations, values, queries);
}