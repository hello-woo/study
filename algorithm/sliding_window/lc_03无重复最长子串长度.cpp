#include<bits/stdc++.h>

using namespace std;

//当一个字符出现次数大于1是，说明需要左边缩紧窗口
int lengthOfLongestSubstring(string s){
    int l = 0 ,r = 0;
    int ans = 0;
    unordered_map<char,int>mp;
    while(r < s.size()){
        mp[s[r]]++;
        while(mp[s[r]] > 1){
            mp[s[l]]--;
            l++;
        }
        r++;
        ans = max(ans,r - l);
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    int res = lengthOfLongestSubstring(s);
    cout << res <<endl;
    return 0;
}