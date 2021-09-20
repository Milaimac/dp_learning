#include"head.h"
// 368. 最大整除子集
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end()); //由于是无重复的，而且对顺序也没什么规定，所以通过排序简化问题
        //1.要找出最长的整除子集，找到之后通过递推将该子集算出来。
        vector<int> dp(len,1);
        int maxsize = 1;int maxval = dp[0];

        for(int i=1;i<len;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            if(maxsize < dp[i]){
                maxsize = dp[i];
                maxval = nums[i];
            }
            // maxsize = max(dp[i], maxsize);
        }


        vector<int> res;
        if(maxsize == 1){
            res.push_back(nums[0]);
            return res;
        }

        for(int i = len-1;i>=0 && maxsize>0;i--){
            if(dp[i] == maxsize && maxval%nums[i] == 0){
                res.push_back(nums[i]);
                maxval = nums[i];
                maxsize--;
            }
        }
        return res;
    }
};