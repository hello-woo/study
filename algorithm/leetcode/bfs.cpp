/*************************************************************************
> File Name: bfs.cpp
> Author:zhaozhicai
> Mail:1871259919@qq.com 
> Created Time: Sat 21 Nov 2020 03:09:54 PM CST
************************************************************************/

#include<iostream>
using namespace std;
#include<iostream>
#include<queue>
using namespace std;
struct node{
    int x,y,step;

};
int n,m,sx,sy;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
char mmap[105][105];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mmap[i][j];
            if(mmap[i][j]=='S'){
                sx=i,sy=j;

            }

        }

    }
    queue<node>que;
    que.push((node){sx,sy,0});
    while(!que.empty()){
        node temp=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int x=temp.x+dir[i][0];
            int y=temp.y+dir[i][1];
            if(mmap[x][y]=='T'){
                cout<<temp.step+1<<endl;
                return 0;

            }
            if(mmap[x][y]=='.'){
                mmap[x][y]=0;
                que.push((node){x,y,temp.step+1});

            }

        }

    }
    cout<<"NO"<<endl;
    return 0;

}
