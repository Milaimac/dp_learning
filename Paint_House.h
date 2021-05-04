#include"head.h"
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // dp[i][j][k]: 前i个房子组成j个街区，且第i个房子的颜色为k，此时的最小花费
        // 房子∈[0, m-1]，街区∈[0, target]，颜色∈[0, n]
        int dp[m][target+1][n+1];
        memset(dp, 0x3f3f3f3f, sizeof(dp));

        // 初始化
        if(houses[0] == 0) {
            for(int k = 1; k <= n; k++)
                dp[0][1][k] = cost[0][k-1];
        }
        else
            dp[0][1][houses[0]] = 0;
        
        // 转移
        for(int i = 1; i < m; i++) {
            // 房子本身无颜色
            if(houses[i] == 0) {
                for(int cur_color = 1; cur_color <= n; cur_color++) {
                    for(int prv_color = 1; prv_color <= n; prv_color++) {
                        for(int j = 1; j <= target; j++) {
                            if(cur_color == prv_color)
                                dp[i][j][cur_color] = min(dp[i][j][cur_color], dp[i-1][j][cur_color] + cost[i][cur_color-1]);
                            else
                                dp[i][j][cur_color] = min(dp[i][j][cur_color], dp[i-1][j-1][prv_color] + cost[i][cur_color-1]);
                        }
                    }
                }
            }
            // 房子本身有颜色
            else {
                int cur_color = houses[i];
                for(int prv_color = 1; prv_color <= n; prv_color++) {
                    for(int j = 1; j <= target; j++) {
                        if(cur_color == prv_color)
                            dp[i][j][cur_color] = min(dp[i][j][cur_color], dp[i-1][j][cur_color]);
                        else
                            dp[i][j][cur_color] = min(dp[i][j][cur_color], dp[i-1][j-1][prv_color]);
                    }
                }
            }
        }
        int ans = *min_element(dp[m-1][target], dp[m-1][target]+n+1);
        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};

/*
解析：
要求
1、恰好组成target个街区
2、最小消费cost
3、有的房子本身有颜色，cost为0

考虑状态方程
动态转移的状态dp数组， 下标是状态， 值是该状态下的最优值
因此dp[i][j][cur_color] 表示的是第i个房子， 第j个街区， 第cur_color的颜色 
房子没有颜色的情况下,那就需要花费cost

if(cur_color == prv_color) //是同一个街区的情况
dp[i][j][cur_color] = min(dp[i-1][j][cur_color]+cost[i][cur_color-1], dp[i][j][cur_color]);

if(cur_color != prv_color)
dp[i][j][cur_color] = min(dp[i-1][j-1][prv_color]+cost[i][cur_color-1], dp[i][j][cur_color]);

如果房子有颜色
cur_color = house[i];
if(cur_color == prv_color)
dp[i][j][cur_color] = min(dp[i][j][cur_color], dp[i-1][j][cur_color])
if(cur_color != prv_color)
dp[i][j][cur_color] = min(dp[i][j][cur_color], dp[i-1][j-1][prv_color])

//note
要注意数组界限问题，首先要初始化dp的第一个元素 ，不然dp[i-1][...]就越界了
*/