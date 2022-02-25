/*************************************************************************
	> File Name: quick_find_union.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 10 Jan 2021 01:14:18 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct UnionSet{
    int *color;
    int n;
}UnionSet;

UnionSet *init(int n){
    UnionSet *u=(UnionSet *)malloc(sizeof(UnionSet));
    u->color=(int *)malloc(sizeof(int)*(n+1));//将0好位置空出来
    u->n=n;
    for(int i=1;i<=n;i++){
        u->color[i]=i;
    }
    return u;
}

//查找操作
int find(UnionSet *u,int x){
    return u->color[x];
}

//合并操作
int merge(UnionSet *u,int a,int b){
    if(find(u,a)==find(u,b)) return 0;
    int color_a=u->color[a];
    for(int i=1;i<=u->n;i++){
        //和a的颜色不同，什么都不做直接coninue结束本次循环进入下一次循环
        if(u->color[i]!=color_a) continue; 
        //把所有和a颜色相同的元素的颜色全部改为b的颜色;
        u->color[i]=u->color[b];
    }
    return 1;
}




void clear(UnionSet *u){
    if(u==NULL) return ;
    free(u->color);
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
