#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h> //INT_MIN,INT_MAX
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {    
        int sum,last_add,n,maxm;
        last_add = A[0], sum = last_add,n = A.size(),maxm = last_add;
        for(int i=1;i<n;i++){
            if(last_add < 0){
                last_add = A[i];
            }
            else{
                last_add += A[i];
            }
            maxm = max(maxm, last_add);
            sum += A[i];
        }

        int minm = 0;
        last_add = 0;

        for(int i=1;i<n-1;i++){
            if(last_add > 0){
                last_add = A[i];
            }
            else{
                last_add += A[i];
            }
            minm = min(minm, last_add);
        }
        return max(maxm, (sum -minm));
    }
    //这道题的难点是处理环形子数组的最大和。具体是分别对非环形数组和环形数组求其中的最大值， 
    //就拿[5,-3,5]这个经典测试用例来谈，非环形的最大子数组和为7，而环形的子数组和为10。
    // 那么如何求得环形子数组的最大和呢？
    // 将非环形的最小子数组算出来，然后在将整个数组的sum减去这个最小子数组大的和。

};