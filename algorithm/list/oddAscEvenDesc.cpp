
#include<bits/stdc++.h>

using namespace std;

/*
对于一个奇数上升，偶数下降的链表重新排序
(1)首先拆分奇数和偶数链表
(2)翻转偶数链表
(3)合并两个有序链表
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode *reverselist(ListNode *head){
    if(head == nullptr || head->next == nullptr) return head;
    ListNode *nextNode = head->next;
    ListNode *start = reverselist(nextNode);
    nextNode->next = head;
    head->next = nullptr;
    return start;
}

ListNode* mergeTwolist(ListNode *l1,ListNode *l2){
    if(l1 == nullptr && l2 == nullptr) return nullptr;
    if(l1 == nullptr || l2 == nullptr) return l1 ? l1 :l2;
    ListNode *dummpy = new ListNode(-1);
    ListNode *cur = dummpy;
    while(l1 && l2){
        if(l1->val < l2->val){
            cur->next = l1;
            l1 = l1->next;
        }else{
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1? l1:l2;
    return dummpy->next;
}

ListNode *reorderList(ListNode *head){
    if(head == nullptr ||head -> next == nullptr) return head;
    ListNode *dummpy = new ListNode(-1);
    dummpy->next = head;
    ListNode *oddHead = dummpy;
    ListNode *evenHead = new ListNode(-1);
    ListNode *cur1 = oddHead;
    ListNode *cur2 = evenHead;
    ListNode *cur = head;
    int cnt = 1;
    while(cur){
        if(cnt & 1){
            cur1->next = cur;
            cur1 = cur1->next;
        }else{
            cur2 ->next = cur;
            cur2 = cur2->next;
        }
        cur = cur ->next;
        cnt++;
    }
    cur1->next = nullptr;
    cur2->next = nullptr;
    // cur1 = oddHead;
    // cur2 = evenHead;
    // while(cur1){
    //     cout << cur1->val<<endl;
    //     cur1 = cur1 ->next;
    // }
    // while(cur2){
    //     cout << cur2->val<<endl;
    //     cur2 = cur2 ->next;
    // }
    //将偶数链表反转
    ListNode *reverseEvenHead = reverselist(evenHead->next);
    // cur2 = reverseEvenHead;
    // cout<< " even reversed!"<<endl;
    // while(cur2){
    //     cout << cur2->val<<",";
    //     cur2 = cur2 ->next;
    // }
    //cout <<endl;
    dummpy->next = mergeTwolist(oddHead->next,reverseEvenHead);
    return dummpy->next;
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