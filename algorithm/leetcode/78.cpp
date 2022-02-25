/*************************************************************************
	> File Name: 78.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 04 Apr 2021 01:48:51 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string a,b;
string addstring(string a,string b){
    int i=a.size()-1;
    int j=b.size()-1;
    int carry=0;
    string res="";
    while(i>=0||j>=0||carry){
        int num_a=(i>=0)?a[i]-'0':0;
        int num_b=(j>=0)?b[j]-'0':0;
        int sum=num_a+num_b+carry;
        carry=sum/10;
        res+=(sum%10+'0');
        i--;
        j--;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    cin>>a;
    cin>>b;
    string c=addstring(a,b);
    cout<<c<<endl;
    return 0;
}
