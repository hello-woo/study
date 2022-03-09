#include<bits/stdc++.h>
/*
线段树:
query():[L,R]区间求和
update()：更新单个数字

前缀和：
query():O(1)
update():O(n)

线段树
query():O(logN)
update():O(logN)

*/

using namespace std;

#define MAX_LEN 1000


//arr : left , right ,start ,end;
//node : left_node .right_node
void build_tree(int *arr,int *tree,int node,int start,int end){
    if(start == end){
        tree[node] = arr[start];
        return ;
    }
    int mid = start + (end - start) /2 ;
    int left_node  = 2 * node + 1;
    int right_node = 2 * node + 2;
    build_tree(arr,tree,left_node,start,mid);
    build_tree(arr,tree,right_node,mid + 1,end);

    tree[node] = tree[left_node] + tree[right_node];
}

void update_tree(int* arr,int* tree,int node ,int start,int end ,int idx,int val){
    if(start == end){
        arr[idx] = val;
        tree[node] = val;
        return ;
    }
    int left_node =  2 * node + 1;
    int right_node = 2 * node + 2;

    int mid = start + (end - start) / 2;

    if(idx >= start && idx <= mid){
        update_tree(arr,tree,left_node,start,mid ,idx,val);
    }else{
        update_tree(arr,tree,right_node,mid + 1, end,idx,val);
    }
    
    tree[node] = tree[left_node] + tree[right_node];

}

int query_tree(int* arr,int* tree,int node ,int start,int end,int left ,int right){
    cout << "start :" << start << " end : "<<end <<endl; 
    if(right < start || left > end){
        return 0;
    }
//这里递归出口有重复计算
    else if(start == end){
        return tree[node];
//如果递归过程中[start,end] 是[left,right]的一个子集，这时直接返回里面的数据即可
    }else if(left <= start && end <= right){
        return tree[node];
    }

    int left_node =  2 * node + 1;
    int right_node = 2 * node + 2;

    int mid = start + (end - start) / 2;
    int left_sum = query_tree(arr,tree,left_node,start,mid,left,right);
    int right_sum = query_tree(arr,tree,right_node,mid + 1,end,left,right);

    return left_sum + right_sum;
}

int main(){
    int arr[] = {1,3,5,7,9,11};
    int len  = sizeof(arr) / sizeof(int);
    int tree[MAX_LEN] = {0};

    build_tree(arr,tree,0,0,len - 1);
    for(int i = 0 ; i< 15 ;i++){
        printf("tree[%d] : %d\n",i,tree[i]);
    }
    cout << endl;
    update_tree(arr,tree,0,0,len - 1, 4,6);
    for(int i = 0 ; i< 15 ;i++){
        printf("tree[%d] : %d\n",i,tree[i]);
    }
    
    int res = query_tree(arr,tree,0,0,len - 1,2,5);
    cout << res<< endl;
    return 0;
}