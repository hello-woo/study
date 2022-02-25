/*************************************************************************
	> File Name: 01.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 27 Apr 2021 07:42:13 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N=5005;
int num[N];

int main(){
    int n;
    cin>>n;
    vector<int>f(n+1,0);//f[i] ,前i个数中为0的个数;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(num[i]==0){
            cnt++;
        }
        f[i]=cnt;
//        cout<<f[i]<<endl;
    }
    if(f[n]==0) {
        cout<<n-1<<endl;
        return 0;
    }
    if(f[n]==n){
        cout<<n<<endl;
        return 0;
    }
    int res=0;
    int maxminlus=INT_MIN;
    int left=0;
    int right=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int qujian=f[j]-f[i]-(j-f[j]-i+f[i]);
//            cout<<"qujian: "<<qujian<<endl;
            if(qujian>=maxminlus){
                maxminlus=qujian;
            }
        }
    }
  //  cout<<maxminlus<<endl;
    cout<<maxminlus+n-f[n]<<endl;
    return 0;
}
