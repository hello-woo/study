/*************************************************************************
	> File Name: tu.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 19 Mar 2021 02:32:17 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int n,m,s,arr[105][105];


int main(){
    memset(arr,0x3f,sizeof(arr));
    cin>>n>>m>>s;//n行m列的邻接矩阵，起点为s:
    for(int i=1;i<=n;i++){
        arr[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int s,e,v;//两个点以及对应的权值
        cin>>s>>e>>v;
        arr[s][e]=min(v,arr[s][e]);
        arr[e][s]=min(arr[s][e],v);
    }
    //求点j到k的最短路径;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(arr[s][i]!=0x3f3f3f3f){
                cout<<arr[s][i]<<" ";
            }else{
                cout<<-1<<" ";
            }
        cout<<endl;
    }
    return 0;
}
