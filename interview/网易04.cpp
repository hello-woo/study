#include<bits/stdc++.h>

using namespace std;

const int N = 505;

int board[N][N];

const int INF = 0x3f3f3f3f;

//dp[i][j] 从(0,0)到(n,m)的最短价值,向下或向右，相等代价位1，不等代价为2；

int main(){
    int n,m;
    cin >> n >> m ;
    for(int i = 0; i < n ;i++){
        for(int j = 0 ; j < m ;j++){
            cin >> board[i][j];
        }
    }

    vector<vector<int>>dp(n,vector<int>(m ,INF));

    //这里初始化很关键
     dp[0][0] = 0;
    for(int i = 1;i < n ;i++){
        dp[i][0] = dp[i - 1][0] + 1;
        if(board[i][0] != board[i - 1][0]){
            dp[i][0]++;
        }
    }

    for(int j = 1; j < m;j++){
        dp[0][j] = dp[0][j - 1] + 1;
        if(board[0][j] != board[0][j - 1]){
            dp[0][j]++;
        }
    }
    cout << "0000" <<endl;

    for(int i = 1 ;i <n ;i++){
        for(int j = 1 ;j < m; j++){
            dp[i][j] = min(dp[i - 1][j] + (board[i - 1][j] == board[i][j] ? 1 : 2),dp[i][j - 1] + (board[i][j - 1] == board[i][j] ? 1 :2));
            // if(board[i - 1][j] == board[i][j]){
            //     dp[i][j] = min(dp[i][j] ,dp[i - 1][j] + 1);
            // }else{
            //     dp[i][j] = min(dp[i][j] ,dp[i - 1][j] + 2);
            // }

            // if(board[i][j - 1] == board[i][j]){
            //     dp[i][j] = min(dp[i][j] ,dp[i][j - 1] + 1);
            // }else{
            //     dp[i][j] = min(dp[i][j],dp[i][j - 1] + 2);
            // }
        }
    }
    cout << dp[n - 1][m - 1];

    return 0;
}