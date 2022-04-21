#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
int nums[N];
long long  preMul[N];

long long  getcount(long long  x){
    long long  cnt = 0;
    if(x == 5 || x % 10 != 0) return 0;

    while(x % 5 == 0){
        cnt++;
        x = x/5;
    }
    return cnt;
}

int main(){
    int n;
    preMul[0] = 1;
    cin >> n;
    for(int i = 1 ;i <= n ;i++){
        cin >> nums[i];
        preMul[i] = preMul[i - 1] * nums[i];
    }

    int ans = 0;

    for(int i = 1;i <=n; i++){
        for(int j = i; j <= n;j++){
            long long  val = preMul[j] / preMul[i - 1];
            ans += getcount(val);
        }
    }
    cout << ans << endl;
    return 0;
}