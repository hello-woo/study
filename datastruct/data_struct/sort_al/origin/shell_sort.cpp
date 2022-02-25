/*************************************************************************
	> File Name: shell_sort.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 13 Dec 2020 11:18:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void shell_sort(int *arr,int len){
    int tmp,gap=len/2;
    while(gap>0){
        for(int i=gap;i<len;i++){
            tmp=arr[i];
            int preIndex=i-gap;
            while(preIndex>=0&&arr[preIndex]>tmp){
                arr[preIndex+gap]=arr[preIndex];
                preIndex-=gap;
            }
            arr[preIndex+gap]=tmp;
        }
        gap/=2;
    }
}

int main(){
    int arr[]={12,23,9,9,13,25,27,14,7};
    int len=(int)sizeof(arr)/(sizeof(*arr));
    shell_sort(arr,len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
