/*************************************************************************
	> File Name: xiaoming.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 05 Dec 2020 06:36:24 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

struct node{
    int x,y,step,f;
};
int n,m,sx,sy,ssx,ssy;
int ans,ans1,ans2;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
char mmap[105][105];
int check[105][105];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mmap[i][j];
            if(mmap[i][j]=='S'){
                sx=i,sy=j;
                check[i][j]=1;
            }
        }   
    }

    queue<node>que;
    que.push((node){sx,sy,0,0});
    while(!que.empty()){
        node temp=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int xx=temp.x+dir[i][0];
            int yy=temp.y+dir[i][1];
            if((check[xx][yy]&1)&&temp.f==0){
                continue;
            }
            if((check[xx][yy]&2)&&temp.f==1){
                continue;
            }
            if(mmap[xx][yy]=='T'&&temp.f==1){
                cout<<temp.step+1<<endl;
                return 0;
            }
            if(mmap[xx][yy]=='.'||mmap[xx][yy]=='S'||mmap[xx][yy]=='T'){
                que.push((node){xx,yy,temp.step+1,temp.f});
                check[xx][yy]+=temp.f+1;
            }
            if(mmap[xx][yy]=='B'){
                que.push((node){xx,yy,temp.step+1,1});
                check[xx][yy]=3;
            }
        }
    }
    cout<<"-1"<<endl; 
    return 0;
}
