#include<bits/stdc++.h>

using namespace std;


void dfs(int n,int index ,int scores,vector<int>& pro,int wrong,int& ans){
    if(wrong >= 3 || index >= 25){
        if(scores == n) ans++;
        return;
    } 
    scores += pro[index];
    dfs(n,index + 1,scores,pro,wrong,ans);
    scores -= pro[index];
    dfs(n,index + 1,scores,pro,wrong + 1,ans);
}

int main(){
    int n;
    cin >> n;
    vector<int>pro = {2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,8,8,8,8,8};
   // dfs(n,0,0,pro,0);

   for(int i = 2 ;i <= 100;i +=2){
        int ans = 0;
        dfs(i,0,0,pro,0,0);
        cout << ans << endl;
   }
    //cout << ans << endl;
    return 0;
}