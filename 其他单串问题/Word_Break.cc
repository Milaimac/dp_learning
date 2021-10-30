#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// 139. 单词拆分
// 1. 不仅是字符串匹配， 还要确保能被空格分割， 也就是不能重叠
// 2. 要注意可以重用， wordDict的字符串

// 3. 这实际上是一个单串问题

// 动态转移， 通过将wordDict丢到unordered_set并使用find。
// 让string s的子串和wordDict进行匹配。 并给对应的dp[i]位置进行判定
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        int idx = 0;
        // for()
        auto wordDictSet = unordered_set<string> ();
        for(auto& str:wordDict)
        {
            wordDictSet.insert(str);
        }
        vector<int> dp(len+1);
        dp[0] = true;
        for(int i = 1;i <= len;++i)
        {
            for(int j = 0;j < i;++j)
            {
                // 从j开始， 如果j是dp[0]才能够继续继承dp状态
                if(dp[j] && wordDictSet.find(s.substr(j,i-j)) != wordDictSet.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }

};

int main()
{
    string s = "applepenapple";
    vector<string> worddict = {"apple", "pen"};
    Solution sl;
    sl.wordBreak(s, worddict);
}


// 还是继续使用dp把
// dp[i] 为s中对应下标匹配成功的情况？ 由于s.substr(postion, len) == postion, postion+len-1， 所以需要初始状态进行dp[0] = true;
// 如何进行动态规划状态转移方程， 
// 其中的边界要确定好， 从j开始到i是对应的一个字符串 ， 那么要设置为dp[i]而不是dp[i-1]是因为我们转移状态的时候是要设置一个字符串的开头， 而不是结尾
// 只要把能够匹配的分割点 设置出来， dp[i] = dp[j] 。这里的j是上一个分割点
// 假设找到一个数了， applepenapple， 其中的apple  --- apple pen apple ，而在pen的末尾才能够恰好继承pen开头的dp状态