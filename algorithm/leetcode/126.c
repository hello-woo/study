/*************************************************************************
	> File Name: 126.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 21 Sep 2020 11:31:29 PM CST
 ************************************************************************/

#include<stdio.h>
#define PI 3.14
int main(){
    double r1,r2;
    scanf("%lf%lf",&r1,&r2);
    printf("%.2lf",PI*(r1*r1-r2*r2));
    return 0;
}
