/*************************************************************************
	> File Name: 185.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 12 Oct 2020 04:24:40 PM CST
 ************************************************************************/

#include<stdio.h>
int f(int n){
    if(n==1||n==2){
        return 1;
    }
    return f(n-1)+f(n-2);
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",f(n));
    return 0;
}
