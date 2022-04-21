/*
链接：https://www.nowcoder.com/questionTerminal/f97e99347cc24f6c8a7136766cfdc9bb?orderByHotValue=1&page=1&onlyReference=false&toCommentId=12410296
来源：牛客网

现在，这个游戏到了最后一关，这一关的等式很奇特：_+_+_+...+_=n
这里可以填任意多个正整数（甚至可能是1个），只要这些数的和等于n即可。
但是，有一个额外的限制，填入的所有数必须小于等于k，大于等于1，填入的数的最大值必须大于等于d。
请你计算，有多少个不同的等式满足这些限制。由于答案可能很大，请将答案mod(998244353)后输出。
*/

//题意：num ,[1,k],最填入数的最大值大于等于d;
/*
完全背包，重量为n,物品为【1，k】 && max(num) >= d;求排列数，即一个数必定为【d,k】,其他的数【1，k】

等价为【1，k】，和为n的总和 - 【1，d-1】和为n的总和
*/

#include<bits/stdc++.h>

using namespace std;

const int MOD  = 998244353;

//总和为n,物品为【1，y】的完全背包总数
long long  getnums(int n,int y){
    vector<long long >dp(n + 1,0);
    dp[0] = 1;
    //求排列数，先遍历背包，再遍历物品
    for(int i = 1;i <= n;i++){
        //遍历物品
        for(int j = 1 ;j <= y;j++){
            if(i >= j) dp[i] = (dp[i] + dp[i - j])%MOD;
        
        }
    }
    for(int i = 1 ;i <= n;i++){
        cout << dp[i] << ",";
    }
    return dp[n];
}

int main(){
    long long  n ,k ,d;
    cin >> n >> k >> d;
    long long  ans = getnums(n,k)- getnums(n,d - 1);
    ans = (ans + MOD) % MOD;
    cout << ans <<endl;
    return 0;
}