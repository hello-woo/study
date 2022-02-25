/*************************************************************************
	> File Name: qu_sort.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 08 Jan 2021 12:07:41 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int partion(int *arr,int low,int high){
    int mid=low+(high-low)/2;
    if(arr[low]>arr[high]){
        swap(arr[low],arr[high]);
    }
    if(arr[mid]>arr[high]){
        swap(arr[mid],arr[high]);
    }
    if(arr[low]<arr[mid]){
        swap(arr[low],arr[mid]);
    }
    int pivotkey=arr[low];
    while(low<high){
        while(low<high&&arr[high]>=pivotkey) high--;
        swap(arr[low],arr[high]);
        while(low<high&&arr[low]<pivotkey) low++;
        swap(arr[low],arr[high]);
    }
    return low;
}

void quick_sort(int *arr,int low,int high){
    while(low<high){
        int pivot=partion(arr,low,high);
        quick_sort(arr,low,pivot-1);
        //quick_sort(arr,pivot+1,high);
        low=pivot+1;
    }
}

int main(){
    int arr[10]={12,3,5,1,4,15,16,15,9,10};
    quick_sort(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
   }
    cout<<endl;
    return 0;
}
