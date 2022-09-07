// #include<bits/stdc++.h>

// using namespace std;

// vector<vector<string>>ans;
// vector<string>path;

// bool ishuiwen(string s){
//     int l = 0,r = s.size() - 1;
//     while(l < r){
//         if(s[l++] != s[r--]) return false;
//     }
//     return true;
// }

// void dfs(string s,int startIndex){
//     if(startIndex == s.size()){
//         ans.push_back(path);
//         return;
//     }
//     for(int i = startIndex;i < s.size();i++){
//         string temp = s.substr(startIndex ,i - startIndex + 1);
//         if(ishuiwen(temp)){
//             path.push_back(temp);
//             dfs(s,i + 1);
//             path.pop_back();
//         }
//     }
// }

// vector<vector<string>>getString(string s){
//     int n = s.size();
//     if(n == 0) return ans;
//     dfs(s,0);
//     return ans;
// }

// int main(){
//     string s;
//     cin >> s;
//     int index = 0;
//     for(int i =0 ;i < s.size();i++){
//         if(s[i] == '='){
//             index = i;
//             break;
//         }
//     }
//     string s1 = s.substr(index + 1);
//     vector<vector<string>>ans = getString(s1);
//     cout << "[";
//     for(auto p : ans){
//         cout << "[";
//         for(auto s : p){
//             cout << " << s << " <<",";
//         }
//         cout << "]";
//     }
//     cout << "]";
//     return 0;
// }

//03
#include<bits/stdc++.h>

using namespace std;
vector<vector<int>>ans;
vector<int>path;


void dfs(int startIndex,int n,int k){
    if(path.size() == k){
        ans.push_back(path);
        return ;
    }
    for(int i = startIndex;i <= n;i++){
        path.push_back(i);
        dfs(i + 1,n,k);
        path.pop_back();
    }
}

int main(){
    string s;
    cin >> s;
    int index = 0;
    string s1 = "";
    for(int i = 0 ; i < s.size();i++){
        if(s[i] == '='){
            index = i;
        }
        if(s[i] == ','){
            s1 = s.substr(index,i - index + 1);
        }
    }
    string s2 = s.substr(index);
    int n = stoi(s1),k = stoi(s2);
    ans.clear();
    dfs(1,n,k);
    cout << "[";
    for(int i = 0; i < ans.size();i++){
        cout << "[";
        for(int j = 0 ;j < k;j++){
            cout << ans[i][j];
            j != k - 1 && cout << ",";
        }
        cout << "]";
        cout << ",";
    }
    cout << "]";
    return 0;
}