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
#include<vector>


using namespace std;
void output(int *,int);

int partion(int *arr,int low,int high){
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
    if(low>=high) return;
    int pivot=partion(arr,low,high);
    quick_sort(arr,low,pivot);
    quick_sort(arr,pivot+1,high);
}

void bubble_sort(int *arr,int n){
    cout<<"orgin:";
    output(arr,n);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1],arr[j]);
            }
        }
    }
    cout<<"bubble_sort sorted:";
    output(arr,n);
}

void select_sort(int *arr,int n){
    cout<<"orgin:";
    output(arr,n);
    for(int i=0;i<n;i++){
        int min_Index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_Index]){
                min_Index=j;
            }
        }
        swap(arr[min_Index],arr[i]);
    }
    cout<<"select sorted:";
    output(arr,n);
}

void insert_sort(int *arr,int n){
    cout<<"orgin:";
    output(arr,n);
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    cout<<"insert sorted:";
    output(arr,n);
}

void shell_sort(int *arr,int n){
    cout<<"orgin:";
    output(arr,n);
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=arr[i];
            int preindex=i-gap;
            while(preindex>=0&&arr[preindex]>temp){
                arr[preindex+gap]=arr[preindex];
                preindex-=gap;
            }
            arr[preindex+gap]=temp;
        }
    }
    cout<<"shell sorted:";
    output(arr,n);
}

void heapAdjust(int *arr,int n,int index){
    if(index>=n) return;
    int maxindex=index;
    int l=2*index+1;
    int r=2*index+2;
    if(l<n&&arr[l]>arr[maxindex]) maxindex=l;
    if(r<n&&arr[r]>arr[maxindex]) maxindex=r;
    if(maxindex!=index){
        swap(arr[maxindex],arr[index]);
        index=maxindex;
        heapAdjust(arr,n,index);
    }
}

void heapsort(int *arr,int n){
    cout<<"orgin: ";
    output(arr,n);
    //建堆
    for(int i=n>>1;i>=0;i--){
        heapAdjust(arr,n,i);
    }
    for(int i=n;i>=0;i--){
        swap(arr[0],arr[i]);
        heapAdjust(arr,i-1,0);
    }
    cout<<"heap sorted: ";
    output(arr,n);

}
void merge_(int *arr,int left,int mid,int right,vector<int>&temp){
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
    for( k=0,i=left;i<=right;i++,k++){
        arr[i]=temp[k];
    }
}
void merge_sort(int *arr,int left ,int right,vector<int>&temp){
    if(left>=right) return ;
    int mid=(left+right)>>1;
    merge_sort(arr,left,mid,temp);
    merge_sort(arr,mid+1,right,temp);
    merge_(arr,left,mid,right,temp);
}
void output(int *arr,int n){
    cout<<'[';
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<']'<<endl;
}

int *init_arr(int n){
    srand(time(0));
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        arr[i]=rand()%100;
    }
    return arr;
}


int main(){
    #define max_n 20
    vector<int>temp(max_n,0);
    int *arr=init_arr(max_n);
    bubble_sort(arr,max_n);
    arr=init_arr(max_n);
    insert_sort(arr,max_n);
    arr=init_arr(max_n);
    select_sort(arr,max_n);
    arr=init_arr(max_n);
    heapsort(arr,max_n-1);
    arr=init_arr(max_n);
    shell_sort(arr,max_n);
    arr=init_arr(max_n);
    merge_sort(arr,0,max_n-1,temp);
    output(arr,max_n);
    arr=init_arr(max_n);
    quick_sort(arr,0,max_n-1);
    output(arr,max_n);
    delete[]arr;
    return 0;
}
