/*************************************************************************
	> File Name: heap1.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 08 Jan 2021 07:06:52 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;


void heapAdjust(int *arr,int n,int index){
    if(index>=n) return ;
    int smallest=index;
    int l=2*index+1;
    int r=2*index+2;
    if(l<n&&arr[l]<arr[smallest]) smallest=l;
    if(r<n&&arr[r]<arr[smallest]) smallest=r;
    if(smallest!=index){
        swap(arr[smallest],arr[index]);
        heapAdjust(arr,n,smallest);
    }
}


void heapsort(int *arr,int n){
    for(int i=n/2-1;i>=0;i--){
        heapAdjust(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapAdjust(arr,i,0);
    }
}

void output(int *arr,int n){
    cout<<'[';
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<']'<<endl;
}

int main(){
    srand(time(0));
    #define max_n 20
    int *arr=new int [max_n];
    for(int i=0;i<max_n;i++){
        arr[i]=rand()%100;
    }
    cout<<"origin: ";
    output(arr,max_n);
    heapsort(arr,max_n);
    cout<<"sorted: ";
    output(arr,max_n);
    delete[]arr;
    return 0;
}
