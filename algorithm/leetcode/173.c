/*************************************************************************
	> File Name: 173.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 11 Oct 2020 09:33:40 PM CST
 ************************************************************************/


#include<stdio.h>
#include<string.h>
int main(){
    char s[1000]={0};
    gets(s);
    int num=0;
    int digit=0;
    int kongge=0;
    int qita=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]>=65&&s[i]<=90||s[i]>=97&&s[i]<=122){
            num++;
        }else if(s[i]==32){
            kongge++;
        }else if(s[i]>=48&&s[i]<=57){
            digit++;
        }else{
            qita++;
        }
    }
    printf("%d %d %d %d\n",num,digit,kongge,qita);
    return 0;
}
