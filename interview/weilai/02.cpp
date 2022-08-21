#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+ 5;
int nums[N];
int diff[N];



int main(){
    int n;
    cin >> n;
    long long sum = 0;
    for(int i = 1; i <= n;i++){
        cin >> nums[i];
        sum += nums[i];
    }
    int q;
    cin >> q;
    int ans = sum;
    while(q--){
        int temp;
        cin >> temp;
        ans += temp * n ;
        cout << ans << endl;
    }
    system("pause");
    return 0;
}