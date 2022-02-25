/*************************************************************************
	> File Name: tu.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 19 Mar 2021 02:32:17 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int n,m,arr[105][105];


int main(){
    memset(arr,0x3f,sizeof(arr));
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int s,e,v;//两个点以及对应的权值
        cin>>s>>e>>v;
        arr[s][e]=min(v,arr[s][e]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]!=0x3f3f3f3f){
                cout<<arr[i][j]<<" ";
            }else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
