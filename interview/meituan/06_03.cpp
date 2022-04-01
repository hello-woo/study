#include<bits/stdc++.h>

using namespace std;

const int N = 50005; 
const int M = 50005;
string str;
int board[N][M];
bool dp[N][M];

int main(){
    int n,m;
    cin >> n >> m;
    
    for(int i = 0 ;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> board[i][j];
        
            if(j == 0) str += board[i][j] + '0';
        }
    }

    int left = 0 ,right = 0,len = 0;
    for(int i = n - 1 ;i >= 0 ;i--){
        for(int j = i;j < n;j++){
            if(str[i] == str[j] && (j - i <=1 || dp[i + 1][j - 1] == true)){
                dp[i][j] = true;
            }
            if(dp[0][j] == true && j + 1 > len){
                len = j  + 1;
                right = j;
            }
        }
    }
    // for(int i = 0;i < n;i++){
    //     for(int  j = 0 ;j < n;j++){
    //         cout << dp[i][j] << " <";
    //     }
    //     cout <<endl;
    // }
    //cout << left << right <<endl;
    int l = left ,r = right;
    int ans =0;
    while(l < r){
        int mid = (l + r) >> 1;
        if(dp[l][mid] == true && dp[mid + 1][r] == true){
            r = mid;
        }else{
            ans  = mid;
            break;
        }
    }
    //cout << ans <<endl;
    for(int i = 0 ;i <= ans;i++){
        for(int j = 0;j < m;j++){
            j != 0 && cout << " ";
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}