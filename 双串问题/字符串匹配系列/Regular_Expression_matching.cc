#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 把s作为原字符串，  p是正则后的字符串、
// "." 匹配一个字符
// "*" 匹配零个或则多个前面的一个元素
// 感觉是做了第n遍了

// 先是设置dp数组的定义， dp[i] 就表示字符串s， 索引i之前的匹配度怎么样， 但是后来发现他要和字符串p匹配， 而对应的下标是不一样的， 
// 那么应该设置为 dp[i][j] 表示字符串 s[0 ... i] 和 p[0 ... j] 的匹配度

// 现在假设前面的都一致 
// 如果是 用p[j] "."  那么 s[i] == p[j]  , dp[i][j] = dp[i-1][j-1]
// 如果是 用p[j] "*" 那么假设 s = "aaabccb" p = "aaabc*b" 这个"*" 通配符， 是用来匹配p[j-1]这个数字的
// 匹配0次 dp[i] = dp[i][j-2]
// 那么 dp[i][j] = dp[i][j-2] or dp[i-1][j]    如果s[i] = p[j-1]

// apppp = ap*
// 如果是 "."

// 确定dp数组的初始状态
// 由于空字符串是可以匹配的， 那么就不能够设置dp[0][0] 下标为字符串的下标， 而是要设置成字符串的长度， 
// 那么最终答案为dp[m][n] 


// 在推理的时候我们是将 * 前面的字符分开来匹配的
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches  = [&](int i, int j)
        {
            if(i == 0)
            {
                return false;
            }

            if(p[j-1] == '.')
            {
                // 如果说是".*", 那么就是无懈可击
                return true;
            }

            return s[i-1] == p[j-1];
        };

        vector<vector<int>> dp(m+1, vector<int>(n+1));
        // 字符串为空的情况
        dp[0][0] = true;

        for(int i=0;i<=m;++i)
        {
            for(int j=1;j<=n;++j)   // 为什么j从1开始
            {
                // "*" 这个字符串是不行的，因为没有前缀, 所以不会给出这个示例
                // 所以才可以允许dp[i][j-2]
                if(p[j-1] == '*')
                {
                    // 如果数组使用bool， 就没法使用位运算
                    dp[i][j] |= dp[i][j-2];         // 将"a*" 看成一整块， 确认这个块之前是否匹配
                    if(matches(i, j-1))             // 如果是s[i-1] 和 p[j-2]匹配, 这里是p[j-1]为"*" ,那么j-2 就是前缀
                    {
                        dp[i][j] |= dp[i-1][j];     
                    }
                }
                else
                {   // 比较s[i-1] 和 p[j-1] ， 不需要比较s[i]和p[j]，若是不匹配， 自然为false
                    if(matches(i, j))   
                    {
                        dp[i][j] |= dp[i-1][j-1];
                    }
                }
            }
            // return dp[m][n];
        }
        return dp[m][n];
    }

    // 为什么要让dp中的i和j和 字符串s和p的i和j不同步
    // 是为了避免"*"这个字符串


};