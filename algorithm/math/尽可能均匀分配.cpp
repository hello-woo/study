/*
对于一个数组nums= {1,2,3,4,5,6},和一个操作数k，(每次操作只能加1),
使得k次操作之后数组的乘积最大;求最大值

题意：使得最小值的最大。
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 3005;
int nums[N];

int main(){
    int n ;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>>pri; //小顶堆
    for(int i = 0 ;i < n;i++){
        cin >> nums[i];
        pri.push(nums[i]);
    }

    int k;
    cin >> k;
    while(k--){
        int temp = pri.top();
        pri.pop();
        pri.push(temp + 1);
    }
    long long ans = 1;
    while(!pri.empty()){
        ans *= pri.top();
        pri.pop();
    }
    cout << ans << endl;
    return 0;
}

//tips 给定一个和为sum，尽可能均匀的分配给k个数;
vector<int>getNums(int sum,int k){
    vector<int>nums(k,0);
    int a = sum / k;
    int b = sum % k;

    for(int i = 0 ;i < k;i++){
        if(i < b){
            nums[i] = a + 1;
        }else {
            nums[i] = a;
        }
    }
    return nums;
}

// int main(){
//     int sum = 0;
//     cin >> sum ;
//     int n;
//     cin >> n;
//     vector<int>ans = getNums(sum,n);
//     for(auto p : ans){
//         cout << p << ", " << endl;
//     }
//     return 0;
// }