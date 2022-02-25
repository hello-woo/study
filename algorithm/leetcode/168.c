/*************************************************************************
	> File Name: 168.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 12 Oct 2020 11:45:00 AM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
void trans(char *arr,int n){
    for(int i=0;i<n;i++){
        if(i){
            if(arr[i]>=65&&arr[i]<=90){
                arr[i]+=32;
            }
        }else{
            if(arr[i]>=97&&arr[i]<=122){
                arr[i]-=32;
            }
        }
    }
}
void sort(char (*arr)[100],int n){
    char tmp[100]={0};
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(arr[i],arr[j])>0){
                strcpy(tmp,arr[i]);
                strcpy(arr[i],arr[j]);
                strcpy(arr[j],tmp);
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    char name[n][100];
    for(int i=0;i<n;i++){
        scanf("%s",name[i]);
//      printf("%s\n",name[i]);
        trans(name[i],strlen(name[i]));
    }
    sort(name,n);
    for(int i=0;i<n;i++){
        printf("%s\n",name[i]);
    }
    return 0;
}
