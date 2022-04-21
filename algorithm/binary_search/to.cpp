#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+2;
int n,m;
int nums[N];
int preSum[N];
int test[N];

int getIndex(int val){
    int l = 0,r = n;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(preSum[mid] <= val){
            l = mid;
        }else {
            r = mid - 1;
        }
    }
    return l;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n;i++){
        cin >>nums[i];
        preSum[i] = preSum[i - 1] + nums[i];
    }
    for(int i = 0 ;i < m;i++){
        cin >> test[i];
        cout << getIndex(test[i]) <<endl;
    }
    int ans = 2e9 + 2;
    cout << ans << endl;
    return 0;
}