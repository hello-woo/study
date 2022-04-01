#include<bits/stdc++.h>

using namespace std;


int binary_search(int arr[],int n,int val){
	int head=0,tail = n - 1;
	while(head < tail){
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

int main(){
    int arr[] = {1,2,3,3,5,6,7};
    cout << binary_search(arr,7,3);
    return 0;
}