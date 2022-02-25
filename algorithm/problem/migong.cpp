/*************************************************************************
	> File Name: migong.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 20 Mar 2021 10:28:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

char mmap[2005][2005],check[2005][2005];
int n,m,ans;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(xx==0||yy==0||xx==n+1||yy==m+1||check[xx][yy]==1){
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
    for(int i=1;i<=n;i++){
        cin>>&mmap[i][1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(check[i][j]==0){
                ans++;
                check[i][j]=1;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
