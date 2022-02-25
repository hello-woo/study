/*************************************************************************
	> File Name: select_sort.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 13 Dec 2020 10:08:11 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

void selection_sort(float *arr,int len){
    for(int i=0;i<len-1;i++){
        int minIndex=i;
        for(int j=i+1;j<len;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

int main(){
    float arrf[] = { 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4  };
    int len=(int)sizeof(arrf)/sizeof(*arrf);
    selection_sort(arrf,len);
    for (int i = 0; i < len; i++)
        cout << arrf[i] << ' ';
    return 0;
}
