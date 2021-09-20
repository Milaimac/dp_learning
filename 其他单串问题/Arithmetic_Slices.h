#include"head.h"
class Solution {
public:
//暴力法，直接计算从s(start) 到e(end)的d是否符合，如果能到e，则可行。
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count = 0;
        int len = nums.size();
        for(int s=0;s<len-2;s++){
            int d = nums[s+1] - nums[s];
            for(int e=s+2;e<len;e++){
                int i=0;
                for(i=s+1;i<=e;i++){
                    if(nums[i]-nums[i-1] != d){
                        break;
                    }
                }
                if(i > e){
                    count++;
                }
            }
        }      
        return count;
    }
    //不需要重复判断从s到e区间的d是否相同，在区间增长到e+1的时候，只要判断e和e+1的差值d。
    int numberOfArithmeticSlices_1(vector<int>& nums) {
        int count = 0;
        int len = nums.size();
        for(int s = 0;s< len-2;s++){
            int d = nums[s+1] - nums[s];
            for(int e=s+2;e<len;e++){
                if(nums[e] - nums[e-1] == d){
                    count++;
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
    
    
};