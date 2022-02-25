/*************************************************************************
	> File Name: 183.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 12 Oct 2020 04:07:21 PM CST
 ************************************************************************/

#include<stdio.h>
int f(int x){
    if(x<=0){
        return 0;
    }
    if(x==1){
        return 1;
    }
    if(x>1&&x%2==0){
        return 3*f(x/2)-1;
    }
    if(x>1&&x%2==1){
        return 3*f((x+1)/2)-1;
    }}
int main(){
    int x;
    scanf("%d",&x);
    printf("%d\n",f(x));
    return 0;
}
