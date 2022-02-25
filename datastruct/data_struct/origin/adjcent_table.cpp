/*************************************************************************
	> File Name: adjcent_table.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 19 Mar 2021 03:17:03 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<utility>

using namespace std;
int n,m;
int main(){
    cin>>n>>m;//n个点，m条边；
    //初始化动态二维数组：
    vector<vector<pair<int,int>> >edg(n+1,vector<pair<int,int>>{});
    for(int i=0;i<m;i++){
        int s,e,v;
        cin>>s>>e>>v;
        edg[s].push_back(make_pair(e,v));
    }
    for(int i=1;i<=n;i++){
        cout<<i<<" :";
        for(int j=0;j<edg[i].size();j++){
            cout<<"{"<<edg[i][j].first<<","<<edg[i][j].second<<"}";
        }
        cout<<endl;
    }
    return 0;
}
