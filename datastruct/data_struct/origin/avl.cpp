/*************************************************************************
	> File Name: avl.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Thu 14 Jan 2021 03:55:09 PM CST
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>
/*
#define L(n) (n?n->lchild:NULL)
#define R(n) (n?n->rchild:NULL)
#define H(n) (n?n->h:0)*/

#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define H(n) (n->h)


typedef struct Node{
    int key,h;//结点的值和树高
    struct Node *lchild,*rchild;
}Node;

//虚拟头节点,可以访问结点的数据字段I
Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init__NIL(){
    NIL->key=0,NIL->h=0;
    NIL->lchild=NIL->rchild=NIL;
    return ;
}

Node *getNewNode(int key){
    Node *p=(Node *)malloc(sizeof(Node ));
    p->key=key;
    p->h=1;
    p->lchild=p->rchild=NIL;
    return p;
}

void clear(Node *root){
    if(root==NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void update_height(Node *root){
    root->h=(H(L(root))>H(R(root))?H(L(root)):H(R(root)))+1;
    return ;
}

Node *left_rotate(Node *root){
    Node *temp=root->rchild;
    root->rchild = temp->lchild;
    temp->lchild=root;
    update_height(root);
    update_height(temp);
    return temp;
}

Node *right_rotate(Node *root){
    Node *temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild=root;
    update_height(root);
    update_height(temp);
    return temp;
}

Node *maintain(Node*root){
    if(abs(H(L(root))-H(R(root)))<=1) return root;
    //左子树树高比右子树树高高;即为LR和LL失衡;
    if(root->lchild->h > root->rchild->h){
        //左子树的左子树树高比左子树的右子树的树高低(LR类型);
        //先进行小左旋
        if(root->lchild->lchild->h < root->lchild->rchild->h){
            root->lchild=left_rotate(root->lchild);
        }
        //LL类型只用进行大右旋
        root=right_rotate(root);
        //RL和RR类型失衡
    }else{
        //RL类型，先经行小右旋
        if(root->rchild->lchild->h > root->rchild->rchild->h){
            root->rchild=right_rotate(root->rchild);
        }
        //RR类型置用进行大左旋
        root=left_rotate(root);
    }
    return root;
}


//root中插入指为key的结点

Node *insert(Node *root,int key){
    if(root==NIL) return getNewNode(key);
    if(root->key==key) return root;
    if(key < root->key){
        root->lchild=insert(root->lchild,key);
    }else{
        root->rchild=insert(root->rchild,key);
    }
    update_height(root);
    //回溯过程中调整节点
    return maintain(root);
}


Node *predecessor(Node *root){
    Node *temp=root->lchild;
    while(temp->rchild) temp=temp->rchild;
    return temp;
}

Node *erase(Node *root,int key){
    if(root==NIL) return NIL;
    if(key < root->key){
        root->lchild=erase(root->lchild,key);
    }else if(key>root->key){
        root->rchild=erase(root->rchild,key);
    }else{
        if(root->lchild==NIL||root->rchild==NIL){
            Node *temp=root->lchild!=NIL?root->lchild:root->rchild;
            free(root);
            return temp;
        }else{
            Node *temp=predecessor(root);
            root->key=temp->key;
            root->lchild=erase(root->lchild,temp->key);
        }
    }
    update_height(root);
    //回溯过程中调整节点
    return maintain(root);
}
void print(Node *root){
    printf("(%d[%d],%d,%d)\n",
          root->key,root->h,
          root->lchild->key,
          root->rchild->key);
    return ;
}

void output(Node *root){
    if(root==NIL) return ;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return;
}

int main(){
    int op,val;
    Node *root=NIL;
    while(~scanf("%d%d",&op,&val)){
        switch(op){
            case 0:root=erase(root,val);break;
            case 1:root=insert(root,val); break;
        }
        output(root);
        printf("-------------\n");
    }
    return 0;
}



