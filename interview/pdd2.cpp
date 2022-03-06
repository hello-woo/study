#include<bits/stdc++.h>

using namespace std;

const int N= 10005;
vector<vector<int>>vis(N,vector<int>(N,0));

int main(){
    int n,m;
    vector<pair<int,int>>duo;
    vector<pair<int,int>>pi;
    cin >> n >>m;
    for(int i = 0 ; i < n ; i++){
        int gj,fy;
        cin >> gj >> fy;
        duo.push_back(make_pair(gj,fy));
        vis[gj][fy]++;
    }
    for(int i = 0 ; i< m ;i++){
        int gj ,fy;
        cin >> gj >> fy;
        pi.push_back(make_pair(fy,gj));
    }
    int ans = 0;
    
    sort(duo.begin(),duo.end());
    sort(pi.begin(),pi.end());
    for(int i = 0 ; i < m ;i++){ 
        int fy = pi[i].first;
        for(int j = 0 ; j < n ; j++){
            if(vis[duo[j].first][duo[j].second] > 0&&duo[j].first > fy && duo[j].second >= pi[i].second){
                ans++;
                vis[duo[j].first][duo[j].second]--;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}