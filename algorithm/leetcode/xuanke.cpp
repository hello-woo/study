/*************************************************************************
	> File Name: xuanke.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 29 Nov 2020 08:04:32 PM CST
 ************************************************************************/

#include<algorithm>
#include<iostream>
using namespace std;

struct student{
    string num,name;
    int cnt;
    char list[25];
};

int n,m;
struct student stu[100];

bool cmp(student &a,student&b){
    return a.num<b.num;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>stu[i].num>>stu[i].name>>stu[i].cnt;
        for(int j=0;j<stu[i].cnt;j++){
            cin>>stu[i].list[j];
        }
    }
    sort(stu,stu+n,cmp);
    for(int i=0;i<m;i++){
        char temp=(char)('A'+i);
        cout<<temp<<":";
        for(int i=0;i<n;i++){
            for(int k=0;k<stu[i].cnt;k++){
                if(temp==stu[i].list[k]){
                    cout<<'['<<stu[i].num<<','<<stu[i].name<<']';
                }
            }
        }
        cout<<endl;
    }


    return 0;
}
