/*************************************************************************
	> File Name: sort.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 23 Mar 2021 06:48:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
void bubble_sort(int *arr,int len){
    int flag=1;
    for(int i=0;i<len&&flag;i++){
        flag=0;
        for(int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=1;
            }
        }
    }
}
void select_sort(int *arr,int n){
    for(int i=0;i<n;i++){
        int min_Index=i;
        for(int j=i+1;j<n;j++){
            if(arr[min_Index]>arr[j]){
                min_Index=j;
            }
        }
        swap(arr[min_Index],arr[i]);
    }
}
void inser_sort(int *arr,int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
void shell_sort(int *arr,int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=arr[i];
            int j=i-gap;
            while(j>=0&&arr[j]>temp){
                arr[j+gap]=arr[j];
                j-=gap;
            }
            arr[j+gap]=temp;
        }
    }
}

void heapAdjust(int *arr,int n,int index){
    int maxIndex=index;
    int l=2*index+1;
    int r=2*index+2;
    if(l<n&&arr[l]>arr[maxIndex]) maxIndex=l;
    if(r<n&&arr[r]>arr[maxIndex]) maxIndex=r;
    if(maxIndex!=index){
        swap(arr[maxIndex],arr[index]);
        heapAdjust(arr,n,maxIndex);
    }
}

void heap_sort(int *arr,int n){
    for(int i=n/2-1;i>0;i--){
        heapAdjust(arr,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapAdjust(arr,i,0);
    }
}
int main(){
    int arr[]={10,4,6,7,8,5,4,5,3,2};
    int len=sizeof(arr)/sizeof(int);
    //shell_sort(arr,len);
    heap_sort(arr,len);
   // bubble_sort(arr,len);
   // select_sort(arr,len);
    //inser_sort(arr,len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
