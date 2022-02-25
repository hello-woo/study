/*************************************************************************
	> File Name: lc64.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 21 Nov 2020 02:52:49 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<vector>

int dir[2][2]={0,-1,-1,0};

int n,m,mmap[205][205];
int ans=0;
int sum=0;
int mark[205][205];

void func(int x,int y){
    for(int i=0;i<2;i++){
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(xx==m&&yy==n){
            cout<<ans;
        }
        mark[xx][yy]=1;
        sum+=mmap[xx][yy];
        func(xx,yy);
        ans=min(ans,sum);
    }
}


int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;i++){
            cin>>mmap[i][j];
        }
    }
    ans=mmap[0][0];
    mark[0][0]=1;
    func(0,0);
    cout<<ans<<endl;

    return 0;
}
