
#include<bits/stdc++.h>

using namespace std;


void merge_(int* arr,int left,int mid ,int right ,vector<int>&temp){
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right){
        if(arr[i] >= arr[j]){
            temp[k++] = arr[j++];
        }else {
            temp[k++] = arr[i++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= right){
        temp[k++] = arr[j++];
    }
    for(int i = left,k = 0 ;i <= right ;i++,k++){
        arr[i] = temp[k];
    }
}


void merge_sort(int*arr,int left ,int right,vector<int>&temp){
    if(left >= right) return ;
    int mid = left + (right - left) / 2;
    merge_sort(arr,left,mid,temp);
    merge_sort(arr,mid + 1,right,temp);
    merge_(arr,left,mid ,right,temp);
}


void bubble_sort(int* arr,int len){
    for(int i = 0 ; i < len ;i++){
        for(int j = 0 ;j < len - i - 1; j++){
            if(arr[j] > arr[j + 1]) swap(arr[j],arr[j+1]);
        }
    }
}

void heapAdjust(int * arr,int index ,int len){
    int maxindex  = index;
    int leftNode  = 2 * index + 1;
    int rightNode = 2 * index + 2;
    if(leftNode < len && arr[leftNode] > arr[maxindex]) maxindex = leftNode;
    if(rightNode < len && arr[rightNode] > arr[maxindex]) maxindex = rightNode;
    if(index != maxindex){
        swap(arr[index],arr[maxindex]);
        heapAdjust(arr,maxindex,len);
    } 
}

//长度为len 取不到
void heapSort(int* arr,int len){
    int lastNode = len - 1;
    int lastParentNode = (lastNode - 1) / 2;
    for(int i = lastParentNode ;i >= 0 ;i--){
        heapAdjust(arr,i,len);
    }

    for(int i = len - 1; i > 0 ;i--){
        swap(arr[0],arr[i]);
        heapAdjust(arr,0,i);
    }
}

int partion(int *arr,int low,int high){
    int pivotKey = arr[low];
    while(low < high){
        while(low < high && arr[high] >= pivotKey) high--;
        swap(arr[low],arr[high]);
        while(low < high && arr[low] < pivotKey ) low++;
        swap(arr[low],arr[high]);
    }
    return low;
}

void quick_sort(int* arr,int low ,int high){
    if(low >= high) return;
    int pivot = partion(arr,low,high);
    quick_sort(arr,low,pivot - 1);
    quick_sort(arr,pivot + 1,high);
}

void select_sort(int* arr,int len){
    for(int i = 0 ; i < len ;i++){
        int minIndex = i;
        for(int j = i + 1; j < len ;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
}

void insert_sort(int* arr,int len){
    for(int i = 1 ; i < len ;i++){
        int temp = arr[i];
        int j = i - 1 ; // j = 0;
        while(j >= 0  && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}


int main(){
    int arr[]={10,4,6,7,8,9,4,2,3,1};
    int len=sizeof(arr)/sizeof(int);
    vector<int>temp(len,0);
   // merge_sort(arr,0,len-1,temp);ok
    //quick_sort(arr,0,len-1);
    //heapSort(arr,len);
    //shell_sort(arr,len);
    //bubble_sort(arr,len);ok
    //select_sort(arr,len);
    insert_sort(arr,len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}