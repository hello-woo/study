/*************************************************************************
	> File Name: 146.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Thu 08 Oct 2020 11:19:51 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char s[50]={0};
    for(int i=0;i<50;i++){
        cin>>s[i];
        while(s[i]!=32){
           if(s[i]>=65&&s[i]<90||s[i]>=97&&s[i]<122){
                s[i]=s[i]+1;
            }else if(s[i]==90){
                s[i]=65;
            }else if(s[i]==122){
                s[i]=97;
            }
        }
        cout<<s[i];
    }
    return 0;
}
