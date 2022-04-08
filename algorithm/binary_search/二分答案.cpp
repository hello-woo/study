/**
 * 给定长度为n的数组，每个元素代表一个木头的长度，木头可以任意截断，
 * 从这堆木头中截出至少k个相同长度为m的木块。已知k，求max(m)。
   输入两行，第一行n, k，第二行为数组序列。输出最大值。
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
int nums[N];
int n,k;

int check(int x){
    int ans = 0;
    for(int i = 1; i <= n;i++){
        ans += nums[i] / x;
    }
    return ans;
}

int main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> nums[i];
    }
    sort(nums,nums + n);
    int l = 1,r = nums[n - 1];
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(check(mid) >= k){
            l = mid;
        }else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}