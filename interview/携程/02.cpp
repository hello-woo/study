// #include<bits/stdc++.h>

// using namespace std;

// const int N = 1e5+10;
// int nums[N];

// int main(){
//     int n;
//     cin >> n;
//     int maxval = 0;

//     int ans = 0;
//     if(n == 1) {
//         cout << ans <<endl;
//         return 0;
//     }
//     for(int i = 0 ;i < n ;i++){
//         cin >> nums[i];
//         maxval = max(maxval,nums[i]);
//     }
//     int cnt = 0;
//     for(int i = 0 ;i < n;i++){
//         if(nums[i] < maxval){
//             cnt++;
//         }
//     }
//     cout << cnt << endl;
//     return 0;
// }

// #include<bits/stdc++.h>

// using namespace std;

// const int N = 1e5 + 5;

// int nums[N];
// int t[N];

// int dfs(int x){
//     if(x == 1 ){
//         return 0;
//     }
//     if(x == 2){
//         return 1;
//     }
//     if(t[x] !=0){
//         return t[x];
//     }
//     int cnt = dfs(x - 1);
//     int temp = pow(x,0.5);
//     for(int i = 2 ; i <= temp;i++){
//         int k = x / i;
//         if(i * k == x){
//             cnt = min(dfs(i) + dfs(k),cnt);
//         }
//     }
//     t[x] = ++cnt;
//     return cnt;
// }

// int main(){
//     int n ;
//     cin >> n;
//     for(int i = 0 ;i < n;i++){
//         cin >> nums[i];
//     }
//     int ans = 0;
//     for(int i = 0 ;i < n ;i++){
//         if(nums[i] == 1) continue;
//         ans += dfs(nums[i]);
//     }
//     cout << ans << endl;
//     return 0;
// }

#include<bits/stdc++.h>

using namespace std;


int main(){
    string str;
    cin >> str;

    
    return 0;
}