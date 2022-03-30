#include<bits/stdc++.h>

using namespace std;

const int N = 10005;
const int M = 10005;

int v[N];
int w[N];
int flag[M];
int ans[M];
int allsum[N];

bool cmp(pair<int,int>& a,pair<int,int> &b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> v[i]>>w[i];
    }
    int cnt = 0;
    vector<pair<int,int>>good;
    priority_queue<int,vector<int>,greater<int>>que;
    for(int i = 0;i < n;i++){
        allsum[i] = v[i] + 2 * w[i];
        //good.push_back(make_pair(allsum,i));
    }
    for(int i = 0 ;i < m;i++){
        que.push(i);
    }

    for(int i = m ;i < n;i++){
        if(allsum[i] > allsum[que.top()]){
            que.push(i);
            que.pop();
        }
    }

    while(!que.empty()){
        cout << que.top() + 1<<" ";
        que.pop();
    }

    // sort(good.begin(),good.end(),cmp);
    // // for(auto p : good){
    // //     cout << p.first << " ," << p.second <<endl;
    // // }

    // for(int i = n - 1; i > n - 1 - m;i--){
    //     ans[n - 1 - i] = good[i].second  + 1;
    // }
    // sort(ans,ans + m);
    // for(int i = 0 ;i < m;i++){
    //     i!= 0&& cout << " ";
    //     cout << ans[i] ;
    // }
    return 0;
}