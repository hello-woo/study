/*************************************************************************
	> File Name: quick_sort.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Thu 07 Jan 2021 03:08:16 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int partion(int *arr,int low ,int high){
    int pivotkey=arr[low];
    while(low<high){
        while(low<high&&arr[high]>=pivotkey) high--;
        //交换arr[low]和arr[high],不是pivotkey;
        swap(arr[high],arr[low]);
        while(low<high&&arr[low]<pivotkey) low++;
        swap(arr[low],arr[high]);
    }
    return low;
}

void quick_sort(int *arr,int low,int high){
    while(low<high){
        int pivot = partion(arr,low, high);
        quick_sort(arr,low,pivot-1);
       // quick_sort(arr,pivot+1,high);
        low=pivot+1;
    }
}

int main(){
    int arr[10]={12,4,5,8,5,10,1,9,6,14};
    quick_sort(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
