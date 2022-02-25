/*************************************************************************
	> File Name: 378.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 05 Dec 2020 09:30:33 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int main(){
    string s;
    cin>>s;
    stack<char>sta;
    for(int i=0;i<s.size();i++){
        if(s[i]=='{'||s[i]=='('||s[i]=='[') {
            sta.push(s[i]);
        }else if(s[i]==')'){
            if(sta.empty()||sta.top()!='('){
                cout<<"NO"<<endl;
                return 0;
            }
            sta.pop();
        }else if(s[i]==']'){
            if(sta.empty()||sta.top()!='['){
                cout<<"NO"<<endl;
                return 0;
            }
            sta.pop();
        }else if(s[i]=='}'){
            if(sta.empty()||sta.top()!='{'){
                cout<<"NO"<<endl;
                return 0;
            }
            sta.pop();
        }   
    }
    if(sta.empty()){
        cout<<"YES"<<endl;                
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
