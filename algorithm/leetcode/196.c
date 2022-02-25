/*************************************************************************
	> File Name: 196.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 12 Oct 2020 04:59:12 PM CST
 ************************************************************************/

#include<stdio.h>
int f(int n){
    if(n==2||n==3){
        return 1;
    }
    if(n==1){
        return 0;
    }
    return f(n-2)+f(n-3);
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",f(n));
    return 0;
}
