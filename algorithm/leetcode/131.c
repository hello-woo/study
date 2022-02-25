/*************************************************************************
	> File Name: 131.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 07 Oct 2020 07:22:50 PM CST
 ************************************************************************/

#include<stdio.h>
void swap(int *a,int *b ){

    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int n,a;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        arr[i]=a;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
             swap(&arr[j],&arr[i]);
            }
        }
    }
//for (int i=0;i<n;i++){
//        printf("%d\n",arr[i]);
//    }
    printf("%d\n",arr[0]-arr[n-1]);
    return 0;
}
