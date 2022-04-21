#include<bits/stdc++.h>

using namespace std;

/*
l1->l2->l3->l4....->ln-1->ln;
reorder-
l1->ln->l2->ln-1.....
1-3-5-7-8-6-4-2
1-2-3-4-5-6-7-8

思路：
(1)找到中间节点
(2)反转中间之后面的节点
(3)合并两个序列的链表
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode *getMiddle(ListNode *head){
    if(head == nullptr || head->next == nullptr) return head;
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast ->next->next;
    }
    return slow;
}

ListNode *reverselist(ListNode *head){
    if(head == nullptr ||head ->next == nullptr) return head;
    ListNode *nextNode = head->next;
    ListNode *start = reverselist(nextNode);
    nextNode->next = head;
    head->next = nullptr;
    return start;
}


//这里mergelist没有顺序
ListNode *mergeTwolist(ListNode *l1,ListNode *l2){
    if(l1 == nullptr && l2 == nullptr) return nullptr;
    if(l1 == nullptr || l2 == nullptr) return l1 ? l1: l2;
    ListNode *dummpy = new ListNode(-1);
    ListNode *cur = dummpy;
    int cnt = 1; // 奇数取l1,偶数取l2中的
    while(l1 && l2){
        if(cnt & 1){
            cur->next = l1;
            l1 = l1->next;
        }else{
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
        cnt++;
    }
    cur ->next = l1 ?l1:l2;
    return dummpy->next;
}

ListNode *reorderList(ListNode *head){
    if(head == nullptr) return nullptr;
    ListNode *middle = getMiddle(head);
    ListNode *middleNode = middle->next;
    middle->next = nullptr;
    middleNode = reverselist(middleNode);
    ListNode *cur1 = head;
    ListNode *cur2 =middleNode;
    while(cur1){
        cout<< cur1->val<<",";
        cur1 = cur1->next;
    }
    cout << endl;
    while(cur2){
        cout << cur2->val << ",";
        cur2 = cur2->next;
    }
    cout << endl;
    ListNode* mergeNode = mergeTwolist(head,middleNode);
    return mergeNode;
}


int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(8);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(6);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(2);

    /*
    1-8-3-6-5-4-7-2
    1-2-8-7-3-4-6-5
    */

    ListNode *cur = head;
    while(cur){
        cout << cur->val<<",";
        cur = cur->next;
    }
    cout <<endl;
    cout << "reversed!:------"<<endl;
    ListNode *newStart = reorderList(head);
    cur = newStart;
    while(cur){
        cout << cur->val<<",";
        cur = cur->next;
    }
    return 0;
}

/*
1,8,3,6,5,4,7,2,
reversed!:------
1,8,3,6,5,
2,7,4,
1,2,8,7,3,4,6,5,% 
*/