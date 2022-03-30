#include<bits/stdc++.h>

using namespace std;

bool check(char c){
    if(c >= 'a' && c <= 'z' || c >='A' && c <= 'Z') return true;
    else return false;
}

string getAnswer(string s){
    if(!check(s[0])) return "Wrong";
    cout << " xx " <<endl;
    bool digtiflag = false;
    bool charflag = false;
    bool noother = true;
    for(int i = 0 ;i < s.size();i++){
        //是数字
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
            digtiflag = true;
            //是字符。
            //cout << s[i] << " ,"<<endl;
        }else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            charflag = true;
        }else{
            noother = false;
        }
    }
    return digtiflag && charflag && noother == true ? "Accept" : "Wrong";
}

int main(){
    int T;
    cin >> T;
    while(T--){
       string s;
       cin >> s;
       cout << getAnswer(s) <<endl;
    }
    return 0;
}