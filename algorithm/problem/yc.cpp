/*************************************************************************
	> File Name: yihuo.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 27 Mar 2021 07:52:19 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int len;
vector<int>num(len+1,0);
int taget;
vector<int>dp(len+1,0);
int res=0;
int main(){
    cin>>len;
    for(int i=0;i<len;i++){
        int temp;
        cin>>temp;
        num[i]=temp;
    }
    cin>>taget;
    int sum=0;
    for(int i=0;i<len;i++){
        int temp=num[i];
        for(int j=i;j<len;j++){
            sum=temp^num[j];
            cout<<sum<<" ";
            if(sum<=taget) res++;
        }
        cout<<endl;
    }

    cout<<res<<endl;
}
