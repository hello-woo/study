/*************************************************************************
	> File Name: pri_queue.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 08 Jan 2021 11:36:49 AM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>


#define swap(a,b){\
    __typeof(a) __temp=a;\
    a=b;b=__temp;\
}
typedef struct pri_queue{
    int *data;
    int cnt,size;
}pri_queue;

pri_queue *init(int n){
    pri_queue *p=(pri_queue *)malloc(sizeof(pri_queue));
    p->data=(int *)malloc(sizeof(int)*(n+1));
    p->cnt=0;
    p->size=n;
    return p;
}

void clear(pri_queue *p){
    if(p==NULL) return;
    free(p->data);
    free(p);
    return ;
}

int top(pri_queue *p){
    return p->data[1];
}

int push(pri_queue *p,int val){  
    if(p==NULL) return 0;
    if(p->cnt==p->size) return 0;
    p->data[++(p->cnt)]=val;
    int ind = p->cnt;
    while(ind>>1&&p->data[ind]>p->data[ind>>1]){
        swap(p->data[ind],p->data[ind>>1]);
        ind>>=1;
    }
    return 1;
} 
int empty(pri_queue *p){
    return p->cnt==0;
}

int pop(pri_queue *p){
    if(p==NULL) return 0;
    if(empty(p)) return 0;
    p->data[1]=p->data[p->cnt--];
    int ind=1;
    while((ind<<1)<p->cnt){
        int temp = ind ,l=ind<<1,r=ind<<1|1;
        if(p->data[l] > p->data[temp]) temp = l;
        if(r<=p->cnt&&p->data[r] > p->data[temp]) temp = r;
        if(ind==temp) break;
        swap(p->data[ind],p->data[temp]);
        ind = temp;
    }
    return 1;
}

int main(){
    srand(time(0));
    #define max_op 20
    pri_queue *q=init(max_op);
//循环创建max-op个元素，并且插入到优先队列
    for(int i=0;i<max_op;i++){
        int val=rand()%100;
        push(q,val);
        printf("insert %d to the pri_queue \n",val);
    }
    for(int i=0;i<max_op;i++){
        printf("%d ",top(q));
        pop(q);
    }
    printf("\n");
    clear(q);
    #undef max_op 
    return 0;
}
