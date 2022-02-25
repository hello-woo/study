/*************************************************************************
	> File Name: all_sort.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 24 Mar 2021 10:29:07 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void bubble_sort(int *arr,int len){
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i-1;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1],arr[j]);
            }
        }
    }
}
void select_sort(int *arr,int len){
    for(int i=0;i<len;i++){
        int minIndex=i;
        for(int j=i+1;j<len;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
}
void insert_sort(int *arr,int len){
    for(int i=1;i<len;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void shell_sort(int *arr,int len){
    for(int gap=len/2;gap>0;gap/=2){
        for(int i=gap;i<len;i++){
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
    int maxindex=index;
    int l=2*index+1;
    int r=2*index+2;
    if(l<n&&arr[l]>arr[maxindex]) maxindex=l;
    if(r<n&&arr[r]>arr[maxindex]) maxindex=r;
    if(maxindex!=index){
        swap(arr[index],arr[maxindex]);
        heapAdjust(arr,n,maxindex);
    }
}


void heapSort(int *arr,int n){
    for(int i=n/2-1;i>=0;i--){
        heapAdjust(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapAdjust(arr,i,0);
    }
}

int partion(int *arr,int low,int high){
    int pivotkey=arr[low];
    while(low<high){
        while(low<high&&arr[high]>=pivotkey)  high--;
        swap(arr[low],arr[high]);
        while(low<high&&arr[low]<pivotkey) low++;
        swap(arr[low],arr[high]);
    }
    return low;
}

void quick_sort(int *arr,int low,int high){
    if(low>=high) return ;
    int pivot=partion(arr,low,high);
    quick_sort(arr,low,pivot);
    quick_sort(arr,pivot+1,high);
}

void merge_(int* arr,int left,int mid,int right,vector<int>&temp){
    int i=left,j=mid+1,k=0;
    while(i<=mid&&j<=right){
        if(arr[i]>=arr[j]){
            temp[k++]=arr[j++];
        }else{
            temp[k++]=arr[i++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }
    for(int i=left,k=0;i<=right;i++,k++){
        arr[i]=temp[k];
    }

}

void merge_sort(int *arr,int left,int right,vector<int>&temp){
    if(left>=right) return ;
    int mid=(left+right)/2;
    merge_sort(arr,left,mid,temp);
    merge_sort(arr,mid+1,right,temp);
    merge_(arr,left,mid,right,temp);
}

int main(){
    int arr[]={10,4,6,7,8,9,4,2,3,1};
    int len=sizeof(arr)/sizeof(int);
    vector<int>temp(len,0);
 //   merge_sort(arr,0,len-1,temp);
   // quick_sort(arr,0,len-1);
    //heapSort(arr,len);
    //shell_sort(arr,len);
   // bubble_sort(arr,len);
   // select_sort(arr,len);
    insert_sort(arr,len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
