/*************************************************************************
	> File Name: 181.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 11 Oct 2020 08:31:54 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(){
    char s[50];
    char temp[50];
    gets(s);
    for(int i=0;i<strlen(s);i++){
        temp[i]=s[i];}
    for(int i=0;i<strlen(s);i++){
        if(s[i]>=65&&s[i]<=90){
            s[i]=s[i]+32;
        }
        if(temp[i]>=97&&temp[i]<=122){
            s[i]=temp[i]-32;
        }
    }
    for(int i=0;i<strlen(s);i++){
        printf("%c",s[i]);
    }
    return 0;
}
