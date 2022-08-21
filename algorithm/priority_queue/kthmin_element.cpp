/* 
给定n个长度为m的有序数组，求第K小的元素
 */

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    //重载堆的比较函数
    struct Node{
        int x,y,val;
        friend bool operator<(const Node& a,const Node &b){
            return a.val > b.val;
        }
    };
    priority_queue<Node>q;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int Row = matrix.size();
        int Col = matrix[0].size();
        for(int i = 0; i < Row;i++){
            q.push({i,0,matrix[i][0]});
        }
        //最小的在堆顶，弹出k-1个，堆顶即为第k小的
        while(--k){
            Node temp = q.top();
            q.pop();

            if(temp.y + 1 < Col){
                q.push({temp.x , temp.y + 1,matrix[temp.x][temp.y + 1]});
            }
        }
        return q.top().val;
    }
};