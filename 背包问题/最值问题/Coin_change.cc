#include <vector>
using namespace std;
// 322. 零钱兑换  不是01背包问题
//      coins是无限的， 是完全背包问题
//

// 时间复杂度 为O(nS)
// 空间复杂度 为O(S)
// 其中 n = coins.size()
//  S = amount;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount+1, Max);
        for(int i = 1; i <= amount;++i)
        {// 总量为amount
            for(int j = 0;j < coins.size();++j)
            {
                if(coins[j] <= i)   // 这里排除了那些 coints[j] 大于 i 的情况，全部钱比一个硬币还少
                {
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount] > amount ?  -1 : dp[amount];
        // 如果 说都大于amount，就是amount+1, 那么所有钱币都大于amount这个值，所以不能凑出来
    }
};