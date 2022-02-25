/*************************************************************************
	> File Name: 1-migong.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 21 Mar 2021 11:47:39 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;


char mmap[505][505],check[505][505];
int ans;
int n,m;
int dir[4][2]={0,1,1,0,0,-1,-1,0};

void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(xx<0||yy<0||xx==n||yy==m||check[xx][yy]==1){
            continue;
        }
        if(mmap[x][y]!=mmap[xx][yy]){
            check[xx][yy]=1;
            dfs(xx,yy);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char temp;
            cin>>temp;
            mmap[i][j]=temp;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(check[i][j]==0){
                check[i][j]=1;
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
