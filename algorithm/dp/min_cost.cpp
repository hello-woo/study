/* 
2022/08/20美团笔试
给定两个数组A和B,长度为m和n,
两个操作：
(1)选定某个数列中的某一个数a，改成b,cost代价为|b - a |
(2)选择一个数列某个数a,将它从数列中丢弃,花费|a|
问：
最少花费多少代价将两个数列变得再次相同
输入格式：

n m
n个整数
m个整数

【示例】
1 1
-9821
7742

ouput:17563
 */
#include<bits/stdc++.h>

using namespace std;

const int N = 2005;
int a[N];
int b[N];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0 ;i < n ;i++){
        cin >> a[i];
    }

    for(int j = 0 ;j < m;j++){
        cin >> b[j];
    }
    //dp[i][j];将a[0:i - 1]编辑为b[0:j - 1]相同的最小代价
    vector<vector<int>>dp(n + 1,vector<int>(m + 1,0));
    for(int i = 1; i <= n;i++){
        dp[i][0] = dp[i - 1][0] + abs(a[i - 1]);
    }
    for(int j = 1; j <= m;j++){
        dp[0][j] = dp[0][j - 1] + abs(b[j - 1]);
    }

    for(int i = 1; i <= n ;i++){
        for(int j = 1; j <= m;j++){
            //如果前一个相等，则代价和上一步一样
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                //删除a中数字
                long t1 = dp[i - 1][j] + abs(a[i - 1]);
                //删除b中数字
                long t2 = dp[i][j - 1] + abs(b[j - 1]);
                //更改数字
                long t3 = dp[i - 1][j - 1] + abs(a[i - 1] - b [i - 1]);
                dp[i][j] = min({t1,t2,t3});
            }
        }
    }
    cout << dp[n][m] <<endl;
    system("pause");
    return 0;
}