/*************************************************************************
	> File Name: 70.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 07 Oct 2020 05:14:01 PM CST
 ************************************************************************/

#include<stdio.h>
int isugly(int n){
    while(n%2==0){
        n=n/2;
    }
    while(n%3==0){
        n=n/3;
    }
    while(n%5==0){
        n=n/5;
    }
    if(n==1){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    isugly(i) && printf("%d\n",i);
    return 0;   
}
