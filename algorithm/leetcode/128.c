/*************************************************************************
	> File Name: 128.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 07 Oct 2020 07:03:28 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int n,a;
    scanf("%d",&n);
    double sum=0;
    for(int i=0;i<n;i++){
       scanf("%d",&a);
        sum+=a;
    }
    printf("%.2lf\n",sum*1.0/n);
    return 0;
}
