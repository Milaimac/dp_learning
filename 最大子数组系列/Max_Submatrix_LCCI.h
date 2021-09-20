// 最大子矩阵
#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h> //INT_MIN,INT_MAX
using namespace std;
/*
本题思路：
这道题和最大子序和的思想是一致的。
我认为本题最大的关键点就是如何存储左上角的坐标和右上角的坐标。要如何遍历这个矩阵才能使得完成这个目标？

我假想了许多情况。
第一种：很自然而然地就是按顺序遍历（就是先是同一行遍历其中的列），但是如果是这样的话，拿就不是子矩阵了。
为什么？ 假如有这样的矩阵
[
    [-1,0,2]
    [ 2,1,3]
    [2,2,3]
]

因为第一个是-1,很自然地舍弃掉这个数字，从第一行第二列的0开始，按照dp[i] = max(dp[i-1]+nums[i], nums[i])的方程，会一直到最后一个数字，那么左上角的最优选择是[0,1]?,显然不是，因为第一列还有正数，这么做会舍弃掉第一列的数字。所以完全不能使用这种遍历使得二维变成一维。

那么到底怎样才能使得子矩阵最大？也可以说怎么去计算子矩阵的和？
其实从刚刚的分析，子矩阵的必须从最上行到最下行然后按列累加起来。

为了解决得到最上行和最下行的坐标，我们必须在遍历得到最下行的坐标时，把最上行给固定住（有点像双指针）。
那么我们按设置两个行坐标。一个为i（最上行），一个为j（最下行），为了在用j（最下行）遍历时，能够得到从j到i行（同一列）的历史记录，我们使用一个数组b[m] (m表示m列)，去把第i和到第j行的同一列给累加起来，这样在处理第j行的时候，其实是在处理从i到j行的历史数据，这样我们才能实现从二维变一维。

对于下面这个矩阵
[
    [-1,0,2]
    [-2,-2,3]
    [2,3,4]
]

我们使用sum来表示子矩阵的和。使用最大子序和的思想，当sum<0时，就会舍弃掉，使用b[m]来存储历史记录。每次更新j时，要把sum清零。



*/
class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int n =matrix.size(),m = matrix[0].size();
        vector<int> ans(4);     //用来存储左上角和右上角的坐标
        int Maxsum = INT_MIN;
        vector<int> b(m, 0);
        int sum;
        int left_col, left_row; //用来存储左上角
        for(int i=0;i<n;i++){
            for(int t=0;t<m;t++){
                b[t] =0;
            }
            for(int j=i;j<n;j++){
                sum =0;
                for(int k=0;k<m;k++){
                    b[k] += matrix[j][k];
                    if(sum > 0){
                        sum += b[k];
                    }
                    else{
                        sum = b[k];
                        left_col = k;
                        left_row = i;
                    }
                    if(sum > Maxsum){
                        Maxsum = sum;
                        ans[0] = left_row;
                        ans[1] = left_col;
                        ans[2] = j;
                        ans[3] = k;
                    }
                }
            }
        }
        return ans;
    }
};