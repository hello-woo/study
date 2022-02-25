/*************************************************************************
	> File Name: 177.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 25 Oct 2020 10:54:16 AM CST
 ************************************************************************/

#include<stdio.h>
#include<strings.h>
#include<string.h>
void swap_order(char arr[],int n){
    char temp[n];
    for(int i=0;i<n;i++){
        temp[i]=arr[i];
    }
    for(int i=0;i<n;i++){
        if(i<2){
            arr[i]=temp[n-2+i];
        }else{
            arr[i]=temp[i-2];
        }
    }}
int main(){
    char s[100];
    gets(s);
    int n=strlen(s);
    printf("%s\n",s);
    for(int i=0;i<n-1;i++){
        swap_order(s,n);
        printf("%s\n",s);
    }
    return 0;
}
