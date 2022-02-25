/*************************************************************************
	> File Name: dancifanzhuan.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 29 Nov 2020 07:19:10 PM CST
 ************************************************************************/

#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
string reversewords(string str){  
    int start=0,end=0,restart;
    char temp;
    for(int i=0;i<str.length()+1;i++){
        if(str[i]==' '||str[i]=='.'){  
        end=i-1;
        while(start<=end){
            temp=str[end];
            str[end]=str[start];
            str[start]=temp;
            start++;
            end--;
        }
        start=i+1;
         }
    }
    return str;
}

int main(){
    string str="";
    getline(cin,str);
    string ans=reversewords(str);
    cout<<ans;
    return 0;
}

