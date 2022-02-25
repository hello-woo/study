/*************************************************************************
	> File Name: 233.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Thu 01 Apr 2021 11:15:17 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;
int n,p,h,m;
int main(){
    cin>>n>>p>>h>>m;
    vector<pair<int,int>>num;
    int x,y;
    vector<int>he(n,h);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        if(x>y){
            int temp=y;
            y=x;
            x=temp;
        }
        num.push_back(make_pair(x,y));
    }
    for(int i=0;i<num.size();i++){
//        cout<<"num first"<<num[i].first<<"num sec:"<<num[i].second<<endl;
        for(int j=(num[i].first)+1;j<num[i].second;j++){
  //          cout<<"j="<<j;
            he[j-1]=he[j-1]-1;
    //        cout<<"he"<<":";
      //      cout<<he[3]<<endl;
        }
    }
    for(int i=0;i<n;i++){
        cout<<he[i]<<endl;
    }
    return 0;

}
