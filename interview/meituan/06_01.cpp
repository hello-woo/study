#include<bits/stdc++.h>

using namespace std;

const int N = 50005;
int good[N];
int preSum[N];

int main(){
    int n ,m ,k;
    cin >> n >> m >> k;
    for(int i = 1 ;i <= n;i++){
        cin >> good[i];
        preSum[i] = preSum[i - 1] + good[i];
    }
    //m个数字连续和大于>=k的方案数
    int cnt = 0;
    for(int i = m ;i <= n;i++){
       // int ans = preSum[i] - preSum[i - m];
        bool flag = false;
        for(int j = i - m + 1; j <= i;j++){
            if(good[j] < k) flag = true;
            //break;
        }
        //cout << ans <<endl;
        //if(ans >= k && flag == false) cnt++;
        if(flag == false) cnt++;
    }
    cout << cnt <<endl;
    return 0;
}