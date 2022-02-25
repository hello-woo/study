/*************************************************************************
	> File Name: 102.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 22 Sep 2020 12:20:40 AM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int a,b,c,t;
    scanf("%d%d%d%d",&a,&b,&c,&t);
    printf("%.2lf",(1-t*1.0/c)*a*b*c/(a*c+b*c-a*b));
    return 0;
}
