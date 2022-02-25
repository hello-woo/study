/*************************************************************************
	> File Name: test111.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 19 Mar 2021 07:26:18 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int num;
    vector<int>nums;
    for(int i=0;i<n;i++){
        cin>>num;
        nums.push_back(num);
    }
    vector<int>help;
    for(int i=0;i<nums.size();i++){
        int temp=sqrt(nums[i]);
        int min_val=min(abs(nums[i]-temp*temp),abs(nums[i]-(temp+1)*(temp+1)));
        help.push_back(min_val);
    }
    sort(help.begin(),help.end());
    int res = 0;
    for(int i=0;i<n/2;i++){
        res+=help[i];
    }
    cout<<res<<endl;
    return 0;

}
