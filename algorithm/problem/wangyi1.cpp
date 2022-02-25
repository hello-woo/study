/*************************************************************************
	> File Name: wangyi1.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Thu 01 Apr 2021 07:31:38 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>>v;
vector<int>p1(20,0);
vector<int>p2(20,0);
vector<int>p3(20,0);
vector<int>p4(20,0);
int main(){
    int color,val;
    for(int i=0;i<27;i++){
        cin>>val>>color;
        if(val<15){
            if(color==1) p1[val]=1;
            if(color==2) p2[val]=1;
            if(color==3) p3[val]=1;
            if(color==4) p4[val]=1;
        }
    }
    int res=0;
    for(int i=2;i<=10;i++){
        int flag=1;
        for(int j=i;j<=i+4;j++){
            if(!p1[j]){
                flag=0;
                break;
            }
        }
        if(flag) res++;
    }
    if(p1[2]&&p1[3]&&p1[4]&&p1[5]&&p1[14]) res++;
    for(int i=2;i<=10;i++){
        int flag=1;
        for(int j=i;j<=i+4;j++){
            if(!p2[j]){
                flag=0;
                break;
            }
        }
        if(flag) res++;
    }
    if(p2[2]&&p2[3]&&p2[4]&&p2[5]&&p2[14]) res++;
    
    for(int i=2;i<=10;i++){
        int flag=1;
        for(int j=i;j<=i+4;j++){
            if(!p3[j]){
                flag=0;
                break;
            }
        }
        if(flag) res++;
    }
    if(p3[2]&&p3[3]&&p3[4]&&p3[5]&&p3[14]) res++;
    
    for(int i=2;i<=10;i++){
        int flag=1;
        for(int j=i;j<=i+4;j++){
            if(!p4[j]){
                flag=0;
                break;
            }
        }
        if(flag) res++;
    }
    if(p4[2]&&p4[3]&&p4[4]&&p4[5]&&p4[14]) res++;
    cout<<res<<endl;
}

