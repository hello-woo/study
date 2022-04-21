#include<bits/stdc++.h>

using namespace std;

int binary_search(int arr[],int n,int val){
	int head=0,tail = n - 1;
	while(head <= tail){
		int mid=(head+tail)/2;
		if(arr[mid]==val){
			return mid;
		}else if(arr[mid]>val){
			tail=mid-1;
		}else{
			head=mid+1;
		}
	}
	return -1;
}

//查找111110000的最后一个1； /arr[mid] <= target 为1
int binary_search_last(int* arr,int n,int val){
    int l = 0 ,r = n - 1;
    while(l < r){
        int mid = (r + l + 1) /2;
        //如果在1的区间里面
        if(arr[mid] <= val){
            l = mid ;
        //如果是0的区间
        }else{
            r = mid - 1;
        }
    }
    return l;
}

//0001111,搜索第一个1
int binary_search_first(int* arr,int n,int val){
    int l = 0,r= n - 1;
    while(l < r){
        int mid = (l + r) / 2;
        //如果是在满足条件为1的一边
        if(arr[mid] >= val){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    return l;
}

int main(){
    int arr[] = {1,2,3,3,3,5,6,7};
    int arr1[] = {1,2,3,5,6,7};
    cout << binary_search(arr1,7,3)<<endl;
    cout << binary_search_first(arr,7,3)<<endl;
    cout << binary_search_last(arr,7,4)<<endl;
    return 0;
}