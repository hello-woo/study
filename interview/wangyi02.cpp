#include<bits/stdc++.h>

using namespace std;

bool check(char a,char b){
    return abs(a - b) <= 1;
}

int cal(char a){
    return a - 'a' + 1;
}

int main(){
    string s;
    cin >> s;
    int n = s.size();

    vector<int>dp(n,0);
    //dp[i]表示s中前i + 1个字符中可以得到的最大分数
    if(check(s[0],s[1])){
        dp[1] = cal(s[0]) + cal(s[1]);
    }
    for(int i = 2 ; i < n; i++){
        dp[i] = dp[i -1];
        if(check(s[i],s[i - 1])){
            dp[i] = max(dp[i],dp[i - 2] + cal(s[i]) + cal(s[i - 1]));
        }
    }
    cout <<dp[n - 1] <<endl;
    return 0;
}