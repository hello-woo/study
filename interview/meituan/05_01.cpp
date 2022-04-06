#include<bits/stdc++.h>

using namespace std;

const int N = 2005;
int nums[N];
int modval[N][N];

int main(){
    int n;
    cin >> n;
    // cout << n << endl;
    // string str ;
    // cin >> str;
    //cout << str << endl;
    for(int i = 1 ;i <= n;i++){
        cin >> nums[i];
    }
    int ans = 0;
    for(int i = 1 ;i <= n; i++){
        for(int j = 1; j <= n;j++){
            modval[i][j] = i % j;
            ans ^= modval[i][j];
        }
    }
    for(int i = 1; i <= n;i++){
        ans ^= nums[i];
    }
    cout << ans <<endl;
    return 0;
}