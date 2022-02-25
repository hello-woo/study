/*************************************************************************
	> File Name: 448.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 11 Oct 2020 03:22:57 PM CST
 ************************************************************************/

#include<stdio.h>
/*
int binary_search(int arr[],int n,int num){
    int head=0;
    int tail=n-1;
    int mid=0;
    while(head<=tail){
        mid=(head+tail)>>1;
        if(arr[mid]==num){
            return mid+1;
        }else if(arr[mid]>num){
            tail=mid-1;
        }else{
            head=mid+1;
        }
    }
    return -1;
}*/
int main(){
    int n;
    scanf("%d",&n);
    int num[n];
    int numb;
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    scanf("%d",&numb);
    int m=0;
    for(int i=0;i<n;i++){
        if(num[i]==numb){
          m= printf("%d\n",i+1);
        }
    }
    if(m==0){
        printf("%d\n",0);
    }
   // int ret=binary_search(num,n,numb);
   // if(ret==1){
   //     printf("%d\n",ret);
   // }else{
   //     printf("%d",0);
    //}
    return 0;
}
