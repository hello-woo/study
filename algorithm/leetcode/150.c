/*************************************************************************
	> File Name: 150.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 11 Oct 2020 04:44:47 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int num[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&num[i][j]);
        }
    }
/*    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",num[i][j]);
        }
        printf("\n");
    }*/
    int tmp[m][n];
    int dst=n-1;
    for(int i=0;i<n;i++,dst--){
        for(int j=0;j<m;j++){
            tmp[j][dst]=num[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            num[i][j]=tmp[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d",num[i][j]);
            if(j!=n-1){
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
