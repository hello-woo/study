/*************************************************************************
	> File Name: all_sort.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 17 Mar 2021 04:01:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void bubble_sort(int *arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1],arr[j]);
            }
        }
    }
}
void bubble_sort_optic(int *arr,int n){
    int flag=1;
    for(int i=0;i<n&&flag;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]>=arr[j]) continue;
            swap(arr[j+1],arr[j]);
            flag=1;
        }
    }
}

int main(){
    int arr[]={10,2,10,3,5,6,1,9,5};
    int len=sizeof(arr)/sizeof(int);
    bubble_sort_optic(arr,len);
   // select_sort(arr,len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
