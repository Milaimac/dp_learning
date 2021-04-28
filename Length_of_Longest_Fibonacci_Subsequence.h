#include"head.h"
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        unordered_set<int> S(arr.begin(), arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x = arr[j],y = arr[i]+arr[j];
                int length = 2;
                while(S.find(y) != S.end()){
                    int z = x+y;
                    x = y;
                    y = z;
                    ans=max(ans, ++length);
                }
            }
        }
        return ans>=3?ans:0;
    }
};