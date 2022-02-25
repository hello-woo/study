/*************************************************************************
	> File Name: 381.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 17 Nov 2020 10:22:32 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

struct person{
    string name;
    int num,avg,cla,paper,m;
    char off,west;
};
int n,ans;
person stu[105];
bool cmp(person a,person b ){
    if(a.m==b.m){
        return a.num<b.num;
    }
    return a.m>b.m;
    
}
int func(int x){
    int t=0;
    if(stu[x].avg>80&&stu[x].paper>=1){
        t+=8000;
    }
    if(stu[x].avg>85&&stu[x].cla>80){
        t+=4000;
    }
    if(stu[x].avg>90){
        t+=2000;
    }
    if(stu[x].avg>80&&stu[x].west=='Y'){
        t+=1000;
    }
    if(stu[x].cla>80&&stu[x].off=='Y'){
        t+=850;
    }
    return t;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>stu[i].name>>stu[i].avg>>stu[i].cla>>stu[i].off>>stu[i].west>>stu[i].paper;
        stu[i].num=i;
        stu[i].m=func(i);
        ans+=stu[i].m;
    }

        sort(stu,stu+n,cmp);
        cout<<stu[0].name<<endl<<stu[0].m<<endl<<ans<<endl;
    return 0;
}
