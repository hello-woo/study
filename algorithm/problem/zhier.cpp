/*************************************************************************
	> File Name: zhier.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 20 Mar 2021 04:44:39 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>table(n+1,vector<int>(n+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            int temp;
            cin>>temp;
            table[i][j]=temp;
        }
    }
    long long  a,b,c;
    a=1;
    b=2;
    for(int i=3;i<=m;i++){
        c=table[b][a];
        a=b;
        b=c;
        cout<<c<<endl;
    }
    cout<<c<<endl;
    return 0;
}
