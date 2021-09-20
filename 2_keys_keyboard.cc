#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    int minSteps(int n) {
        // int Max = __INT_MAX__;
        int ans = __INT_MAX__;
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for(int i = 0;i<=n;++i){
            for(int j = 0;j<=n;++j){
                dp[i][j] = __INT_MAX__;
            }
        }

        dp[1][0] = 0;
        dp[1][1] = 1;
        for(int i = 2;i<=n;++i){
            int minindx = __INT_MAX__;
            for(int j = 0;j <= n/2;++j){
                dp[i][j] = dp[i-j][j] + 1; //paste
                minindx = min(minindx, dp[i][j]);
            }
            dp[i][j] = minindx + 1;
        }
        for(int i = 0;i <= n;++i){
            ans = min(ans, dp[n][i]);
        }
        return ans;
    }
};

// 此思路不知为何不行
class SolutionV1 {
public:
    int minSteps(int n) {
        int ans = __INT_MAX__;
        if(n == 1){
            return 0;
        }
        if(n <= 3){
            return n;
        }
        for(int i = 2;i*i <= n;i++){
            int curans =__INT_MAX__;
            if(n % i == 0){
                curans = n/i + i;
            }
            ans = min(ans, curans);
        }
        if(ans == 0){
            return n;
        }
        return ans;
    }
};

int main(){
    SolutionV1 sl;
    sl.minSteps(9);
}