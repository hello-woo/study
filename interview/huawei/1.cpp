#include<bits/stdc++.h>

using namespace std;

int ans = 0;
vector<int>path;

bool check(vector<int>&path){
    int maxindex = path.back();
    int ans = 0;
    for(int i = 0 ;i <= maxindex;i++){
        if(find(path.begin(),path.end(),i) == path.end()){
            ans++;
        }
    }
    if(ans > 3) return false;
    else if(ans == 3 && maxindex != 24) return false;
    return true;
}

void dfs(vector<int>&pro ,int sum,int startIndex,int tar){
    if(sum == tar){
        if(check(path)){
            ans++;
            return;
        }
    }
    for(int i = startIndex;i < pro.size();i++){
        sum += pro[i];
        path.push_back(i);
        dfs(pro,sum,i + 1,tar);
        path.pop_back();
        sum -= pro[i];
    }
}


int main(){
    int n;
    cin >> n;
    vector<int>pro = {2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,8,8,8,8,8};
    if(n == 0) cout << 1 << endl;
    dfs(pro,0,0,n);
    cout << ans << endl;
    return 0;
}