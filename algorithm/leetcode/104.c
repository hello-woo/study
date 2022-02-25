/*************************************************************************
	> File Name: 104.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 07 Oct 2020 06:17:21 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int cnt=0;
    while(a){
        int temp=a;
        a=a%10;
        if(a==9){
            printf("YES\n");
            break;
        }
        a=temp/10;
        cnt++;
    }
    if(cnt==3){
            printf("NO\n");
        }
    return 0;
}
