/*************************************************************************
	> File Name: 109.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 28 Sep 2020 11:39:25 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int temp=n;
    int m;
    while(n){
        temp=n%10;
        if(temp%2==0){
            m= printf("YES\n");
            break;
        }
        n=n/10;
    }
    if(m!=4){
        printf("NO\n");
    }
    return 0;
}
