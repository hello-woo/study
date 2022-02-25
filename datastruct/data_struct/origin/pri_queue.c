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
    int cnt ,size;
}pri_queue;

pri_queue *init(int n){
    pri_queue *q = (pri_queue *)malloc(sizeof(pri_queue));
    q->data=(int *)malloc(sizeof(int)*(n+1));
    q->cnt=0;
    q->size=n;
    return q;
}

void clear(pri_queue *q){
    if(q==NULL)return ;
    free(q->data);
    free(q);
    return ;
}

int empty(pri_queue *q){
    return q->cnt==0;
}

int top(pri_queue *q){
    return q->data[1];
}


int push(pri_queue *q,int val){
    if(q==NULL) return 0;
    if(q->cnt==q->size) return 0;
    q->data[++(q->cnt)]=val;
    //插入调整，
    int ind=q->cnt;
    //不为0 ，有父节点
    while(ind >>1&&q->data[ind]>q->data[ind>>1]){
        swap(q->data[ind],q->data[ind>>1]);
        ind>>=1;
    }
    return 1;
}

int pop(pri_queue *q){
    if(q==NULL) return 0;
    if(empty(q)) return 0;
    q->data[1]=q->data[q->cnt--];
    int ind=1;
    //左孩子变量合法
    while((ind<<1)<=q->cnt){
        int temp=ind,l=ind<<1,r=ind<<1|1;
        if(q->data[l]>q->data[temp]) temp =l;
        if(r<=q->cnt&&q->data[r]>q->data[temp]) temp=r;
        if(temp==ind) break;
        swap(q->data[temp],q->data[ind]);
        ind =temp;
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
