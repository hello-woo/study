/*************************************************************************
	> File Name: haffman.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 15 Jan 2021 03:45:20 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define swap(a,b){\
    __typeof(a) __temp=a;\
    a=b,b=__temp;\
}

typedef struct Node{
    char ch;
    double pro;
    struct Node *lchild,*rchild;
}Node;

Node *getNewNode(char ch,double pro){
    Node *p=(Node *)malloc(sizeof(Node));
    p->ch=ch;
    p->pro=pro;
    p->lchild=p->rchild=NULL;
    return p;
}

//两个节点合并成一个节点
Node *CombinNode(Node *a,Node *b){
    Node *p=getNewNode(0,a->pro + b->pro);
    p->lchild=a;
    p->rchild=b;
    return p;
}

void clear(Node *root){
    if(root==NULL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void pick_min(Node **arr,int n){
    for(int j=n-1;j>=0;j--){
        if(arr[n]->pro > arr[j]->pro){
            swap(arr[n],arr[j]);
        }
    }
    return ;
}


Node *getHaffmanTree(Node **arr,int n){
    //循环找到概率最小的两个节点合并；
    for(int i=1;i<n;i++){
//以下代码优化为优先队列，每次弹出最小概率元素；
        pick_min(arr,n-i);
        pick_min(arr,n-i-1);
        //合并为新节点
        arr[n-i-1]=CombinNode(arr[n-i],arr[n-i-1]);
    }
    return arr[0];
}

void __output_encode(Node *root,char *str,int k){
    str[k]=0;
    if(root->lchild==NULL&&root->rchild==NULL){
        printf("%c %s\n",root->ch,str);
        return ;
    }
    str[k]='0';
    __output_encode(root->lchild,str,k+1);
    str[k]='1';
    __output_encode(root->rchild,str,k+1);
    return ;
}

void output_encode(Node *root){
    char str[100];
    __output_encode(root,str,0);
    return ;
}

int main(){
    int n;
    Node **arr;
    scanf("%d",&n);
    arr=(Node **)malloc(sizeof(Node*)*n);
    for(int i=0;i<n;i++){
        char ch[10];
        double p;
        scanf("%s%lf",ch,&p);
        arr[i]=getNewNode(ch[0],p);
    }
    Node *root=getHaffmanTree(arr,n);
    output_encode(root);
    clear(root);
    free(arr);
    return 0;
}
