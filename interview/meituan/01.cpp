#include<bits/stdc++.h>

using namespace std;

const int N = 50005;

bool flag[N];
int nums[N];
int preSum[N];
int weight[N];
int n;

//取第i个
int getSUm(int x){
    int ans = 0;
    if(x  == 1 && flag[x] == false) {
        ans = preSum[n] - preSum[1];
    }
    else if(x == n && flag[x] == false) {
        ans  = preSum[n - 1];
    }else {
        int presum = preSum[x - 1];
        int postsum = preSum[n]  - preSum[x];
        ans = max(presum,postsum);
        cout << " pre S:"<<presum << " posrt : " << postsum <<endl;
    }
    flag[x] = true;
    for(int i = x ;i <= n; i++){
        preSum[i] -= weight[x];
    }
    for(int i = 1 ;i <= n ;i++){
        cout << " presum :" << preSum[i] << " ,";
    }
    cout <<endl;
    return ans;
}

int main(){

    cin >> n;
    for(int i =1 ;i <= n ;i++){
        cin >> weight[i];
    }
    for(int i = 1 ;i <= n ;i++){
        preSum[i] = preSum[i - 1] + weight[i];
    }
    for(int i = 1 ;i <= n;i++){
        int x;
        cin >> x;
        cout << getSUm(x) <<endl;
    }
    return 0;
}