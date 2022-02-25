/*************************************************************************
	> File Name: findnumber.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 20 Mar 2021 09:36:21 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


int binary_search(vector<int>&nums,int len,int val){
    if(val<nums[0]) return -1;
    int left=0,right=len-1;
    while(left<right){
        int mid=(left+right+1)>>1;
        if(nums[mid]<=val){
            left=mid;
        }else{
            right=mid-1;
        }
    }
    return left==right?left:-1;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n,0);
    vector<int>under_find(k,0);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums[i]=temp;
    }
    for(int i=0;i<k;i++){
        int temp;
        cin>>temp;
        under_find[i]=temp;
    }
    for(int i=0;i<k;i++){
        cout<<binary_search(nums,n,under_find[i]);
        i!=k-1&&cout<<" ";
    }
    return 0;
}
