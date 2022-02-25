/*************************************************************************
	> File Name: 189.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 04 Nov 2020 09:03:20 PM CST
 ************************************************************************/

#include<stdio.h>
long long int binary_search(long long int arr[],long long int n,long long int num){
    long long int head=0;
    long long int tail=n-1;
    long long int mid=0;
    while(head<=tail){
        mid=(head+tail)>>1;
        if(arr[mid]==num){
            return mid+1;
        }else if(arr[mid]>num){
            tail=mid-1;
        }else{
            head=mid+1;
        }
    }
    return -1;
}
int main(){
    long long int n,k,m;
    long long int arr[n];
    scanf("%lld%lld",&n,&k);
    for(long long int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    while(k--){
        scanf("%lld",&m);
        long long int res=binary_search(arr,n,m);
        if(res!=-1){
            printf("%lld",res);   
        }else{
            printf("%d",0);
        }
        k&&printf(" ");
    }
    return 0;
}
