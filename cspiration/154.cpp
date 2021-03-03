//
// Created by akio on 2021/2/17.
//
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r-l)/2;
            if(nums[m] > nums[r]) l =m + 1;
            else if(nums[m] < nums[r]) r = m;
            else --r;
        }
        return nums[r];
    }
};