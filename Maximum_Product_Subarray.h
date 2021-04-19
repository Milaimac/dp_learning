#include"head.h"
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxF(nums), minF(nums);
        for(int i=1;i<n;++i){
            maxF[i] = max(maxF[i-1]*nums[i], max(nums[i]*minF[i-1], nums[i]));
            minF[i] = min(minF[i-1]*nums[i], min(nums[i]*maxF[i-1], nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
    //优化，
    int maxProduct1(vector<int>& nums){
        int n = nums.size();
        int Max = INT32_MIN;
        int imax = 1, imin =1;
        for(int i =0;i<n;i++){
            if(nums[i] < 0){
                // 当遇到小于0的情况
                //让imax和imin换位， 为什么？
                //因为要获得最小的负数，必须将之前最大的数和现在的数进行相乘， 而当下一次有偶个负数时，imax会获得最小的负数 和 现在的负数相乘，得到最大的数。
                int tmp = imax;
                imax = imin;
                imin = tmp;
            }
            imin = min(nums[i], nums[i]*imin);
            imax = max(nums[i], nums[i]*imax);

            Max = max(Max, imax);
        }
        return Max;
    }
};

/*
该题分析
由于负负得正，所以我们要把最小的状态也给存储下来， 然后进行比较。
*/