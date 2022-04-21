#include<bits/stdc++.h>


using namespace std;

void print(int * arr,int n,string name){
    cout <<name << " : ";
    for(int i = 0 ;i < n ;i++){
        cout << arr[i] << ",";
    }
    cout << endl;
    return ;
}

void heap_adjust(int *arr,int i ,int len){
    if(i >=len) return ;
    int smallest = i;
    int left_node = 2 *i + 1;
    int right_node = 2 *i + 2;
    //这里只是找到最小得下标，值还没有交换
    if(left_node < len && arr[left_node] < arr[smallest]) smallest = left_node;
    if(right_node < len && arr[right_node] < arr[smallest]) smallest = right_node;
    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heap_adjust(arr,smallest,len);
    }
}

void heap_sort(int *arr,int len){
    int lastnode = len - 1;
    int last_parent_node=  (lastnode - 1) / 2;
    //建堆
    for(int i = last_parent_node ;i >= 0;i--){
        heap_adjust(arr,i,len);
    }
    //每次取出
    for(int i = len - 1; i >= 0;i--){
        swap(arr[0],arr[i]);
        heap_adjust(arr,0,i);
    }
}

int partion(int* arr,int low,int high){
    int pivotkey = arr[low];
    while(low < high){
        while(low < high && arr[high] > pivotkey) high--;
        swap(arr[high],arr[low]);
        while(low < high && arr[low] <= pivotkey) low++;
        swap(arr[high],arr[low]);
    }
    cout << "low:" << low << endl;
    return low;
}

void quick_sort(int*arr,int low,int high){
    if(low > high) return;
    int pivot = partion(arr,low,high);
    quick_sort(arr,low,pivot - 1);
    quick_sort(arr,pivot + 1,high);
    for(int i = low ; i <= high ;i++){
        cout << arr[i] << " , ";
    }
    cout << endl;
}

int main(){
    int arr[] = {10,5,3,4,5,2,1,3,6,7};
    int len = sizeof(arr) / sizeof(int);
    //heap_sort(arr,len);
    quick_sort(arr,0,len - 1);
    print(arr,len,"heapSort");
    return 0;
}