/*
设有 N 堆石子排成一排，其编号为 1，2，3，…，N。

每堆石子有一定的质量，可以用一个整数来描述，现在要将这 N 堆石子合并成为一堆。

每次只能合并相邻的两堆，合并的代价为这两堆石子的质量之和，合并后与这两堆石子相邻的石子将和新堆相邻，合并时由于选择的顺序不同，合并的总代价也不相同。

例如有 4 堆石子分别为 1 3 5 2， 我们可以先合并 1、2 堆，代价为 4，得到 4 5 2， 又合并 1，2 堆，代价为 9，得到 9 2 ，再合并得到 11，总代价为 4+9+11=24；

如果第二步是先合并 2，3 堆，则代价为 7，得到 4 7，最后一次合并代价为 11，总代价为 4+7+11=22。

问题是：找出一种合理的方法，使总的代价最小，输出最小代价。
*/

/*
区间 DP 常用模版
所有的区间dp问题，第一维都是枚举区间长度，一般 len = 1 用来初始化，枚举从 len = 2 开始，
第二维枚举起点 i （右端点 j 自动获得，j = i + len - 1）

for (int i = 1; i <= n; i++) {
    dp[i][i] = 初始值
}
for (int len = 2; len <= n; len++)           //区间长度
    for (int i = 1; i + len - 1 <= n; i++) { //枚举起点
        int j = i + len - 1;                 //区间终点
        for (int k = i; k < j; k++) {        //枚举分割点，构造状态转移方程
            dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + w[i][j]);
        }
    }
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 305;
int dp[N][N];
int s[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n ;i++) cin>> s[i],s[i]+=s[i-1];
    for(int len = 2; len <= n; len++){
        for(int i = 1;i + len -1 <= n;i++){
            int j = i + len -1;
            dp[i][j] = 0x3f3f3f;
            for(int k = i ; k < j; k++){
                dp[i][j] = min(dp[i][j] ,dp[i][k]+dp[k+1][j] + s[j] - s[i-1]);
            }
        }
    }
    cout << dp[1][n]<<endl;
    return 0;
}