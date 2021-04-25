#include"head.h"
class Solution{
public:
//  该题和打家劫舍二不同的地方在于，选完之后的东西的左右会消失掉。
//  [1,2,3,4,5,6] ，如果是打家劫舍二，可以选三个数，但是如果是3n块披萨，则可以选两个。
    int calcualte(vector<int>& slices){
        int n = slices.size();
        int choose = (n+1)/3;
        vector<vector<int>> dp(n+1, vector<int>(choose+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=choose;j++){
                dp[i][j] = max(dp[i-1][j], (i-2>=0 ? dp[i-2][j-1]+slices[i]:0));
            }
        }
        return dp[n][choose];

    }
    int maxSizeSlices(vector<int>& slices){
        // int n = slices.size()
        vector<int> v1(slices.begin(), slices.end()-1);
        vector<int> v2(slices.begin()+1, slices.end());
        int ans1 = calcualte(v1);
        int ans2 = calcualte(v2);
        return max(ans1, ans2);
    }
};