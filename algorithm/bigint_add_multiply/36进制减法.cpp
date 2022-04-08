#include<bits/stdc++.h>

using namespace std;

//s1 > s2 判断
bool cmp(string s1,string s2){
    if(s1.size() == s2.size()) return s1 > s2;
    return s1.size() > s2.size();
}

int getdigit(char c){
    if( c >= '0' && c <= '9'){
        return c - '0';
    }else if(c >= 'a' && c <= 'z'){
        return c - 'a' + 10;
    }
    return 0;
}

char getchar(int val){
    if(val >=0 && val <= 9){
        return val + '0';
    }else if(val >= 10 && val <= 35){
        return val - 10 + 'a';
    }
    return ' ';
}

string do_sub(string s1,string s2){
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    int borrow = 0;
    string ans = "";
    while(i >=0 || j >= 0 || borrow){
        int a = (i >= 0) ? getdigit(s1[i]) : 0;
        int b = (j >= 0) ? getdigit(s2[j]) : 0;
        int curval = (a - b + 36 - borrow) % 36;
        borrow = a - b - borrow < 0 ? 1 : 0;
        ans += getchar(curval);
        i--,j--;
    }
    reverse(ans.begin(),ans.end());
    //去除前导0
    int pos ;
    for(pos = 0 ; pos < ans.size() - 1; pos++ ){
        if(ans[pos] != '0') break;
    }
    return ans.substr(pos);
}

string subString(string s1,string s2){
    string ans = "";
    if(cmp(s1,s2)){
        ans = do_sub(s1,s2);
    }else{
        ans = do_sub(s2,s1);
        ans.insert(ans.begin(),'-');
    }
    return ans;
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    cout << subString(s1,s2) << endl;
    return 0;
}