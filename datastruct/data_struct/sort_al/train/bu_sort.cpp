/*************************************************************************
	> File Name: bu_sort.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 08 Jan 2021 12:02:51 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void bubble_sort(int *arr,int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


int main(){
    int arr[5]={23,12,34,1,4};
    bubble_sort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
