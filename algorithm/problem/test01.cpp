/*************************************************************************
	> File Name: test01.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 27 Mar 2021 08:53:04 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int arr[]={7,6,6,5,15};
    int len=5;
    int a=arr[0];
    for(int i=1;i<len;i++){
        cout<<(a^arr[i])<<endl;
    }
    return 0;
}
