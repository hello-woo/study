/*************************************************************************
	> File Name: test123.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 19 Mar 2021 07:41:54 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a;
    vector<int>b;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    for(int j=0;j<n;j++){
        int temp;
        cin>>temp;
        b.push_back(temp);
    }
    int res=0x3f3f3f;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]<=a[j]&&a[j]<=a[k]){
                    res=min(res,b[i]+b[j]+b[k]);
                }
            }
        }
    }
    res==0x3f3f3f?-1:res;
    cout<<res<<endl;
    return 0;
}
