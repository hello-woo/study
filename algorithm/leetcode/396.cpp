/*************************************************************************
> File Name: 535.cpp
> Author:zhaozhicai
> Mail:1871259919@qq.com 
> Created Time: Sat 21 Nov 2020 10:07:31 AM CST
************************************************************************/

#include<iostream>
using namespace std;

int n;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int mmap[105][150];

void func(int x,int y){
    for(int i=0;i<4;i++){
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(xx<0||xx>n+1||yy<0||yy>n+1){
            continue;
        }
        if(mmap[xx][yy]==0){
            mmap[xx][yy]=3;
            func(xx,yy);
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mmap[i][j];
        }
    }

    func(sx,sy);
    cout<<ans<<endl;
    return 0;

}
