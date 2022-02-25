/*************************************************************************
> File Name: tencent3.cpp
> Author:zhaozhicai
> Mail:1871259919@qq.com 
> Created Time: Mon 05 Apr 2021 12:05:53 AM CST
************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
ll t,n;
double w;
struct node{
    int a,b;
}a[maxn];
bool check(double mid){
    //判断是否可行
    double ans=mid*w;//总电量
    double cnt=0;
    for(int i=1;i<=n;i++){
        double x=mid*(double)a[i].b-(double)a[i].a;//每一个手机的需求
        if(ans>=x&&x>0){
            cnt+=x/w;//充电的总时间
            ans-=x;
        }else if(x<0){
            //如果需求为负数则不需要操作
            continue;
        }else{
            //无法满足，直接返回false
            return false;
        }
    }
    if(cnt>mid)return false;//如若充电事件大于mid也为false
    return true;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>w;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b;
        }
        double l=0,r=1e18,pos=0;
        cout<<r<<endl;
        while(l<r){
            //二分
            double mid=(l+r)/2.0;
            if(check(mid)){
                l=mid;
            }else{
                r=mid;
            }
            if(fabs(mid-pos)<1e-7){
                //当前一次的答案和本次的答案差距在1e-7之内，则精度符合要求
                pos=mid;
                break;
            }else{
                pos=mid;
            }
        }
        if(r==1e18){
            //如若最后r不变，则表示答案无限大，输出-1
            cout<<-1<<endl;
        }else{
            //反之输出pos
            cout<<pos<<endl;
        }

    }

}

