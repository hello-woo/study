/*************************************************************************
	> File Name: 222.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 15 Jan 2021 05:16:36 PM CST
 ************************************************************************/

#include<iostream>
#include<climits>
using namespace std;

#define MAX_N 10000

//线段树的空间大小开辟为节点数量的4倍
struct {
    int max_num;
}Tree[MAX_N<<2];

int arr[MAX_N+5];

void update(int ind){
    Tree[ind].max_num=max(Tree[ind<<1].max_num,Tree[ind<<1|1].max_num);
    return ;
}

void build_tree(int ind,int l,int r){
    //当左右节点的索引相等时，将值赋给对应的节点；
    if(l==r){
        Tree[ind].max_num=arr[l];
        return ;
    }
    int mid=(l+r)>>1;
    build_tree(ind<<1,l,mid);
    build_tree(ind<<1|1,mid+1,r);
    update(ind);
}

void modify(int ind ,int l,int r,int k,int val){
    if(l==r){
        Tree[ind].max_num=val;
        return ;
    }
    int mid=(l+r)>>1;
    if(k<=mid){
        modify(ind<<1,l,mid,k,val);
    }else{
        modify(ind<<1|1,mid+1,r,k,val);
    }
    update(ind);
}
int query(int ind ,int l,int r,int x,int y){
    if(l>=x&&r<=y){
        return Tree[ind].max_num;
    }
    int ans=INT_MIN;
    int mid=(l+r)>>1;
    if(mid>=x){
        ans=max(ans,query(ind<<1,l,mid,x,y));
    }
    if(mid<y){
        ans=max(ans,query(ind<<1|1,mid+1,r,x,y));
    }
    return ans;
}

int main(){
    int n,m,a,b,c;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",arr+i);
    }
    //线段树根节点的坐标从一开始
    build_tree(1,1,n);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        switch(a){
            case 1: modify(1,1,n,b,c);break;
            case 2:{
                if(b>c){
                    cout<<"-2147483648"<<endl;
                    break;
                }
                printf("%d\n",query(1,1,n,b,c));
            } break;
        }
    }
    return 0;
}
