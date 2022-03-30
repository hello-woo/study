#include<bits/stdc++.h>

using namespace std;

/*
窗口内最多有K个不同字符的最长长度；

当窗口unordered_map.size() > k时说明要缩紧窗口，左边界右移

注意：这里要判断数量减为0之后，要将key值erase掉
*/
int K_Length(string s,int k){
    int l = 0, r = 0;
    int ans = 0;
    unordered_map<char,int>mp;
    while(r < s.size()){
        mp[s[r]]++;

        while (mp.size() > k)
        {
            mp[s[l]]--;
            //如果数量减为0，说明要删除这个key.
            if(mp[s[l]] == 0){
                mp.erase(s[l]);
            }
            //左窗口右移；
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
    int k;
    cin >> k;
    int res = K_Length(s,k);
    cout << res <<endl;

    return 0;
}