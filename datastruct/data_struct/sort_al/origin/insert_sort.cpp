/*************************************************************************
	> File Name: insert_sort.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 13 Dec 2020 10:21:45 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>

using namespace std;

void insert_sort(int *arr,int len){
    for(int i=1;i<len;i++){
        int key=arr[i];
        int j;
        //从后向前面扫描，直到小于
        for(j=i-1;j>=0&&key<arr[j];j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }
}

int main(){
    int arr[]={20,12,13,15,7,0,2,46,45};
    int len=(int)sizeof(arr)/sizeof(*arr);
    insert_sort(arr,len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return 0;
}
