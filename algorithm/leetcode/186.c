/*************************************************************************
	> File Name: 186.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 12 Oct 2020 04:33:23 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 10000
int f(int *arr,int n){
    if(n==1){
        return 1;
    } 
    
}
int mian(){
    int n;
    scanf("%d",&n);
    int a[MAX_N]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",f(a,n));
    return 0;
}
