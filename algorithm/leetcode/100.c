/*************************************************************************
	> File Name: 100.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 21 Sep 2020 11:52:41 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    double sum=0;
    int i=0;
    while(i<6){
        sum=(n+sum)*(1+0.00417);
         i++;
    }
    printf("$%.2lf",sum);

    return 0;

}

