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
    char temp[50];
    gets(s);
    for(int i=0;i<strlen(s)/2;i++){
        temp[i]=s[i];
        s[i]=s[strlen(s)-1-i];
        s[strlen(s)-i-1]=temp[i];
    }
    for(int i=0;i<strlen(s);i++){
        printf("%c",s[i]);
    }
    return 0;
}
