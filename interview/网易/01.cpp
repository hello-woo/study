#include<bits/stdc++.h>

using namespace std;

vector<long long >getNum(int n,int k,int x){
    
}

int main(){
    int n,k,x;
    cin >> n >> k >> x;
    if(n > k ) return -1;
    vector<long long >ans;
    int sum = 0;
    vector<long long >nums;
    for(long long  i = 1 ;i <= k;i++){
        nums.push_back(i);
    }
    ans = getNum(n,k,x);
    return 0;
}