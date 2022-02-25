/*************************************************************************
	> File Name: 386.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 17 Nov 2020 10:37:20 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    //编号及数据
    int cnt ,num;

};
int n,m;
node wm[100005];
bool cmp(const node &a,const node &b){
    return a.num<b.num;
}
int main(){ 
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>wm[i].num;
        wm[i].cnt=i+1;
    }
    sort(wm,wm+n,cmp);
    for(int i=0;i<m;i++){
        int t,f=0,l=0,r=n-1;
        cin>>t;
        while(l<=r){
            int mid=(l+r)/2;
            if(t==wm[mid].num){
                f=wm[mid].cnt;
                break;
            }
            if(t<wm[mid].num){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<f<<endl;
    }
    return 0;
}
