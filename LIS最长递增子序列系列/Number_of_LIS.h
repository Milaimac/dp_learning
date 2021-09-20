#include"head.h"
// 相较于最长递增序列的那道题而言，该题还需要加个数组将最长递增序列的数量的状态也给存储出来。
// 这里使用counter
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int length = nums.size();
        vector<int> dp(length, 1);
        vector<int> counter(length, 1);
        for(int i=0;i<length;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    //在遍历先前的序列时，当有多个dp[j]相同时，这时候就会dp[j] + 1 = dp[i]，那么增加counter;
                    if(dp[j]+1 > dp[i]){
                        dp[i] = max(dp[i],dp[j] + 1);
                        counter[i] = counter[j];
                    }
                    else if(dp[j] + 1 == dp[i]){
                        counter[i] += counter[j];
                    }
                }
            }
        }

        int max = *max_element(dp.begin(), dp.end());
        int res = 0;
        for(int i=0;i<length;i++){
            if(dp[i] == max){
                res += counter[i];
            }
        }
        return res;
    }
};