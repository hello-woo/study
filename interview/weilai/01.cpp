#include<bits/stdc++.h>

using namespace std;


int main(){
    string s;
    cin >> s;
    stack<char>sta;
    bool flag = true;
    for(int i = 0 ;i < s.size();){
        if(i == 0 && s[i] != '<') {
            flag = false;
        }
    
        string temp = "";
        while(i < s.size() && s[i] != '>'){
            temp += s[i];
            i++;
        }
        cout << temp;
        if(s.substr(i,2) !="</"){
            flag = false;
        }else{
            i += 2;
        }
    }
    if(flag ){
        cout <<"YES"<<endl;
    }else{
        cout <<"No"<<endl;
    }
    system("pause");
    return 0;
}