/*************************************************************************
	> File Name: 108.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 28 Sep 2020 11:26:10 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    char s;
    double m,n;
    scanf("%c",&s);
    scanf("%lf%lf",&m,&n);
    if(s=='r'){
        printf("%.2lf\n",m*n);
    }
    if(s=='t'){
        printf("%.2lf\n",0.5*m*n);
    }
    return 0;
}
