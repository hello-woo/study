#include<bits/stdc++.h>


using namespace std;

int binary_search(vector<int>& nums,int tar){
    int l = 0 ,r = nums.size() - 1;
    while(l <= r ){
        int mid = (l + r) /2;
        if(nums[mid] == tar) return mid;
        if(nums[mid] >= nums[0]){
            if(nums[0] <= tar && tar < nums[mid]){
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }else {
            if(tar > nums[mid] && tar <= nums[nums.size() - 1]){
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int>arr={4,5,6,7,1,2,3};
    int val;
    cin >> val;
    int res = binary_search(arr,val);
    cout << res << endl;
    return 0;
}