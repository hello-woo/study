/*************************************************************************
> File Name: correct_word.cpp
> Author:zhaozhicai
> Mail:1871259919@qq.com 
> Created Time: Sun 29 Nov 2020 09:40:15 PM CST
************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std; 
struct node{
    char c;
    int cnt;
};
node q[8];

int main(){
    string s;
    cin>>s;
    for(int i=0,j=0;i<s.length();i++,j++){
        if(s[i]!=s[i+1]){
            q[j].c=s[i];
            q[j].cnt=i+1;
        }
        cout<<q[j].c<<q[j].cnt;
    }

    return 0;
}
