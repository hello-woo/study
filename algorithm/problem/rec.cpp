/*************************************************************************
> File Name: rec.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 30 Mar 2021 11:07:59 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;
vector<pair<pair<long,long>,pair<long,long>>>rec;
int main(){
    long n;
    long lx,ly,rx,ry;
    cin>>n;
    vector<long>le_x(n,0);
    vector<long>le_y(n,0);
    vector<long>ri_x(n,0);
    vector<long>ri_y(n,0);
    for(long i=0;i<n;i++){
        cin>>lx;
        le_x[i]=lx;
    }
    for(long i=0;i<n;i++){
        cin>>ly;
        le_y[i]=ly;
    }
    for(long i=0;i<n;i++){
        cin>>rx;
        ri_x[i]=rx;
    }
    for(long i=0;i<n;i++){
        cin>>ry;
        ri_y[i]=ry;
    }
    for(long i=0;i<n;i++){
        rec.push_back(make_pair(make_pair(le_x[i],le_y[i]),make_pair(ri_x[i],ri_y[i])));
    }
    long res=0;
    for(long i=0;i<n;i++){
        long ans=1;
        for(long j=i+1;j<n;j++){
            if(rec[i].second.first>=rec[j].first.first&&rec[i].second.second>=rec[j].first.second){
                ans++;
//                cout<<"里面多的";
  //              cout<<ans<<endl;
            }
        }
        res=max(res,ans);
    }
    cout<<res<<endl;
    return 0;
}
