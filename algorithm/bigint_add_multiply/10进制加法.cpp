#include<bits/stdc++.h>

using namespace std;

//10进制加法
string add10String(string s1,string s2){
    int i = s1.size() - 1,j = s2.size() - 1;
    int carry = 0;
    string ans = "";
    while (i >= 0 || j >= 0 || carry){
        int a1 = (i >= 0) ? (s1[i] - '0') :0;
        int b1 = (j >= 0) ? (s2[j] - '0') :0;
        int curval = a1 + b1 + carry;

        carry = curval / 10;

        ans += (curval % 10 + '0');
        i--;
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s1,s2;
    cin >> s1 >>s2;
    string res = add10String(s1,s2);
    cout <<res << endl;
    return 0;
}