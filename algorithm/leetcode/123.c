/*************************************************************************
	> File Name: 123.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 03 Oct 2020 11:47:44 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if ( (a>=c&&b<=d )||a<=c&&b>=d){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}
