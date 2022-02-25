/*************************************************************************
	> File Name: 184.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 12 Oct 2020 04:15:50 PM CST
 ************************************************************************/

#include<stdio.h>
int f(int n){
    if(n==1){
        return 1;
    }
    return  2*f(n-1)+2;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",f(n));
    return 0;
}
