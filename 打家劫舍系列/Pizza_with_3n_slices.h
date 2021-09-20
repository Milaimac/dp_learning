#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h> //INT_MIN,INT_MAX
using namespace std;
class Solution{
public:
//  该题和打家劫舍二不同的地方在于，选完之后的东西的左右会消失掉。
//  [1,2,3,4,5,6] ，如果是打家劫舍二，可以选三个数，但是如果是3n块披萨，则可以选两个。
// 那么建立动态方程， dp[i][j] = max(dp[i-1][j], dp[i-2][j-1]+slices[i])
// dp[i][j] 表示的是前i个数，选择了j个的最大之和， dp[i-1][j]表示没有选择第i个数，而是选择了第i-1个。 dp[i-2][j-1] + slices[i]表示选这第i个，那么第i-1个不能选，则只能从前i-2个选择j-1个。
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


    // 优化方法，除了使用动态规划，也可以使用双向链表贪心的方法来解决这道题，对于一块披萨，要想拿=得最多，那首先肯定是拿最大的一块。
    // [8,9,8,1,2,3] 那么对于这一个数组，最大的是9，如果选择接下来只能选择3,加起来12。
    // 但是如果不选择9,而是选择了8,那么还可以选择8,加起来16，这才是最优的。 

    // 如果能够反悔就好了？ 怎么反悔，将第一步选择了9之后，如果直接删除了两个8,就失去了反悔的机会， 所以我们在删除了两个8的同时，还要把它们的信息留下来。

    // 在选取了9之后，将左右两个结点删除，并且将9修改成8 + 8 -9 = 7，那样我们还有机会反悔。当他反悔时， 9（一开始选的） + 8 + 8 - 9 = 16 ，则代表它舍弃了原来的选择。

    int maxSizeSlice_1(vector<int>& slices){
        int n = slices.size();
        int need = n/3;
        int ret = 0;
        for(int i=0;i<need;i++){
            int max_pos = (slices.begin(), slices.end()) - slices.begin();
            int max_left = (max_pos + slices.size() - 1)%slices.size();
            int max_right = (max_pos + slices.size() + 1)%slices.size();
            int dis = slices[max_right] + slices[max_left] - slices[max_pos];
            ret += slices[max_pos];
            slices[max_pos] = dis;
            slices.erase(slices.begin() + min(max_left, max_right));
            slices.erase(slices.begin() + max(max_left, max_right));
        }
        return ret;
    }

};


