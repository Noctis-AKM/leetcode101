//
// Created by akio on 2021/2/18.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        for (int i = 1; s.length(); ++i) {
            if (s[i] == '+' && s[i - 1] == '+') {
                res.push_back(s.substr(0, i - 1) + "--" + s.substr(i + 1));
            }
        }
        return res;
    }
};