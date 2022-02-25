/*************************************************************************
	> File Name: test.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 10 Jan 2021 05:48:15 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int nums[]={10,201,2023,1,31,3,13,1};
    int *hash= new int [sizeof(nums)/sizeof(int)];
    char str[]={'c','b','c','g','h'};
    cout<<"c++ 11: ";
    for(int num:nums){
        cout<<num<<" ";
    }
    cout<<endl;
    for(auto i:str){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i:nums){
        hash[i]=i;
        cout<<hash[i]<<endl;
    }
    cout<<"origin : ";
    for(int i=0;i<sizeof(nums)/sizeof(int);i++){
        cout<<nums[i]<<" ";
    }
    delete []hash;
    return 0;
}
