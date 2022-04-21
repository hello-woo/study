#include<bits/stdc++.h>

using namespace std;

vector<vector<int>>getNum(vector<int>&nums,int tar){
    unordered_map<int,int>mp1;
    unordered_map<int,int>mp2;
    vector<vector<int>>ans;
    for(int i = 0 ; i < nums.size();i++){
        mp1[nums[i]] = i;
        mp2[nums[i]]++;
    }

    for(int i = 0 ; i< nums.size();i++){
        int tarval = tar - nums[i];
        if(mp1.find(tarval)!=mp1.end()  && mp2[nums[i]] != 0 && mp2[tarval] !=0){
            ans.push_back({nums[i],tarval});
            mp2[nums[i]]--;
            mp2[tarval]--;
        }
    }
    return ans;
}

int main(){
    vector<int>nums={1,2,2,3,3,4,4,5,5,6};
    vector<vector<int>>ans = getNum(nums,8);
    for(auto p : ans){
        for(auto v : p){
            cout << v << ",";
        }
        cout << endl;
    }
    return 0;
}