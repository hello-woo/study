/*************************************************************************
	> File Name: tea.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 20 Mar 2021 04:14:11 PM CST
 ************************************************************************/

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int getcount(int mid,vector<int>&tea){
    int cnt=1;
    int sum=0;
    for(int i=0;i<tea.size();i++){
        if(sum+tea[i]>mid){
            cnt++;
            sum=tea[i];
        }else{
            sum+=tea[i];
        }
    }
    return cnt;
}

using namespace std;
int main(){
    int n,m,c;
    cin>>n>>m>>c;
    vector<int>tea(n,0);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        tea[i]=temp;
    }
    int left=0,right=0;
    for(int i=0;i<n;i++){
        right+=tea[i];
        if(left<tea[i]){
            left=tea[i];
        }
    }
    while(left<right){
        int mid=(left+right)>>1;
        if(getcount(mid,tea)<=m){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    cout<<left<<endl;
    cout<<ceil(left*1.0/c)<<endl;
    return 0;
}
