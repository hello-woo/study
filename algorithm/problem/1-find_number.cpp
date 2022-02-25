/*************************************************************************
	> File Name: 1-find_number.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 20 Mar 2021 10:14:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int num[500005],n,k;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(int i=0;i<k;i++){
        int t,l=0,r=n-1;
        scanf("%d",&t);
        if(i!=0){
            cout<<" ";
        }
        if(num[0]>t){
            cout<<-1;
            continue;
        }
        while(l!=r){
            int mid=(l+r+1)>>1;
            if(num[mid]<=t){
                l=mid;
            }else{
                r=mid-1;
            }
        }
        cout<<l;
    }
    return 0;
}
