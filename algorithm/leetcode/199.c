/*************************************************************************
	> File Name: 199.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 12 Oct 2020 08:01:28 PM CST
 ************************************************************************/

#include<stdio.h>
int f(int k,int *arr){
    int a[100000]={0,1,2,3,4,5,6,7,8,9};
    int sum=0;
    if(k<10){
        return a[k];
    }else {
        for(int i=0;i<=k;i++){
            sum+=arr[i+1]*a[k-i-1];
        }
    }
    return sum;
}

int main(){
    int k,m;
    int a[10]={0};
    scanf("%d%d",&k,&m);
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    int ret=f(k,a);
    printf("%d\n",ret);
    printf("%d\n",ret%m);
    return 0;
}
