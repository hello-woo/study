/*************************************************************************
	> File Name: merge_sort.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 22 Mar 2021 10:20:06 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


void merge_(int *arr,int left,int mid,int right,vector<int>&tmp){
    int i=left,j=mid+1,k=0;
    while(i<=mid&&j<=right){
            if(arr[i]<=arr[j]){
                tmp[k++]=arr[i++];
            }else{
                tmp[k++]=arr[j++];
            }
    }
    while(i<=mid){
        tmp[k++]=arr[i++];
    }
    while(j<=right){
        tmp[k++]=arr[j++];
    }
    for(int i=left,k=0;i<=right;i++,k++){
        arr[i]=tmp[k];
    }
}
void merge_sort(int *arr,int left,int right,vector<int>&tmp){
    if(left>=right) return ;
    int mid=left+(right-left)/2;
    merge_sort(arr,left,mid,tmp);
    merge_sort(arr,mid+1,right,tmp);
    merge_(arr,left,mid,right,tmp);
}



int main(){
    int arr[]={10,1,4,9,7,7,4,8,0,5};
    int len=sizeof(arr)/sizeof(int);
    vector<int>tmp(len,0);
//    merge_sort(arr,0,len-1,tmp);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
