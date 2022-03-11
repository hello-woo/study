/*************************************************************************
	> File Name: heap_sort.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 08 Jan 2021 04:08:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void HeapAdjust(int *arr,int n,int i){
    if(i >= n) return;
    int smallest = i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&arr[l]<arr[smallest]) smallest=l;
    if(r<n&&arr[r]<arr[smallest]) smallest=r;
    if(i!=smallest){
        swap(arr[i],arr[smallest]);
        i=smallest;
        HeapAdjust(arr,n,i);
    }
}

void HeapSort(int *arr,int n){
    //建堆，最后一个父节点开始，自下而上建堆，
    //长度为n,从0开始，最后一个为n-1,其父节点为(n - 1 -1)/2 = n / 2 -1
    for(int i=n/2-1;i>=0;i--) {
        HeapAdjust(arr,n,i);
    }
    //每次将堆顶元素和最后一个元素互换，然后将最后一个元素砍掉
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        HeapAdjust(arr,i,0);//每次对堆顶自下而上开始调整
    }
}

int main(){
    int arr[10]={1,4,5,2,1,12,8,9,11,10};
    int len=sizeof(arr)/sizeof(int);
//    printf("%d\n",len);
    HeapSort(arr,len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
