/*************************************************************************
	> File Name: euler04.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 04 Nov 2020 10:37:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int func(int x){
    int t=0,tmp=x;
    while(x){
        t=t*10+x%10;
        x=x/10;
    }
    return t==tmp;
}
int main(){
    int ans=0;
    for(int i=100;i<1000;i++){
        for(int j=i;j<1000;j++){
            int t=i*j;
            if(func(t)){
                ans=max(ans,t);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
