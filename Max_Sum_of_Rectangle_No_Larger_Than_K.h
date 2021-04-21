#include"head.h"
class Solution {
public:
//  暴力，动态规划

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n =matrix.size();
        int m = matrix[0].size();
        int max = INT_MIN;
        int dp[n+1][m+1][n+1][m+1] = {0};


        for(int i1=1;i1<=n;i1++){
            for(int j1=1;j1<=m;j1++){
                dp[i1][j1][i1][j1] = matrix[i1-1][j1-1];
                for(int i2=i1;i2<=n;i2++){
                    for(int j2=j1;j2<=m;j2++){
                        dp[i1][j1][i2][j2] = dp[i1][j1][i2-1][j2] + dp[i1][j1][i2][j2-1] - dp[i1][j1][i2][j2] + matrix[i2][j2];
                        if(dp[i1][j1][i2][j2] <= k && dp[i1][j1][i2][j2] > max){
                            max = dp[i1][j1][i2][j2];
                        }
                    }
                }
            }
        }
        return max;
    }

// 优化方法，状态压缩
// 更换了左上角的i和j，之前记录的值就不会在使用了，指的是i1和j1之前的记录，那么每当重新遍历i和j时，要将dp重新构造。
//
    int maxSumSubmatrix_1(vector<vector<int>>& matrix, int k){
        int n = matrix.size(); int m = matrix[0].size();
        int max = INT_MIN;
        // int dp[n+1][m+1] = {0};

        for(int i1 =1;i1<=n;i1++){
            for(int j1=1;j1<=m;j1++){
                vector<vector<int>> dp(n+1,vector<int>(m+1,0));     
                dp[i1][j1] = matrix[i1-1][j1-1];
                for(int i2=i1;i2<=n;i2++){
                    for(int j2=j1;j2<=m;j2++){
                        dp[i2][j2] = dp[i2-1][j2] + dp[i2][j2-1] - dp[i2-1][j2-1] + matrix[i2-1][j2-1];
                        if(dp[i2][j2] <= k && dp[i2][j2] >  max){
                            max = dp[i2][j2];
                        }
                    }
                }
            }
        }
        return max;
    }
    int dpmax(vector<int>& b, int k){
        int maxm = INT_MIN;
        for(int l=0;l<b.size();l++){
            int sum =0;
            for(int r=l;r<b.size();r++){
                sum += b[r];
                if(sum > maxm && sum <= k)
                    maxm = sum;
            }
        }
        return maxm;

    }

    int maxSumSubmatrix_2(vector<vector<int>>& matrix, int k){
        int n = matrix.size();int m = matrix[0].size();
        int maxm = INT_MIN;
        for(int l=0;l<m;l++){
            vector<int> b(n,0);
            for(int r=l;r<m;r++){
                for(int j=0;j<n;j++){
                    b[j] += matrix[j][r];
                }
                maxm = max(maxm, dpmax(b,k));
            }
        }
        return maxm;
    }
};