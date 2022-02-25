/*************************************************************************
	> File Name: 204.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 11 Oct 2020 04:22:58 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int height[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&height[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\n",height[i][i]);
    }
    return 0;
}
