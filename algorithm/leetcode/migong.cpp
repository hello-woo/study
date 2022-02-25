/*************************************************************************
	> File Name: migong.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 29 Nov 2020 08:21:59 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int dir[4][2]={0,1,1,0,0,-1,-1,0};
int n,m;
char mmap[2005][2005];
int ans1;
void dfs2(int ,int);
void dfs1(int x,int y){
    for(int i=0;i<4;i++){
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(xx<0||yy<0||xx==n||yy==m||mmap[xx][yy]=='2'){
            continue;
        }
        if(mmap[xx][yy]=='1'){
            //ans1++;
            mmap[xx][yy]='2';
            dfs2(xx,yy);
        }
        
    }
}

void dfs2(int x,int y){
    for(int i=0;i<4;i++){
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(xx<0||yy<0||xx==n||yy==m||mmap[xx][yy]=='2'){
            continue;
        }
        if(mmap[xx][yy]=='0'){
           // ans2++;
            mmap[xx][yy]='2';
            dfs1(xx,yy);
        }
        
    }}
int main(){
    int temp=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mmap[i][j];
        }
    }

/*    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mmap[i][j];
        }
        cout<<endl;
    }
  */
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mmap[i][j]=='0'){
                mmap[i][j]='2';
                dfs1(i,j);
                ans1++;
            }
        }
    }
    cout<<ans1<<endl;
    return 0;
}
