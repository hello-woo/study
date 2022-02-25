/*************************************************************************
	> File Name: hz.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 05 Dec 2020 08:25:15 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

string s[1005];
string s_reverse(string s){
    char temp=s[0];
    string ans=s;
    int len=s.length();
    for(int i=0;i<len;i++){
        temp=s[i];
        ans[i]=s[len-i-1];
        s[len-i-1]=temp;
    }
    return ans;
}
int main(){
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%s",&s[i]);
    }
    for(int i=0;i<n;i++){
       printf("%s\n", s_reverse(s[i]));
    }
    return 0;
}

