/*************************************************************************
	> File Name: list.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 09 Jan 2021 10:22:29 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct ListNode{
    int data;
    struct ListNode *next;
}ListNode;

typedef struct List{
    ListNode head; //变量，不是指针，方便链表节点的插入和删除，虚拟头节点（没有数据域）
    int length; //当前链表的长度信息
}List;
//初始化结点
ListNode *getNewNode(int );
//初始化链表
List *getLinkList();
//删除结点
void clear_node(ListNode *);
//删除链表
void clear(List *);
//链表的插入
int insert (List *,int ,int );
//链表的删除
int erase(List *,int );
//reverse
void reverse(List *l);
//输出
void output(List *);


ListNode *getNewNode(int val){
    ListNode *p=(ListNode *)malloc(sizeof(ListNode));
    p->data=val;
    p->next=NULL;
    return p;
}

List *getLinkList(){
    List *l=(List *)malloc(sizeof(List));
    l->head.next=NULL;
    l->length=0;
    return l;
}

int insert(List *l ,int ind,int val){
    if(l==NULL)return 0;
    if(ind<0||ind>l->length) return 0;
    //p指向虚拟头节点的地址,防止在头结点插入
    ListNode *p=&(l->head),*node=getNewNode(val);
    //找到待插入结点的前一个位置；
    while(ind--) p=p->next;
    node->next=p->next;
    p->next=node;
    l->length += 1;
    return 1;
}

int erase(List *l,int ind){
    if(l==NULL) return 0;
    if(ind<0 || ind>=l->length) return 0;
    ListNode *p=&(l->head) ,*q;
    //找到到删除结点的前一个位置；
    while(ind--){
        p=p->next;
    }
    q=p->next;
    p->next=q->next;
    free(q);
    l->length-=1;
    return 1;
}

void reverse(List *l){
    ListNode *p=l->head.next,*q;
    l->head.next=NULL;
    while(p){
        q=p->next;
        p->next=l->head.next;
        l->head.next=p;
        p=q;
    }
    return;
}

void output(List *l){
    if(l==NULL) return;
    printf("List(%d)=[",l->length);
    for(ListNode *p=l->head.next;p;p=p->next){
        printf("%d->",p->data);
    }
    printf("NULL]\n");
    return;
}

void clear_node(ListNode *node){
    if(node==NULL) return;
    free(node);
    return ;
}

void clear(List *l){
    if(l==NULL) return;
    ListNode *p=l->head.next,*q;
    while(p){
        q=p->next;
        clear_node(p);
        p=q;
    }
    free(l);
    return ;
}

int main(){
    srand(time(0));
    #define max_op 20
    List *l=getLinkList();
    for(int i=0;i<max_op;i++){
        int val=rand()%100;
        //模拟所有输出
        int ind=rand()%(l->length+3)-1;
        int op=rand()%5;
        switch(op){
            case 0:
            case 1:
            case 2:{
                printf("insert %d at %d to List = %d\n",val,ind,insert(l,ind, val));
                break;
            }
            case 3:
                printf("erase iterm at %d from List = %d\n",ind ,erase(l,ind));
                break;
            case 4:
                printf("reverse the List !\n");
                reverse(l);
                break;
        }
        output(l);
        printf("\n");
    }
    #undef max_op 
    clear(l);
    return 0;
}

