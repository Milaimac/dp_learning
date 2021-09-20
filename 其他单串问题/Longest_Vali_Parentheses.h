// 最长有效括号
#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h> //INT_MIN,INT_MAX
using namespace std;
class Solution {
public:
    //动态规划版本， 该题要求的回答的是最长括号的长度，所以我们只要考虑连续状态下括号的长度。
    //我们分别考虑两种情况，
    /*
    1. ()()()  
    2. ((()))
    3. ()((()))
    思考：
    对上面两种情况如何做状态转移
    
    1. 遇到 ) 时， dp[i] = dp[i-2] + 2
    2. 遇到嵌套连续的括号 dp[i] = dp[i-1] + 2
    3. 但是遇到组合的情况， dp[i] = dp[i-1] + dp[i-dp[i-1]-2]，回到非嵌套情况。

    */
    int longestValidParentheses(string s) {
        int maxm = 0, n = s.size();
        vector<int> dp(n, 0);
        for(int i=1;i<n;i++){
            if(s[i] == ')'){
                if(s[i-1] == '('){
                    dp[i] = (i>=2 ? dp[i-2]:0)+2; // 连续
                }
                if(i-dp[i-1] > 0 && s[i-dp[i-1]-1] == '('){
                    dp[i] = dp[i-1] + (i-dp[i-1] >= 2 ? dp[i-dp[i-1]-2]:0)+2;
                }
                maxm = max(dp[i], maxm);
            }
        }
        return maxm;
    }
    // 栈版本。
    //使用栈将前面‘（’的坐标给存下来，
    //难点： 如何将())))()()这种情况下，将))))的index递推到后面去。
    int longestValidParentheses_1(string s) {
        stack<int> stk;
        stk.push(-1);
        int res;
        int n = s.size();
        for(int i=0;i<n;i++){
            stk.pop();
            if(s[i] == '('){
                stk.push(i);
            }
            if(stk.empty()){
                stk.push(i);
            }
            res = max(res, i-stk.top());
        }
        return res;
    }
};
