#include<bits/stdc++.h>

using namespace std;

int ans = 0;
vector<int>path;

bool check(vector<int>& path){
    int sum = 0;
    set<int>s;
    for(int i = 0 ; i < path.size();i++){
        if(!s.count(i))
    }
}

void dfs(vector<int>& nums,int tar ,int index,int sum,int wrong,vector<bool>&used){
    if(tar == sum){
        ans++;
        return;
    }else if(sum < tar){
        return;
    }
    for(int i = index;i < nums.size();i++){
        if(!used[i]){
            wrong++;
            if(wrong < 3){
                sum -= nums[i];
                used[i] = true;
                dfs(nums,tar,i + 1,sum ,wrong,used);
                used[i] = false;
                sum += nums[i];
            }
            wrong--;
        }
    }
}


int main(){
    int n;
    cin >> n;
    vector<int>pro = {2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,8,8,8,8,8};
    if(n == 0 ) cout << 1 << endl;
    vector<bool>used(25,false);
    dfs(pro,n,0,100,0,used);
    cout << ans << endl;
}