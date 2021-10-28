#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    // 这道题很简单， 只要维护这个数组里面， 两个数的最大差值即可
    // 至于怎么使用动态规划来维护， 使用dpmax
    // 以及转移方程

    // 至于如何维护利润， 这里直接使用一个值， 维护其中最小的买入资金， 随后计算利润， 如果发现有更小的购入资金， 就假装之前没有买过
    int maxProfit(vector<int>& prices) {
        int money = -1;
        int minpirce = prices[0];
        for(auto& price:prices){
            if(price < minpirce){
                minpirce = price;
            }
            else{
                money = max(money, price-minpirce);
            }
        }
        return money;
    }
};