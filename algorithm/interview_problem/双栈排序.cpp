#include<bits/stdc++.h>
/* 5 1 3 7 2  -----------》1 2 3 5 7*/

using namespace std;

stack<int> stack_sort(stack<int>& sta){
    stack<int>temp;
    while(!sta.empty()){
        int t = sta.top();
        sta.pop();
        while(!temp.empty() && t > temp.top()){
            int val = temp.top();
            temp.pop();
            sta.push(val);
        }
        temp.push(t);
    }
    return temp;
}

int main(){
    stack<int>sta;
    sta.push(5);
    sta.push(1);
    sta.push(3);
    sta.push(7);
    sta.push(2);
    stack<int>s;
    s = stack_sort(sta);
    while(!s.empty()){
        cout << s.top()<<endl;
        s.pop();
    }
    return 0;
}

// //最小的先弹栈
// stack<int> stack_sort(stack<int>& sta){
//     stack<int>temp;
//     while(!sta.empty()){
//         int topval = sta.top();
//         sta.pop();
//         while(!temp.empty() && topval > temp.top()){
//             int t = temp.top();
//             temp.pop();
//             sta.push(t);
//         }
//         temp.push(topval);
//     }
//     return temp;
// }

// int main(){
//     stack<int>ori;
//     ori.push(4);
//     ori.push(5);
//     ori.push(2);
//     ori.push(3);
//     ori.push(1);
//     stack<int>res = stack_sort(ori);
//     while(!res.empty()){
//         cout << res.top() << " ,";
//         res.pop();
//     }
//     return 0;
// }