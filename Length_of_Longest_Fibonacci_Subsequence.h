#include"head.h"
class Solution {
public:
    // 暴力法，对于每个起始对arr[i], arr[j]，我们都去计算y = arr[i] + arr[j]，如果y在数组中，则去跟新，x = y, y = x + y;
    // 算法复杂度 o(N^2 log(m))
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        unordered_set<int> S(arr.begin(), arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x = arr[j],y = arr[i]+arr[j];
                int length = 2;
                while(S.find(y) != S.end()){
                    int z = x+y;
                    x = y;
                    y = z;
                    ans=max(ans, ++length);
                }
            }
        }
        return ans>=3?ans:0;
    }

    // 使用动态规划
    int lenLongestFibSubseq_1(vector<int>& arr){
        int n = arr.size();
        unordered_map<int, int> index;
        for(int i=0;i<n;i++){
            index[arr[i]] = i;
        }

        unordered_map<int, int> longest;
        int ans =0;
        for(int k=0;k<n;k++){
            for(int j=0;j<k;j++){
                if(arr[k]-arr[j] < arr[j] && index.count(arr[k]-arr[j])){
                    int i = index[arr[k] - arr[j]];
                    longest[j*n + k] = longest[i*n+j] + 1; //这里使用了哈希的思想， 避免了longest[j+k] = longest[i+j] + 1的哈希冲突。
                    ans = max(ans, longest[j*n+k] + 2);
                }
            }
            return ans>3?ans:0;
        }
    }

    int longestArithSeqLength(vector<int>& A) {
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
};