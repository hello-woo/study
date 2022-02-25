/*************************************************************************
	> File Name: LRU.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 09 Mar 2021 08:42:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct Node{
    int val;
    Node *next;
}Node;

class LRU{
private:
    Node *head;
    int count;
    int max_size;
public:
    LRU(int size){
        head=new Node();
        head->next=NULL;
        count=0;
        max_size=size;
    }
    ~LRU(){
        while(head!=NULL){
            Node *cur=head;
            head=head->next;
            delete cur;
        }
    }
    bool IsFull(){
        return count==max_size;
    }
    void push(int value){
        Node *p=new Node ;
        Node *node=head;
        //判断链表是否存在该值：
        bool flag=false;
        while(node->next!=NULL){
            if(node->next->val==value){
                node->next=node->next->next;
                count--;
                flag=true;
            }
            //特殊处理，当元素为最后一个元素；
            if(node->next==NULL) break;
            node=node->next;
        }
        if(IsFull()){
            //不存在该值，删除联想
            if(!flag){
                head=head->next;
                count--;
            }
        }
        p->val=value;
        p->next=NULL;
        node->next=p;
        count++;
    }
    void print(){
        Node *node=head->next;
        while(node){
            cout<<node->val<<" ";
            node=node->next;
        }
        cout<<endl;
    }
};


int main(){
    LRU lru=LRU(3);
    lru.push(2);
    lru.push(3);
    lru.push(2);
    cout<<"当容器没满时,插入存在的元素,结果为:"; 
    lru.print(); 
    lru.push(4);
    cout<<"当容器已满时,结果为:"; 
    lru.print();
    lru.push(5);
    cout<<"当容器已满时,插入不存在的元素,结果为:"; 
    lru.print();
    lru.push(3);
    lru.push(5);
    cout<<"当容器已满时,插入存在的元素,结果为:"; 
    lru.print();
    return 0;
}
