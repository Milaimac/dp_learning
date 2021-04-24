// #include"Longest_Increasing_Subsequence.h"
#include "Max_Sum_of_Rectangle_No_Larger_Than_K.h"
int main()
{
    Solution sl;
    vector<vector<int>> ivec = {{2,2,-1}};
    int res = sl.maxSumSubmatrix_1(ivec, 0);
    cout << res << endl;
    //cout <<INT_MIN << endl;

    // int n, m;
    // cin >> n >> m;
    // vector<vector<int>> dp(n, vector<int>(m, 0));
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         // cout <<dp[i][j] <<endl;
    //         dp[i][j] = 2;    
    //     }
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << dp[i][j] << endl;
    //         // dp[i][j] =2;
    //     }
    // }
}