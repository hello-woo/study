class Solution {
public: 
/* 贪心算法：每次在最低点买入，即buy = prices[i] + fee;
卖出有几种情况：
（1）if(prices[i] > buy)  那么能够获利，不一定是最大获利，可以等价于此时买入了prices[i]的股票，
此时：profit += prices[i] - buy, buy = prices[i]; 当后面prices[i]大的时候可以持续获利。

（2） prices[i] + fee < buy ,说明可以更新买入的价格，

（3） prices[i] 在[buy - fee ,buy]之间的时候，卖出不获利，买入也不是最低，不做操作

 */
    int maxProfit(vector<int>& prices, int fee) {
        int buy = prices[0] + fee;
        int ans = 0;
        for(int i = 1 ;i < prices.size();i++){
            if(prices[i] + fee < buy){
                buy = prices[i] + fee;
            }else if(prices[i] > buy){
                ans += prices[i] - buy;
                buy = prices[i];
            }
        }
        return ans;
    }
};