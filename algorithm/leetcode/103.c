/*************************************************************************
	> File Name: 103.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Thu 24 Sep 2020 05:32:03 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    if( (a<b)||(a>b&&a%b )){
     printf("NO");
    }else{
       printf("YES");
    }
    return 0;
}
