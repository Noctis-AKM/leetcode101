#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1);
        dp[0] = 0;
        for (int i = 1; i <= num; ++i) {
            if (i & 1) {
                dp[i] = dp[i - 1] + 1;
            } else
                dp[i] = dp[i >> 1];
        }
        return dp;
    }
};