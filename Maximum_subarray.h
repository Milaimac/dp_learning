#include"head.h"    
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int maxm = nums[0];
        for(int i=1;i<n;i++){
            if(sum < 0){
                sum = nums[i];
                maxm = max(sum, maxm);
            }
            else{
                sum += nums[i];
                maxm = max(sum, maxm);
            }
        }
        return maxm;
    }
};