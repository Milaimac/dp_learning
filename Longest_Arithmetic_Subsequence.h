#include"head.h"
//1027. 最长等差数列
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        unordered_map<int, int> intmap;
        for(int i = 0;i<n;i++){
            intmap[A[i]] = i;
        }
        int Max = 1;
        unordered_map<int, int> longest;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                //并没有规定一定是递增或是递减的
                if(A[i] > A[j] && intmap.count(2*A[j]-A[i])){
                    int k = intmap[A[j]-(A[i]-A[j])];
                    if(k <= j){
                        longest[j*n + i] = longest[k*n + j] + 1;
                        Max = max(Max, longest[j*n + i]+2);
                    }
                }
                if(A[i] < A[j] && intmap.count(2*A[j]-A[i])){
                    int k = intmap[A[j] - (A[i]-A[j])];
                    if(k <= j){
                        longest[j*2*n+i] = longest[k*2*n+j]+1;
                        Max = max(Max, longest[j*2*n + i] + 2);
                    }
                }
            }
        }
        return Max;
    }

    int longestArithSeqLength_1(vector<int>& A) {
        //o(n^3)
        //直到后面两个数，就直到前面一个数，target = A[i]*2 - A[j];
        unordered_map<int,int> mp;
        int n = A.size();
        for(int i = n-1;i>=0;i--){
           mp[A[i]]= i; 
        }
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int target = A[i]*2 - A[j];
                for(int k=i-1;k>=0;k--){
                    if(A[k] == target){
                        dp[i][j] = dp[k][i] + 1;
                        break;
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }


    int longestArithSeqLength_2(vector<int>& A) {
        //直到后面两个数，就直到前面一个数，target = A[i]*2 - A[j];
        unordered_map<int,int> mp;
        int n = A.size();
        // vector<vector<int>> dp(n, vector<int>(n, 2));
        unordered_map<int, int> dp;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int target = A[i]*2 - A[j];
                if(mp.count(target)){
                    dp[i*n+j]  = dp[mp[target]*n+i] + 1;
                }
                ans = max(ans, dp[i*n+j]+2);
            }
            mp[A[i]] = i;
        }
        return ans;
    }

    int longestArithSeqLength_3(vector<int>& A) {
        //直到后面两个数，就直到前面一个数，target = A[i]*2 - A[j];
        unordered_map<int,int> mp;
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int target = A[i]*2 - A[j];
                if(mp.count(target)) dp[i][j] = dp[mp[target]][i] + 1;
                ans = max(ans, dp[i][j]);
            }
            mp[A[i]] = i;
        }
        return ans;
    }    
};