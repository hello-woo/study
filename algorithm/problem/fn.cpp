/*************************************************************************
	> File Name: fn.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 27 Mar 2021 04:18:49 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int n,m;
vector<int>a(n+1,0);
void solve(int num,vector<int>&a){
    int start=0;
    int end=0;
    for(int i=0;i<n;i++){
        if(a[i]==num){
            start=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]==num){
            end=i;
            break;
        }
    }
    if(start==0&&end==0){
        cout<<0<<endl;
    }else   cout<<start+1<<" "<<end+1<<endl;
} 

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a[i]=temp;
    }
    for(int i=0;i<m;i++){
        int num;
        cin>>num;
        solve(num,a);
    }
    return 0;
}
