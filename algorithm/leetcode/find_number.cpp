/*************************************************************************
	> File Name: find_number.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 29 Nov 2020 07:48:31 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n ,k,num[500005],tar[500005];
int find_num(int *arr,int n,int val){
    int l=0,r=n-1,mid;
    if(val>num[n-1]){
        return -1;
    }
    while(l!=r){
        int mid=(l+r)/2;
        if(num[mid]>=val){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    if(l==r){
        return r;
    }
    return -1;
}

int main(){
    cin >> n>>k;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int j=0;j<k;j++){
        cin>>tar[j];
    }
    for(int j=0;j<k;j++){
        cout<<find_num(num,n,tar[j]);
        if(j!=k-1){
            cout<<" ";
        }
    }

    return 0;
}
