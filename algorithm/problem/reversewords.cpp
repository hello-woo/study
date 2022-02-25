/*************************************************************************
> File Name: reversewords.cpp
> Author:zhaozhicai
> Mail:1871259919@qq.com 
> Created Time: Sat 20 Mar 2021 09:33:37 PM CST
************************************************************************/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    string s;
    while(cin>>s){
        reverse(s.begin(),s.end());
        if(s[0]=='.'){
            for(int i=1;i<s.size();i++){
                cout<<s[i];

            }
            break;

        }else{
            cout<<s<<" ";
        }

    }
    cout<<"."<<endl;
    return 0;

}
