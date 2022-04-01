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
            if(i >= j) dp[i] = dp[i]% MOD + dp[i - j] %MOD;
        
        }
    }
    /*for(int i = 0 ;i < n;i++){
        cout << dp[i] << ",";
    }*/
    return dp[n] % MOD;
}

int main(){
    long long  n ,k ,d;
    cin >> n >> k >> d;
    long long  ans = (getnums(n,k)% MOD- getnums(n,d - 1)%MOD)%MOD;
    cout << ans <<endl;
    return 0;
}