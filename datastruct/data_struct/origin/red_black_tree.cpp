/*************************************************************************
	> File Name: red_black_tree_insert.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Thu 14 Jan 2021 07:22:29 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int key;
    int color;//0 red,1 black,2 double black;
    struct Node *lchild,*rchild;
}Node;

Node __NIL;
#define NIL (&__NIL )
__attribute__((constructor))
void init__NIL(){
    NIL->key=0;
    NIL->color=1;
    NIL->lchild=NIL->rchild=NIL;
    return ;
}

Node *getNewNode(int key){
    Node *p=(Node *)malloc(sizeof(Node));
    p->key=key;
    p->color=0;
    p->lchild=p->rchild=NIL;
    return p;
}

int has_red_child(Node *root){
    return root->lchild->color==0||root->rchild->color==0;
}

Node* left_rotate(Node *root){
    Node *temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    return temp;
}

Node *right_rotate(Node *root){
    Node *temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild=root;
    return temp;
}

Node *insert_maintain(Node *root){
    //没有红色子孩子
    if(!has_red_child(root)) return root;
    //如果不发生冲突，修改也没有问题
    //情况1：两个子孩子都是红孩子;调整为红黑黑；
    if(root->lchild->color==0&&root->rchild->color==0){
        root->color=0;
        root->lchild->color=root->rchild->color=1;
        return root;
    }
    int flag=0;
    //左子树发生冲突
    if(root->lchild->color==0&&has_red_child(root->lchild)) flag=1;
    //右子树发生冲突
    if(root->rchild->color==0&&has_red_child(root->rchild)) flag=2;
    //如果没有发生冲突，直接返回;
    if(flag==0) return root;
    if(flag==1){
        //如果是LR类型，右旋之前还要进行小左旋;
        if(root->lchild->rchild->color==0){
            root->lchild=left_rotate(root->lchild);
        }
        root=right_rotate(root);
        //调整完成之后在经行调整为红黑黑
        //root->color=0;
       // root->lchild->color=root->rchild->color=1;
    }else{
        //如果是RL类型，先小右旋，最后进行大左旋
        if(root->rchild->lchild->color==0){
            root->rchild=right_rotate(root->rchild);
        }
        root=left_rotate(root);
        //颜色调整；
        //root->color=0;
        //root->lchild->color=root->rchild->color=1;
    }
    root->color=0;
    root->lchild->color=root->rchild->color=1;
    return root;
}

Node *__insert(Node *root,int key){
    if(root==NIL) return getNewNode(key);
    if(root->key==key) return root;
    if(root->key>key){
        root->lchild=__insert(root->lchild,key);
    }else{
        root->rchild=__insert(root->rchild,key);
    }
    return insert_maintain(root);
}

//强行把根节点的颜色改为黑色;
Node *insert(Node * root,int key){
    root=__insert(root,key);
    root->color=1;
    return root;
}

Node *predecessor(Node *root){
    Node *temp=root->lchild;
    while(temp->rchild) temp=temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root){
    //没有双重黑节点，不用调整，直接返回;
    if(root->lchild->color!=2&&root->rchild->color!=2) return root;
    //如果有红色节点
    if(has_red_child(root)){
        int flag= 0;
        //原根节点改成黑色；
        root->color=0;
        //兄弟节点的左子节点为红色，先右旋;
        if(root->lchild->color==0){
            root= right_rotate(root);
            flag=1;
        }else{
            root=left_rotate(root);
            flag=2;
        }
        //新根节点改成红色；
        root->color=1;
        if(flag == 1) root->rchild=erase_maintain(root->rchild);
        else root->lchild= erase_maintain(root->lchild);
        return root;
    }
    //处理情况1，兄弟节点的子节点都是黑色,待删除节点和兄弟节点颜色减1，父节点颜色加1;
    if(root->lchild->color==2&&!has_red_child(root->rchild)||
       root->rchild->color==2&&!has_red_child(root->lchild)){
        root->lchild->color-=1;
        root->rchild->color-=1;
        root->color += 1;
        return root;
    }

    //如果待删除的双重节点在左侧，说明兄弟节点在右侧;
    if(root->lchild->color == 2){
        //兄弟节点的右子树一定不是红色，此时即为严格的RL类型;
        //***不能写为等于1***
        if(root->rchild->rchild->color!=0){
            //对调新根与原根的颜色;
            root->rchild->color=0;//原根的颜色变成红色;
            root->rchild=right_rotate(root->rchild);
            root->rchild->color=1;//新根的颜色变成黑色;
        }
        root=left_rotate(root);
        //新根变成原来根的颜色;
        root->color=root->lchild->color;
    }else{ 
        if(root->lchild->lchild->color!=0){
            //对调新根与原根的颜色;
            root->lchild->color=0;//原根的颜色变成红色;
            root->lchild=left_rotate(root->lchild);
            root->lchild->color=1;//新根的颜色变成黑色;
        }
        root=right_rotate(root);
        root->color=root->rchild->color;
    }
    //新根的左右字节点颜色强制变成黑色;
    root->lchild->color = root->rchild->color = 1;
    return root;
}

Node *__erase(Node *root,int key){
    if(root==NIL) return NIL;
    if(root->key > key){
        root->lchild=__erase(root->lchild,key);
    }else if(root->key < key){
        root->rchild=__erase(root->rchild,key);
    }else{
        if(root->lchild==NIL||root->rchild==NIL){
            Node *temp= root->lchild!=NIL?root->lchild:root->rchild;
            temp->color += root->color;
            free(root);
            return temp;
        }
        Node *temp=predecessor(root);
        root->key=temp->key;
        root->lchild=__erase(root->lchild,temp->key);
    }
    return erase_maintain(root);
}

Node* erase(Node *root,int key){
    root=__erase(root,key);
    root->color=1;
    return root;
}

void clear(Node *root){
    if(root==NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void print(Node *root){
    printf("(%d| %d ,%d ,%d)\n",
          root->color,
          root->key,
          root->lchild->key,
          root->rchild->key);
}

void output(Node *root){
    if(root==NIL) return ;
    print(root);
    output(root->lchild);
    output(root->rchild);
}
int main(){
    int op,val;
    Node *root=NIL;
    while(~scanf("%d%d",&op,&val)){
        switch(op){
            case 1: root=insert(root,val);break;
            case 2: root=erase(root, val); break;
        }
        output(root);
        printf("------------\n");
    }
    return 0;
}
