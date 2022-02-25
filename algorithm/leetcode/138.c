/*************************************************************************
	> File Name: 138.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 07 Oct 2020 08:39:06 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int k=2*n;
    for(int i=0;i<n;i++){
        for(int j=k;j>0;j--){
            printf("A");
        }
        k=k-2;
        printf("\n");
    }
    return 0;
}
