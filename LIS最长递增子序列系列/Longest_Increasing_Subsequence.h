#include"head.h"
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = nums.size();
        vector<int> dp(length, 1);
        for(int i=1;i<length;i++){
            for(int j=0;j<i;j++){// 关键，不是说越靠后，它的递增子序列就越长。 所以j不能从i-1开始，而是要从0开始，然后不断更新dp[i]
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        auto max = max_element(dp.begin(), dp.end()); //其中，并不是越靠后，子序列越大
        return *max;
    }
};
