/*************************************************************************
	> File Name: 188.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 11 Oct 2020 07:15:35 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int is_prime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
            break;
        }
    }
    return 1;
}
int main(){
    long long int n,m;
    scanf("%lld%lld",&n,&m);
    long long int arr[n];
    int cnt=0;
    for(int i=m;i<=n;i++){
        if(is_prime(i)==1){
            arr[cnt++]=i;
        }
    }
    for(int i=0;i<cnt;i++){
        printf("%lld\n",arr[i]);
    }
    return 0;
}
