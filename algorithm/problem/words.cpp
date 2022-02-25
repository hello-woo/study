/*************************************************************************
	> File Name: words.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 20 Mar 2021 11:02:44 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string ans[100005];
int num[10],snt[10],ans_cnt,letter_cnt;
char letter[10];

void func(int deep){
    if(deep==letter_cnt){
        p();
        return;
    }
    for(int i=1;i<=num[deep];i++){
        cnt[deep]=i;
    }
}

int main(){
    string start;
    cin>>start;
    start+='0';
    int now=1;
    for(int i=1;i<start.size();i++){
        if(start[i]==start[i-1]){
            now++;
        }else{
            num[letter_cnt]=now;
            letter[letter_cnt]=start[i-1];
            letter_cnt++;
            now=1;
        }
    }
    fun(0);
    return 0;
}
