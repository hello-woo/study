/*************************************************************************
> File Name: ispalindroom.cpp
> Author:zhaozhicai
> Mail:1871259919@qq.com 
> Created Time: Mon 08 Mar 2021 11:55:57 AM CST
************************************************************************/


#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
bool ispalindroom(string s){
    int left=0,right=s.size()-1;
    while(left<right){
        if(s[left++]!=s[right--]){
            return false;
        }
    }
    return true;
}
vector<string>path;
string str="";

void dfs(string s,int start,int len,vector<bool>&used){
    if(str.size()==len){
        path.push_back(str);
        return ;
    }
    for(int i=0;i<len;i++){
        if(used[i]) continue;
        if(i>0&&s[i]==s[i-1]&&used[i-1]==true) continue;
        str.push_back(s[i]);
        used[i]=true;
        dfs(s,i+1,len,used);
        used[i]=false;
        str.pop_back();
    }
}
bool canPermutePalindrome(string s) {
    if(s.size()==0) return false;
    int n=s.size();
    sort(s.begin(),s.end());
    vector<bool>used(n,false);
    dfs(s,0,n,used);
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<endl;
    }
    return false;
}


int main(){
    string s;
    cin>>s;
    cout<<ispalindroom(s)<<endl;
    canPermutePalindrome(s);
    return 0;
}

