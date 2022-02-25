/*************************************************************************
	> File Name: 380.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 17 Nov 2020 09:58:36 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

struct node{
    int num;
    string s;
};

int n;
node p[10];
bool cmp(node &a,node &b){
    if(a.s.size()==b.s.size()){
        return a.s.size()>b.s.size();
    }
    return a.s.size()>b.s.size();
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].s;
        p[i].num=i;
    }
    sort(p+1,p+n+1,cmp);
    cout<<p[1].num<<endl<<p[1].s<<endl;

    return 0;
}
