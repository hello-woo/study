/*************************************************************************
	> File Name: 223.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 15 Jan 2021 08:54:59 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 10000
int arr[MAX_N+5];
struct{
    int sum;
    int tag;//懒标记
}tree[MAX_N<<2];


void update(int ind){
    tree[ind].sum=tree[ind<<1].sum+tree[ind<<1|1].sum;
    return ;
}

void build_tree(int ind,int l,int r){
    if(l==r){
        tree[ind].sum=arr[l];
        return ;
    }
    int mid=(l+r)>>1;
    build_tree(ind<<1,l,mid);
    build_tree(ind<<1|1,mid+1,r);
    update(ind);
    return ;
}
void down(int ind,int l,int r){
    if(tree[ind].tag){
        int val=tree[ind].tag;
        int mid=(l+r)>>1;
        //更新左右子树的懒标记及和
        tree[ind<<1].sum+=val*(mid-l+1);
        tree[ind<<1].tag+=val;
        tree[ind<<1|1].sum+=val*(r-mid);
        tree[ind<<1|1].tag+=val;
        //清空当前节点的懒标记；
        tree[ind].tag=0;
    }
    return;
}

void modify(int ind ,int l,int r,int x,int y,int val){
    if(l>=x&&r<=y){
        tree[ind].sum+=(r-l+1)*val;
        tree[ind].tag+=val;//打上懒标记
        return ;
    }
    //懒标记下沉
    down(ind,l,r);
    int mid=(l+r)>>1;
    if(mid>=x){
        modify(ind<<1,l,mid,x,y,val);
    }
    if(mid<y){
        modify(ind<<1|1,mid+1,r,x,y,val);
    }
    update(ind);
    return ;
}

int query(int ind ,int l,int r ,int x,int y){
    if(x<=l&&r<=y){
        return tree[ind].sum;
    }
    //懒标记下沉
    down(ind,l,r);
    int mid=(l+r)>>1;
    int ans=0;
    if(mid>=x){
        ans+=query(ind<<1,l,mid,x,y);
    }
    if(mid<y){
        ans+=query(ind<<1|1,mid+1,r,x,y);
    }
    return ans;
}

int main(){
    int n,m,a,b,c,d;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",arr+i);
    }
    build_tree(1,1,n);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        switch(a){
            case 1:{
                scanf("%d",&d);
                modify(1,1,n,b,c,d);
            }break;
            case 2:{
                if(b>c){
                    printf("0\n");
                    break;
                } else{
                   printf("%d\n", query(1,1,n,b,c));
                }
            }break;
        }
    }
    return 0;
}
