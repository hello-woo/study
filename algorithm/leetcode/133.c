/*************************************************************************
	> File Name: 133.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 07 Oct 2020 10:24:50 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
          printf("%d*%d=%d",i,j,i*j);
            j!=n&& printf("\t");
        }
        printf("\n");
    }
    return 0;
}
