/*************************************************************************
	> File Name: qw.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 28 Mar 2021 07:45:22 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<bit/
#include<algorithm>
using namespace std;

int main(){
    vector<int>num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    num.push_back(2);
    num.push_back(3);
    auto iter= unique(num.begin(),num.end());
    num.erase(iter,num.end());
    for(int i=0;i<num.size();i++){
        cout<<num[i]<<endl;
    }
    return 0;
}
