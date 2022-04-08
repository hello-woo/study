/**
 * @file 圆环回原点问题.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 圆环上有10个点，
 * 编号为0~9。从0点出发,
 * 每次可以逆时针和顺时针走一步，
 * 问走n步回到0点共有多少种走法。
 */

/**
 * @brief 
 * dp[i][j] :从原点出发走i步到点j的方案数量dp[n][0]，即为答案
 * 走i步到0的方案数 = 走i-1步到9的数量 + 走i- 1步到1的数量
 * dp[i][j] = dp[i - 1][(j - 1) % length] + dp[i + 1][(j + 1) % length]
 * 输入：4
 * 输出：6
 * 分别为0-1-2-1-0;0-9-8-9-0;0-1-0-9-0;
 * 0-9-0-1-0;0-1-0-1-0;0-9-0-9-0;
 */

#include<bits/stdc++.h>

using namespace std;

const int N = 40005;
int dp[N][10];

int getNums(int n){
    int len = 10;
    dp[0][0] = 1;
    // dp[1][0] = 0;
    // dp[2][0] = 2;
    for(int i = 1; i <= n;i++){
        for(int j = 0;j < 10;j++){
            dp[i][j] = dp[i - 1][(j + 1) % len] + dp[i - 1][(j + len - 1) % len];
        }
    }
    return dp[n][0];
}

int main(){
    int n ;
    cin >> n;
    cout << getNums(n) << endl;
    return 0;
}