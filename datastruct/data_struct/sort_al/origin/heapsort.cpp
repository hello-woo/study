#include<bits/stdc++.h>

using namespace std;


//对第i个节点构成的三角，进行堆调整，然后递归调整
void heap_adjust(int* arr,int n ,int i){
    if(i >= n) return;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;
    int max = i;
    if(left < n && arr[left] > arr[max]) max = left;
    if(right < n && arr[right] > arr[max]) max = right;
    if(i != max){
        swap(arr[i],arr[max]);
        heap_adjust(arr,n,max);
    }
}

void build_heap(int* arr,int n){
    int lastnode = n - 1;
    int last_parent_node = (lastnode - 1)/2;
    for(int i = last_parent_node ;i >= 0 ;i--){
        heap_adjust(arr,n,i);
    }
}

void heap_sort(int *arr,int n){
    build_heap(arr,n);
    for(int i = n - 1; i >=0 ;i--){
        swap(arr[0],arr[i]);
        heap_adjust(arr,i,0);
    }
}

int main(){
    int arr[] = {5,1,4,6,7,9,5};
    int len = sizeof(arr) /sizeof(int);
    heap_sort(arr,len);
    for(int i = 0 ; i< len;i++){
        cout << arr[i] << ",";
    }
    cout <<endl;
    // int arr2[] = {4,10,2,5,1,3};
    // heap_adjust(arr2,6 ,0);
    // for(int i = 0 ; i< 6 ;i++){
    //     cout << arr2[i] << ",";
    // }
    return 0;
}

//     4            10
//  10    2 ---- >5    2
// 5  1  3      4   1   3