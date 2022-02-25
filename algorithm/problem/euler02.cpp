/*************************************************************************
	> File Name: euler02.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 04 Nov 2020 10:29:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int a=1,b=1,c=2,ans=0;
    while(c<=4000000){
        if(c%2==0){
            ans+=c;
        }
        c=b+c;
        a=b;
        b=c-a;
    }
    cout<<ans<<endl;
    return 0;
}
