#include<bits/stdc++.h>

using namespace std;


void getnum(string& s,int startIndex,int k,int l){
    set<string>se;
    string temp = s;
    reverse(temp.begin(),temp.end());
    for(int i = 0 ; i <k ;i++){
        s += temp;
        
    }
}

int main(){
    int t;
    cin >> t;
    int k,l;
    string s;
    while(t--){
        cin >> k >> l;
        cin >> s;
        getnum(s,0,k,l);
    }
    return 0;
}