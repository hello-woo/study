#include<bits/stdc++.h>

using namespace std;

//s1一定是大于s2的
string do_sub(string s1,string s2){
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    int borrow = 0;
    string ans = "";
    while(i >= 0 || j >= 0 || borrow){
        int a = (i >= 0) ? s1[i] - '0' : 0;
        int b = (j >= 0) ? s2[j] - '0' : 0;
        int curval = (a - b - borrow + 10) % 10;
        borrow = a - b - borrow < 0 ? 1 : 0;
        ans += curval + '0';
        i--,j--;
    }
    reverse(ans.begin(),ans.end());
    //去除前导零
    int pos;
    for(pos = 0 ;pos < ans.size() - 1;pos++){
        if(ans[pos] !='0') break;
    }
    return ans.substr(pos);
}

bool cmp(string s1,string s2){
    if(s1.size() == s2.size()) return s1 > s2;
    return s1.size() > s2.size();
}

string subString(string s1,string s2){
    //s1 > s2
    string res = "";
    if(cmp(s1,s2)){
        res = do_sub(s1,s2);
    }else {
        res = do_sub(s2,s1);
        if(res != "0") res.insert(res.begin(),'-');
    }
    return res;
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    cout << subString(s1,s2);
    return 0;
}