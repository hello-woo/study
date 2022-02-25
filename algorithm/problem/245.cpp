/*************************************************************************
> File Name: 245.cpp
> Author:zhaozhicai
> Mail:1871259919@qq.com 
> Created Time: Fri 19 Mar 2021 08:56:21 PM CST
************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    vector<int>like;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        like.push_back(temp);
    }
    cin>>m;
    vector<vector<int>>test(m,vector<int>(3,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            int temp;
            cin>>temp;
            test[i][j]=temp;
        }
    }
    for(int i=0;i<m;i++){
        int cnt=0;
        for(int j=test[i][0];j<=test[i][1];j++){
            if(like[j-1]==test[i][2]){
                cnt++;
            }

        }
        cout<<cnt<<endl;

    }
    return 0;

}
