/*************************************************************************
	> File Name: 214.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 25 Oct 2020 10:00:35 AM CST
 ************************************************************************/

#include<stdio.h>
void bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int main(){
    int n,k;
    scanf("%d",&n);
    int score[n];
    for(int i=0;i<n;i++){
        scanf("%d",&score[i]);
    }
    bubble_sort(score,n);
    scanf("%d",&k);
    double sum=0;
    for(int i=0;i<k;i++){
        sum+=score[i];
    }
    printf("%.2lf\n",sum*1.0/k);
    return 0;
}
