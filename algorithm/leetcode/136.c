/*************************************************************************
	> File Name: 136.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 07 Oct 2020 08:14:15 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i%7==0){
            printf("%d\n",i);
        }
    }
    return 0;
}
