/*************************************************************************
	> File Name: huiwen.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 27 Mar 2021 03:56:23 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int>findhuiwen(string start,string end){
    vector<int>res;
    int startnum=start+'0';
    int endnum=end+'0';
    for(int i=startnum;i<=endnum;i++){
        if(is_huiwen(i)&&is_huiwen(pow(i,3))){
            res.push_back(i);
        }
    }
    return res;
}


int main(){

    return 0;
}
