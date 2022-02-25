/*************************************************************************
	> File Name: 235.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 20 Nov 2020 09:48:49 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n,cnt =0,num[15];

void p(){
    for(int i=0;i<=cnt;i++){
        if(i){
            cout<<" ";
        }
         cout<<num[i];
    }
    cout<<endl;
}

void func(int s){
    for(int i=s;i<=n;i++){
        num[cnt]=i;
        p();
        cnt++;
        func(i+1);
        cnt--;
    }
}


int main(){
    cin>>n;
    func(1);
    return 0;
}
