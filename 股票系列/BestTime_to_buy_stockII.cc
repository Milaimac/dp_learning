#include <vector>
#include <iostream>
using namespace std;

// 不同的是， 在一个数组中， 可以进行多次交易（可以再次购买）。当然不能同时
// 这里的想法就是贪心， 在最小的时候买入， 最大的时候卖出
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //int money = -prices[0];
        int money = 0;
        int minprice = prices[0];
        int maxprice = prices[0];
        for(auto& price : prices){
            if(price > maxprice){
                // 继续保持
                maxprice = price;
//                money = maxprice - minprice;
            }
            else{
                // 卖出， 买入更小的 
                // minprice = price;
                money += maxprice - minprice;
                minprice = price;
            }
            // money = maxprice - minprice;    
        }
        return money;
    }
};

// 想那么多不如确认是否是递增。 
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {   
        int ans = 0;
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
};





int main(){
    vector<int> vec = {7,1,5,3,6,4};
    Solution sl;
    cout << sl.maxProfit(vec) << endl;
}