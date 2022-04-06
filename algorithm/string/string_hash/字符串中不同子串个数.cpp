/*
确定字符串中不同子字符串的数量
问题：给定长为 n 的字符串，仅由小写英文字母组成，查找该字符串中不同子串的数量。

为了解决这个问题，我们遍历了所有长度为 l = 1,2,...n的子串。对于每个长度为 l，我们将其 Hash 值乘以相同的B的幂次方，
并存入一个数组中。数组中不同元素的数量等于字符串中长度不同的子串的数量，并此数字将添加到最终答案中。

为了方便起见，我们将使用 h[i] 作为 Hash 的前缀字符，并定义h[0] = 0 。
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e8;
const int MOD = 1e7 + 7;
const int B = 13313;

ll hashVal[N];
ll bVal[N];


ll gethashVal(int l,int r){
    return (hashVal[r] - hashVal[l - 1] *bVal[r - l + 1] % MOD + MOD) % MOD;
}

int count_unique_substrings(string& s){
    int n = s.size();
    s = ' ' + s;

    bVal[0] = 1;
    for(int i = 1; i <= n;i++){
        hashVal[i] = (hashVal[i - 1] * B + s[i] - 'a' + 1) % MOD;
        bVal[i] = (bVal[i - 1] * B) % MOD;
    }

    ll ans = 0;

    //枚举区间长度
    for(int len = 1; len <= n;len++){
        set<ll>s;
        //枚举左端点
        for(int i = 1; i + len - 1 <= n;i++){
            int j = i + len - 1; //右端点
            ll res = gethashVal(i,j);
            if(s.count(res) == 0) s.insert(res);
        }
        cout << s.size() << " <";
        ans += s.size();
    }
    return ans;
}

int main(){
    string s ;
    cin >> s;
    cout << count_unique_substrings(s) <<endl;
    return 0;
}