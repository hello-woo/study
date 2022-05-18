/*************************************************************************
	> File Name: bubble_sort.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 13 Dec 2020 09:54:38 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

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

//冒泡排序优化版本，如果一轮有序，则不操作
void bubble_sort_opt(vector<int>&nums){
    for(int i = 0 ; i< nums.size();i++){
        bool flag = false;
        for(int j = 0 ;j < nums.size() - i - 1;j++){
            if(nums[j] > nums[j + 1] ){
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                flag = true;
            }
        }
        if(flag == false) break;
    }
}

int main(){
    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62  };
    int len = (int) sizeof(arr) / sizeof(*arr);
    //bubble_sort(arr, len);
    vector<int>nums = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62  };
    bubble_sort_opt(nums);
    for(auto p : nums){
        cout << p << " , ";
    }
    cout << endl;
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
