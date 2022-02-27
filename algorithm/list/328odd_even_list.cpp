#include<bits/stdc++.h>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* oddEvenList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* dummpy1 = new ListNode(-1);
    ListNode *cur1 = dummpy1;
    ListNode *dummpy2 = new ListNode(-1);
    ListNode *cur2 = dummpy2;
    ListNode *cur = head;
    int cnt = 1;
    while(cur){
        if(cnt & 1){
            cur1->next = cur;
            cur1 = cur1->next;
        }else{
            cur2->next = cur;
            cur2 = cur2->next;
        }
        cnt++;
        cur = cur->next;
    }
    cur2->next = nullptr;
    cur1->next = dummpy2->next;
    return dummpy1->next;
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
    1-3-5-7-8-6-4-2
    */

    ListNode *cur = head;
    while(cur){
        cout << cur->val<<",";
        cur = cur->next;
    }
    cout <<endl;
    cout << "reversed!:------"<<endl;
    ListNode *newStart = oddEvenList(head);
    cur = newStart;
    while(cur){
        cout << cur->val<<",";
        cur = cur->next;
    }
    return 0;
}

/*1,8,3,6,5,4,7,2,
reversed!:------
1,3,5,7,8,6,4,2,%  

*/