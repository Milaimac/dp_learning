//给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 

// 该问题可以拿去和爬楼梯进行比较，爬楼梯是排列问题， 该题为组合问题
#include"head.h"
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        for(int i=0;i<amount+1;i++){
            dp[i] = 0;
        }
        dp[0] = 1;
        for (int& coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};


// 