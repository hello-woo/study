#include<bits/stdc++.h>

using namespace std;

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


//36进制加法
string add36String(string s1,string s2){
    int i = s1.size() - 1,j = s2.size() - 1;
    int carry = 0;
    string ans = "";
    while (i >= 0 || j >= 0 || carry){
        int a1 = (i >= 0) ? getdigit(s1[i]) :0;
        int b1 = (j >= 0) ? getdigit(s2[j]) :0;
        int curval = a1 + b1 + carry;

        carry = curval / 36;

        ans += getchar(curval % 36);
        i--;
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s1,s2;
    cin >> s1 >>s2;
    string res = add36String(s1,s2);
    cout <<res << endl;
    return 0;
}