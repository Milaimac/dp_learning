#include"head.h"
class Solution {
public:
    int numDecodings(string s) {                                                        
        //该题关键在于，去加一和去继承
        //如果说发现能够独立成为一个数字，先让它继承s[i-1]的状态，发现能够和s[i-1]组成小于26的数字，那么再加一
        //怎么应对0的打扰
        // 直接将s[i-1]和s[i]转换为数字，看看在不在对应的区间上。
        int n = s.size();
        vector<int> dp(3,0);dp[0] = 1;
        s=" " +s;
        for(int i=1;i<=n;i++){
            int a = s[i]-'0'; int b = a+10*(s[i-1]-'0');
            dp[i%3]=0;//用滚动数组要清空之前的状态
            if(a>0&&a<=9){
                dp[i%3] += dp[(i-1)%3];
                // cout << dp[i%3] << endl;
            }
            if(b>=10&&b<=26){
                dp[i%3] += dp[(i-2)%3];
                // cout << dp[i%3]<< " d d" << endl;
            }
        }
        return dp[n%3];
    }
    
    public:
    int sum = 0;
    int numberOfArithmeticSlices_2(vector<int>& nums) {
        int len=nums.size();
        slices(nums, len-1);
        return sum;
    }
    int slices(vector<int>& nums, int i){
        //递归边界
        if(i<2){
            return 0;
        }
        int ap = 0;
        if(nums[i] - nums[i-1] == nums[i-1]-nums[i-2]){
            ap = 1+slices(nums, i-1);
            sum += ap;
        }
        else{
            slices(nums, i-1);
        }
        return ap;
    }



};