/*************************************************************************
	> File Name: houzhui.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 05 Dec 2020 07:44:32 PM CST
 ************************************************************************/

#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

int n;

string in_s[1005];
string out_s[1005];
bool cmp(string s1,string s2){
    return s1<s2;

}


int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%s",&in_s[i]);
    }
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }

    return 0;

}
