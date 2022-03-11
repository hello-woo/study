#include<bits/stdc++.h>

using namespace std;


int parti(int* arr,int left ,int right){
    int pivotkey = arr[left];
    while(left < right){
        while(left < right && arr[right] >= pivotkey) right--;
        swap(arr[right],arr[left]);
        while(left < right &&arr[left] < pivotkey) left++;
        swap(arr[left],arr[right]);
    }
    return left;
}

void quick_sort(int*arr,int left ,int right){
    if(left >= right) return;
    int pivot = parti(arr,left,right);
    quick_sort(arr,left,pivot);
    quick_sort(arr,pivot + 1,right);
}

void bubble_sort(int* arr,int n){
    for(int i = 0 ; i< n - 1;i++){
        for(int j = 0;j < n - i - 1;j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j],arr[j + 1]);
            }
        }
    }
}

void selection_sort(int* arr,int n ){
    for(int i = 0 ;i < n;i++){
        int minIndex = i;
        for(int j = i + 1;j < n;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

void insert_sort(int* arr,int n ){
    for(int i = 1;i < n;i++){
        int key = arr[i];
        while(i > 0 && key < arr[i - 1]){
            arr[i] = arr[i - 1];
            i--;
            //if(i == 0) break;
        }
        arr[i] = key;
    }
}

void heap_adjust(int* arr,int n ,int idx){
    if(idx >= n) return;
    int left = 2 * idx + 1;
    int right = 2 *idx + 2;;
    int max = idx;
    if(left < n && arr[left] > arr[max]) max = left;
    if(right < n && arr[right] > arr[max]) max = right;
    if(idx != max){
        swap(arr[idx],arr[max]);
        heap_adjust(arr,n,max);
    }
} 

void build_heap(int *arr,int n){
    int lastnode = n - 1;
    int last_parent_node = (lastnode - 1) / 2;
    for(int i = last_parent_node ;i >=0;i--){
        heap_adjust(arr,n,i);
    }
}

void heap_sort(int* arr,int n){
    build_heap(arr,n);

    for(int i = n -1 ;i >=0 ;i-- ){
        swap(arr[0],arr[i]);
        heap_adjust(arr,i,0);
    }
}

void merge_(int *arr,int left,int mid ,int right,int *temp){
    int i = left ,j = mid + 1,k = 0;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= right){
        temp[k++] = arr[j++];
    }
    for(int i = left ,k = 0;i <= right ;i++ ,k++){
        arr[i] = temp[k];
    }
}

void merge_sort(int* arr,int left,int right ,int *temp){
    if(left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort(arr,left,mid,temp);
    merge_sort(arr,mid + 1,right,temp);
    merge_(arr,left,mid,right,temp);
}

int main(){
    int arr[] = {5,1,4,6,7,9,5,5,4,6};
    int len = sizeof(arr) /sizeof(int);
    int* temp = new int[len];
    merge_sort(arr,0,len - 1,temp);
    //heap_sort(arr,len);
    //quick_sort(arr,0,len - 1);
    //bubble_sort(arr,len);
    //insert_sort(arr,len);
    //selection_sort(arr,len);
    for(int i = 0 ; i< len;i++){
        cout << arr[i] << ",";
    }
    cout <<endl;
    return 0;
}