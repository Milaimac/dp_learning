// 最大子矩阵
#include"head.h"

class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int n =matrix.size(),m = matrix[0].size();
        vector<int> ans(4); //用来存储左上角和右上角
        int Maxsum = INT_MIN;
        vector<int> b(m, 0);
        int sum;
        int left_col, left_row;
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