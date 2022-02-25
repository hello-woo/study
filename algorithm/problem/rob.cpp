/*************************************************************************
	> File Name: rob.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 28 Mar 2021 07:07:21 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int>num;

int rob(vector<int>&num){
    if(num.empty()) return 0;
    int sz=num.size();
    if(sz==1) return num[0];
    int start=num[0];
    int end=max(num[0],num[1]);
    for(int i=2;i<sz;i++){
        int temp=end;
        end=max(start+num[i],end);
        start=temp;
    }
    return  end;
}

int main(){
    int temp;
    while((cin>>temp)){
        num.push_back(temp);
    } 
    /*
    while(scanf("%d",&temp)!=EOF){
        num.push_back(temp);
    }*/
    int res=rob(num);
    cout<<res<<endl;
    return 0;
}
