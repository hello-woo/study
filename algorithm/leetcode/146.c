/*************************************************************************
	> File Name: 146.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Thu 08 Oct 2020 10:59:26 PM CST
 ************************************************************************/
#include<stdio.h>
#include<strings.h>
#include<string.h>
int main(){
    char s[50]={0};
    gets(s);
    for(int i=0;i<strlen(s);i++){  
        if(s[i]>=65&&s[i]<90||s[i]>=97&&s[i]<122){
                s[i]=s[i]+1;
                    
        }else if(s[i]==90){
                        s[i]=65;
                    
        }else if(s[i]==122){
                        s[i]=97;
                    
        }
        }
    for(int i=0;i<strlen(s);i++){
        printf("%c",s[i]);
    }
        return 0;

}
