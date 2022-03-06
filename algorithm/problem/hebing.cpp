#include<bits/stdc++.h>

using namespace std;


const int N = 1000000005;


int main(){
    int n ,l;
    cin >> n >> l;
    vector<vector<int>>nums(n,vector<int>(2,0));
    for(int i = 0; i < n;i++){
        int x,y;
        cin >> x >> y;
        nums[i][0] = x;
        nums[i][1] = y;
    }
    sort(nums.begin(),nums.end());
    int ans = 0;
    for(int i = 0 ; i < n;i++){
        for(int j = i + 1; j < n ;j++){
            int t = nums[j][0];
            if(t > nums[i][1]){
                t = 
            }
        }
    }

}