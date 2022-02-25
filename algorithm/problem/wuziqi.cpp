/*************************************************************************
	> File Name: wuziqi.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 31 Aug 2021 09:45:06 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

const int N = 12;
int mmap[N][N];
int vis[N][N];
int n;
vector<pair<int ,int >>v;

int dir[8][2] = {0,1,
                 1,1,
                 1,0,
                 1,-1,
                 0,-1,
                 -1,-1,
                 -1,0,
                 -1,1
                };

int ans = 0;
void dfs(int x,int y){
    for(int i = 0 ;i<4;i++){
        int x0 = x + dir[i][0];
        int y0 = y + dir[i][1];
        
        int x1 = x + dir[i+4][0];
        int y1 = y + dir[i+4][1];
        if(x0<0||x0==n||y0<0||y0==n||vis[x0][y0]==1||x1<0||x1==n||
          y0<0||y0==n||vis[x1][y1]==1){
            continue;
        }
        if(mmap[x0][y0]==1||mmap[x1][y1]==1){
            ans++;
            cout << "x0"<<x0<<"y0"<<y0<<endl;
            cout << "first ans  ="<<ans<<endl;
            vis[x0][y0] = 1;
        }
        vis[x0][y0] = 0;
        vis[x1][y1] = 0;
    }
}

int main(){
    cin>>n;
    for(int i = 0 ;i < n ;i++){
        for(int j = 0 ;j < n;j++){
            cin >> mmap[i][j];
        }
    }
    for(int i = 0 ;i< n;i++){
        for(int j = 0 ;j < n;j++){
            ans = 0;
            if(mmap[i][j]==0){
                ans += 1;
                vis[i][j] = 1;
                dfs(i,j);
            }
            if(ans == 5){
                cout<< "i :"<<i<<" j:"<<j<<endl;
                v.push_back(make_pair(i,j));
            }
        }
    }
    sort(v.begin(),v.end());
    cout<< v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<< v[i].first+1<<" "<<v[i].second+1;
        i!=v.size()-1 && cout<<endl;
    }
    return 0;
}

