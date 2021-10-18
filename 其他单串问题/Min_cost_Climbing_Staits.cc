#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 0;
        // 要做到cost和dp的时序同步。
        // dp的初始化条件， 要注意dp的初始化条件， 要到达第0个阶梯， 那么便是0就可以到达
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};


int main()
{
    vector<int> cost = {10, 15, 20};
    Solution sl;
    cout << sl.minCostClimbingStairs(cost) << endl;

}