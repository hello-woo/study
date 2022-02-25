/*************************************************************************
	> File Name: 205.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Thu 08 Oct 2020 11:49:18 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int height[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&height[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        float sum=0;
        for(int j=0;j<m;j++){
            sum+=height[i][j];
        }
        printf("%.6lf\n",sum*1.0/m);
    }
    return 0;
}
