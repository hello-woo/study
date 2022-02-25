/*************************************************************************
	> File Name: euler06.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 07 Nov 2020 10:17:08 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int now=1,zero_cnt,ans;
int main(){
    int num[10]={1,2,3,4,0,4,0,4,2,8};
    for(int i=0;i<10;i++){
        if(i<3){
            now*=num[i];
        }else{
            if(num[i]==0){
                zero_cnt++;
            }else{
                now*=num[i];
            }
            if(num[i-3]==0){
                zero_cnt--;
            }else{
                now/=num[i-3];
            }
        }
        if(zero_cnt==0){
            ans=max(ans,now);
        }
    }
    cout<<ans<<endl;
    return 0;
}
