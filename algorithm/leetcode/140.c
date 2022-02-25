/*************************************************************************
	> File Name: 139.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 07 Oct 2020 08:47:52 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int k=1;
    int m=1;
    int a=65;
    for(int i=1;i<=n;i++){
        for(int j=k;j<n;j++){
            printf(" ");
        }
        for(int i=1;i<=m;i++){
            printf("%c",a);
        }
        k++;
        m+=2;
        a++;
        printf("\n");
    }
    a--;
    for(int i=n+1;i<=2*n-1;i++){
        k--;
        m-=2;
        a--;
        for(int j=k-1;j<n;j++){
            printf(" ");
        }
        for(int i=1;i<=m-2;i++){
            printf("%c",a);
        }
        printf("\n");
    }
    return 0;
}
