/*************************************************************************
	> File Name: 124.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 07 Oct 2020 06:56:44 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if((b<=50||a>=1)&&(c<=25||d>=5)){
    printf("ok\n");
    }else {
        printf("pass\n");
    }
    return 0;
}
