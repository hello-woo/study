/*************************************************************************
	> File Name: prime.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 11 Oct 2020 07:46:21 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int  is_prime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return -1;
            break;
        }
    }
    return 1;
}
int main(){
    int n;
    scanf("%d",&n);
    int ret = is_prime(n);
    printf("%d",ret);
    return 0;
}
