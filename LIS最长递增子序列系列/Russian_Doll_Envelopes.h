#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int num = envelopes.size();
        vector<int> dp(num, 1);
        // 没有顺序关系。所以给它排序。
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2){
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]); //当w相等时，不使用递增排序而是使用递减排序，这样就不用去规避w相等时，h呈现递增，将之算进递增子序列。
        });
        for(int i=1;i<num;i++){
            for(int j=0;j<i;j++){
                if(envelopes[j][1] < envelopes[i][1]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
/*
这道题的解题思路和最长递增序列类似， 其中的差别就是它是二维的。
所以我们先对w进行排序，然后再对h进行比较，如果发现满足envelopes[j][1] < envelopes[i][1]，那么dp[i] = max(dp[i],dp[j]+1);

*/