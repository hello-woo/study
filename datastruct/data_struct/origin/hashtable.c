/*************************************************************************
	> File Name: hashtable.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 24 Mar 2021 09:22:38 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 769

typedef struct Node{
    int val;
    struct Node *next;
}Node;

typedef struct MyhashSet{
    Node *hash[MAX_SIZE];//存储链表头节点的数组;
}MyhashSet;

MyhashSet *myHashSetCreate(){
    MyhashSet *obj=(MyhashSet*)malloc(sizeof(MyhashSet));
    int i;
    for(int i=0;i<MAX_SIZE;i++){
        obj->hash[i]=(Node *)malloc(sizeof(Node));
        obj->hash[i]->val=0;
        obj->hash[i]->next=NULL;
    }
    return obj;
}

/*链表的头插法；在node之后插入值为key的节点*/
void addList(Node *node,int key){
    Node *temp=node->next;
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->val=key;
    node->next=newNode;
    newNode->next=temp;
    return ;
}

/*找到对应得元素并且删除*/
void removeList(Node *node,int key){
    Node *cur=node->next;
    Node *pre=node;
    while(cur!=NULL){
        if(cur->val==key){
            pre->next=cur->next;
            free(cur);
            return ;
        }
        pre=cur;
        cur=cur->next;
    }
}

/*判断元素是否在链表中*/
bool isContain(Node *node,int key){
    Node *cur=node->next;
    while(cur!=NULL){
        if(cur->val==key){
            return true;
        }
        cur=cur->next;
    }
    return false;
}

/*链表元素的释放*/

void freeList(Node *node){
    Node *cur=node;
    Node *tmp=NULL;
    while(cur!=NULL){
        tmp=cur;
        cur=cur->next;
        free(tmp);
    }
    return ;
}
/*已经存在，不添加，不存在加入hash中*/
void MyhashSetAdd(MyhashSet *obj,int key){
    if(isContain(obj->hash[key%MAX_SIZE],key)){
        return ;
    }
    addList(obj->hash[key%MAX_SIZE],key);
}

/*移除对应的元素*/
void myHashSetRemove(MyhashSet *obj,int key){
    removeList(obj->hash[key%MAX_SIZE],key);
}

/*判断是否包含*/
bool myHashSetContains(MyhashSet *obj,int key){
    return isContain(obj->hash[key%MAX_SIZE],key);
}

void myHashSetFree(MyhashSet *obj){
    for(int i=0;i<MAX_SIZE;i++){
        freeList(obj->hash[i]);
    }
    free(obj);
}


