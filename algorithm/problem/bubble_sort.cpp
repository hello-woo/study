/*************************************************************************
	> File Name: bubble_sort.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 14 Mar 2021 12:12:06 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
void bubble_sort(int *arr,int len){
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}
int main(){
    int arr[]={12,3,4,6,7,8,9,3,10};
    int len=sizeof(arr)/sizeof(int);
    bubble_sort(arr,len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
