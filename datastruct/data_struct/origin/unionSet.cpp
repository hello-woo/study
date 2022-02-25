/*************************************************************************
	> File Name: quick_find_union.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 10 Jan 2021 01:14:18 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct UnionSet{
    int *father;
    int n;
}UnionSet;

UnionSet *init(int n){
    UnionSet *u=(UnionSet *)malloc(sizeof(UnionSet));
    u->father=(int *)malloc(sizeof(int)*(n+1));//将0好位置空出来
    u->n=n;
    for(int i=1;i<=n;i++){
        u->father[i]=i;
    }
    return u;
}

//查找操作
int find(UnionSet *u,int x){
    if (u->father[x]==x) return x;
    return find(u,u->father[x]);
}

//合并操作
int merge(UnionSet *u,int a,int b){
    int fa=find(u,a),fb=find(u,b);
    if(fa==fb) return 0;
    u->father[fa]=fb;
    return 1;
}

void clear(UnionSet *u){
    if(u==NULL) return ;
    free(u->father);
    free(u);
    return;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    UnionSet *u=init(n);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        switch(a){
            case 1:merge(u,b,c);break;
            case 2:
                printf("%s\n",find(u,b)==find(u,c)?"Yes":"No");
                break;
        }
    }
    clear(u);
    return 0;
}
