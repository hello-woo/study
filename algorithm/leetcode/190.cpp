/*************************************************************************
	> File Name: 190.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 18 Nov 2020 04:45:24 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int num[100005];

int func(int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=num[i]/n;
    }
    return sum;
}


int main(){
    int n ,m;
    cin>>n>>m;
    int l=1,lr=0;
    for(int i=0;i<n;i++){
        cin>>num[i];
        lr=max(num[i],lr);

    }
    while(l!=lr){
        int mid=(l+lr+1)/2;
        int s=func(mid);
        if(s>=m){
            l=mid;
        }else{
            lr=mid-1;
        }
    }
    cout<<l<<endl;
    return 0;
}
