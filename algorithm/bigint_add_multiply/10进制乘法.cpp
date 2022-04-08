#include<bits/stdc++.h>

using namespace std;

string addString(string s1,string s2){
    int i = s1.size() -1;
    int j= s2.size() - 1;
    int carry = 0;
    string ans = "";
    while(i >= 0 || j >= 0 || carry){
        int a = (i >=0) ? s1[i] - '0' : 0;
        int b = (j >=0) ? s2[j] - '0' : 0;
        int curval = a + b + carry;
        carry = curval / 10;
        ans += curval % 10 + '0';
        i--,j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


string getTenMultiply(string s1,string s2){
    if(s1 == "0" || s2 == "0") return "0";
    int n1= s1.size() - 1,n2 = s2.size() - 1;
    string res = "";
    for(int i = n2 ;i >=0 ;i--){
        int carry = 0;
        string ans ="";
        for(int j = n1 ;j >=0;j--){
            int curval = (s1[j] - '0') * (s2[i] - '0') + carry;
            carry = curval / 10;
            ans += curval % 10 + '0';
        }
        if(carry) ans += carry + '0';
        reverse(ans.begin(),ans.end());
        cout << ans << endl;
        //对于每一位添加对应个数的0;
        int tail = n2 - i;
        ans += string(tail,'0');
        // while(tail--){
        //     ans +='0';
        // }
        res = addString(ans, res);
    }
    return res;
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    string res = getTenMultiply(s1,s2);
    cout << res << endl;
    return 0;
}