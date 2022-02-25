/*************************************************************************
	> File Name: 148.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 11 Oct 2020 03:04:36 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(){
    char s[50];
    int cnt=0;
    gets(s);
    for(int i=0;i<strlen(s);i++){
        if(s[i]==65){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
