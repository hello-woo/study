/*************************************************************************
	> File Name: 87.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 21 Sep 2020 12:23:56 AM CST
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include"stdlib.h"
using namespace std;
int main(){
    double a,b;
    cin>>a>>b;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<2*(a+b)<<endl;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<a*b<<endl;
    return 0;
}
