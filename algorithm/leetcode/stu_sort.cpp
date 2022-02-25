/*************************************************************************
	> File Name: stu_sort.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 29 Nov 2020 01:29:09 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    string num,name;
    int cnt;
    char cl[25];
};
node q[10];
bool cmp(node&a,node&b){
    return a.num<b.num;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>q[i].num>>q[i].name>>q[i].cnt;
        for(int j=0;j<q[i].cnt;j++){
            cin>>q[i].cl[j];
        }
    }
    sort(q,q+n,cmp);
    for(int i=0;i<m;i++){
        char tmp=(char)('A'+i);
        cout<<tmp<<":";
        for(int j=0;j<n;j++){
            for(int k=0;k<q[j].cnt;k++){
                if(tmp==q[j].cl[k]){
                    cout<<q[j].num<<"["<<q[j].name<<']';
                }
            }
        }
        cout<<endl;
    }

    return 0;
}

