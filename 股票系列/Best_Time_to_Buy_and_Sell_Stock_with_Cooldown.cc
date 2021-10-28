#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    // f[i] 表示第i天结束之后的 累积最大收益
    // 加入了冷冻期这个概念
    // 所以将持有股票的状态， 化为3种
    // 目前持有一支股票， 对应的 累积最大收益 即为f[i][0];
    // 目前不持有任何股票， 并且处于冷冻期中， 对应的 [累积最大收益] 记为f[i][1]
    // 目前不持有任何股票， 并且没有处于冷冻期中，对应的 [累积最大收益] 记为f[i][2]

    // 状态转移， f[i][0] = max(f[i-1][0], f[i-1][2]-prices[i]); 购买今天的prices
    // f[i][1] = f[i-1][0] + prices[i]， i是第i天， 要加上当天卖出股票的正收益
    // f[i][2] = max(f[i-1][1], f[i-1][2])

    // 如果在最后一天还持有股票， 是没有意义的， 所以最终的答案应该是f[n-1][1] 和 f[n-1][2] 中的最大值
    // return max(f[n-1][1], f[n-1][2])
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3));
        // 如何初始化,购买股票是需要耗费金钱的

        dp[0][0] = -prices[0];
        for(int i = 1;i < n;++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]-prices[i]);         // 继续持有， 卖掉之后再重新购买
            dp[i][1] = dp[i-1][0] + prices[i];              // 处于冷冻期， 说明是昨天卖掉的， 那么要将卖出的钱放入口袋   
            dp[i][2] =  max(dp[i-1][2], dp[i-1][1]);        // 没有持有股票， 但也没有处于冷冻期， 1.是刚刚结束冷冻期， 2. 不想买
        }
        return max(dp[n-1][1], dp[n-1][2]);
    }
};

// 进行空间优化
// 马尔可夫状态模型， 由于第i个状态只和 第i-1个状态有关， 所以我们存上一个状态就okl
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        int f0 = -prices[0];
        int f1 = 0;
        int f2 = 0;
        for (int i = 1; i < n; ++i) {
            int newf0 = max(f0, f2 - prices[i]);
            int newf1 = f0 + prices[i];
            int newf2 = max(f1, f2);
            f0 = newf0;
            f1 = newf1;
            f2 = newf2;
        }

        return max(f1, f2);
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        // int f0 = -prices[0];
        // int f1 = 0;
        // int f2 = 0;
        vector<int> dp(3);
        dp[0] = -prices[0];
        dp[1] = 0;
        dp[2] = 0;
        for(int i = 1;i < n;++i){
            int newdp0 = max(dp[0], dp[2]-prices[i]);
            int newdp1 = dp[0] + prices[i];
            int newdp2 = max(dp[1], dp[2]);
            dp[0] = newdp0;
            dp[1] = newdp1;
            dp[2] = newdp2;
        }
        return max(dp[1], dp[2]);
    }
};
