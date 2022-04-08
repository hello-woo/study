#include<bits/stdc++.h>

using namespace std;

const int N  = 3005;
int nums[N];
int preSum[N];

int main(){
    int n ;cin >> n;
    for(int i= 1; i <= n;i++){
        cin >> nums[i];
        preSum[i] = preSum[i - 1] + nums[i];
    }
    stack<int>sta;
    int ans = 0;
    for(int i = 1; i <= n;i++){
        while(!sta.empty() && nums[i] < nums[sta.top()]){
            int temp = sta.top();
            sta.pop();
            int left = sta.empty() ? 0:sta.top();
            int right = i;
            //区间为[left + 1,right - 1]内的最小值都为nums[temp]
            int val = preSum[right - 1] - preSum[left];
            cout << "left :" << left << "right :" << right << "val :" << val<<endl;
            ans = max(ans,val * nums[temp]);
        }
        sta.push(i);
    }
    //以下为递增的顺序 比如 1，2，3，5，6，7，8
    while(!sta.empty()){
        int temp = sta.top();
        sta.pop();
        int left = sta.empty() ? 0: sta.top();
        int right = n;
        //区间[left + 1,right] 最小值为nums[temp]
        int val = preSum[right] - preSum[left];
        ans = max(ans,val * nums[temp]);
    }
    cout << ans << endl;
    return 0;
}