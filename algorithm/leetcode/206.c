/*************************************************************************
	> File Name: 206.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 11 Oct 2020 04:05:31 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int n,m;
   // double arr[n][m];
    scanf("%d%d",&n,&m);
    double arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%lf",&arr[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        double sum=0;
        for(int j=0;j<n;j++){
            sum+=arr[j][i];
        }
        printf("%g\n",sum);
    }
    return 0;

}
