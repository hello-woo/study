/*************************************************************************
	> File Name: vector.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 08 Jan 2021 07:41:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Vector{
    int *data;
    int length,size;
}Vec;

Vec *init(int n){
    Vec *v=(Vec *)malloc(sizeof(Vec));
    v->data=(int *)malloc(sizeof(int)*n);
    v->length=0;
    v->size=n;
    return v;
}

void clear(Vec *v){
    if(v==NULL) return ;
    free(v->data);
    free(v);
    return;
}
int expand(Vec *v){
    int extr_size=v->size;
    int *p;
    while(extr_size){
        p=(int *)realloc(v->data,sizeof(int)*(v->size+extr_size));
        if(p) break;
        extr_size/=2;
    }
    if(extr_size==0) return 0;
    v->data=p;
    v->size+=extr_size;
    return 1;
}

//1为插入成功
int insert(Vec *v,int val,int ind){
    if(ind<0||ind>v->length) return 0;
    if(v==NULL) return 0;
    if(v->length==v->size){
        if(!expand(v)) return 0;
        printf("success to expand the Vector size is %d\n",v->size);
    }
    for(int i=v->length;i>ind;i--){
        v->data[i]=v->data[i-1];
    }
    v->data[ind]=val;
    v->length+=1;
    return 1;
}

int erase(Vec *v,int ind){ 
    if(v==NULL) return 0;
    if(ind<0||ind>=v->length) return 0;
    for(int i=ind+1;i<v->length;i++){
        v->data[i-1]=v->data[i];
    }
    v->length-=1;
    return 1;
}

void output(Vec *v){
    if(v==NULL) return ;
    printf("[");
    for(int i=0;i<v->length;i++){
        i&&printf(" ");
        printf("%d",v->data[i]);
    }
    printf("]\n");
    return;
}

int main(){
    srand(time(0));
    #define max_op 20
    Vec *v=init(5);
    for(int i=0;i<max_op;i++){
        int val=rand()%100;
        int ind=rand()%(v->length+2)-1;//测试负数和大于的操作
        int op=rand()%4 ;//操作0,1,2插入，3为删除
        switch(op){
            case 0:
            case 1:
            case 2:
                printf("insert %d at %d to Vector = %d\n",val,ind,insert(v,val,ind));
                break;
            case 3:
                printf("erase a iterm at %d from Vector=%d\n",ind,erase(v,ind));
                break;
        }
        output(v);
        printf("\n");
    }
    clear(v);
    #undef max_op
    return 0;
}
