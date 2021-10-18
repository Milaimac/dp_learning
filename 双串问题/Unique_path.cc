#include <vector>
using namespace std;
class Solution {
public:
    // because the m and n <= 100 
    // 只能向下或者右移动

    // 先是想办法使用动规
    // dp[i][j] = max(dp[i-1][j], dp[i][j-1]

    // 注意：这个不是来求得走的步数的， 而是求路径总和
    // 那么 初始化条件基本上可以确定第一行和第一列必定是路径总和数为1
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));

        for(int i = 0;i<m;++i)
        {
            dp[i][0] = 1;
        }
        for(int j = 0;j < n;++j)
        {
            dp[0][j] = 1;
        }
        for(int i = 1;i<m;++i)
        {
            for(int j = 1;j<n;++j)
            {
                dp[i][j] = dp[i][j-1] + dp[i-1][j]; 
            }
        }
        return dp[m-1][n-1];
    }
};

