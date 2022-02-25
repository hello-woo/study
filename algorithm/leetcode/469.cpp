/*************************************************************************
	> File Name: 469.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 09 Apr 2021 10:50:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
    int x;
    string n;
    cin>>x>>n;
    int ind=1;
    int ans=0;
    for(int i=n.size()-1;i>=0;i--){
        ans+=(n[i]-'0')*ind;
        ind*=x;
    }
    cout<<ans<<endl;
    return 0;
}
