/**
 * @file lc_714含手续费最大利润.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-06
 *
 * @copyright Copyright (c) 2022
输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
输出：8
解释：能够达到的最大利润:  
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/**
 * @brief 
 * 贪心解法
 */

/* 贪心算法：每次在最低点买入，即buy = prices[i] + fee;
卖出有几种情况：
（1）if(prices[i] > buy)  那么能够获利，但不一定是最大获利，可以等价于此时买入了prices[i]的股票，
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

//解法二：

//dp[i][j] ：表示第i天状态为j得最大获利，j可以为0或者1

/*0:表示没有股票，1表示有股票
dp[i][0] = max(dp[i - 1][0],  dp[i - 1][1] + prices[i] - fee);
dp[i][1] = max(dp[i - 1][0] - prices[i],dp[i - 1][1]);
    */
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>>dp(n + 1,vector<int>(2,0));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for(int i =1 ;i < n;i++){
        dp[i][0] = max(dp[i - 1][0],  dp[i - 1][1] + prices[i] - fee);
        dp[i][1] = max(dp[i - 1][0] - prices[i],dp[i - 1][1]);
    }
    return dp[n - 1][0];
}