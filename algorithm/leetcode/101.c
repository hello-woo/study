/*************************************************************************
	> File Name: 101.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 22 Sep 2020 12:03:09 AM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    while(n){
        sum+=n%10;
        n=n/10;
    }
    printf("%d",sum);
    return 0;
}
