/*************************************************************************
	> File Name: 145.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 11 Oct 2020 08:51:44 PM CST
 ************************************************************************/

#include<stdio.h>
#include<strings.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    char name[n][100];
    for(int i=0;i<=n;i++){
        gets(name[i]);
    }
//    printf("%s\n",name[1]);
    char temp[n];
    for(int i=0;i<=n;i++){
        int max=strlen(name[0]);
        if(max<strlen(name[i])){
            max=strlen(name[i]);
            strcpy(temp,name[0]);
            strcpy(name[0],name[i]);
            strcpy(name[i],temp);
        }
    }
    printf("%s\n",name[0]);
    return 0;
}
