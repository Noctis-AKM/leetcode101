//
// Created by akio on 2021/2/16.
//
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int search(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            if (nums[m] < nums[r]) {
                if (nums[m] < target && nums[r] >= target) l = m + 1;
                else r = m - 1;
            } else  {
                if (nums[m] > target && nums[l] <= target) r = m - 1;
                else l = m + 1;
            }
        }
        return -1;
    }
};