
#include <vector>
using namespace std;
// 从0  ---  n， 以0 -- i为左子树， i+1为右子数
// 设置 G[n] 为长度为n的二叉搜索树个数
// 设置 F[i][n] 为以i为节点, 长度为n的二叉搜索树个数

// 我们来构建依赖关系， 动态转移方程
// G[n] = sum (F[i][n] )with i 
// F[i][n] = G[n-i]xG[i]
// 那么 G[n] = sum(G[n-i] x G[i]) with i;
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n+1, 0);
        // 初始状态 节点数为0 或 1 ， 不同二叉树总数为1
        G[0] =  1;
        G[1] = 1;

        // 既然要实现笛卡尔积， 
        // 那么就要循环 n， n的变量是要改变的
        for(int i = 2;i<=n;++i)
        {
            for(int j=1;j<=i;++j)
            {
                // G[i] = G[i-j]*G[j];
                // 这里的i和j的边界条件非常重要
                G[i] += G[i-j]*G[j-1];
            }
        }

        return G[n];

    }
};