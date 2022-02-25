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
    int k=n;
    int m=n;
    int a=65;
    for(int i=1;i<=n+1;i++){
        for(int i=n;i>m;i--){
            printf(" ");
        }
        for(int j=2*k+1;j>=k+1;j--){
            printf("%c",a++);
        }
        a--;
        for(int j=k;j>0;j-- ){
            printf("%c",--a);
        }
        a++;
        k--;
        m--;
        printf("\n");
    }
//    printf("%d%d%d",a,k,m);
    a=a-2;
    m=n;
    k=1;
    for(int i=n+2;i<=2*n+1;i++){
        for(int j=1;j<m;j++){
            printf(" ");
        }
        for(int i=1;i<=k;i++){
            printf("%c",a++);
        }
        for(int i=k+1;i<=2*k+1;i++){
            printf("%c",a--);
        }
        k++;
        m--;
        printf("\n");
    }
    
    return 0;
}
