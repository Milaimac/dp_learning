#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h> //INT_MIN,INT_MAX
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
