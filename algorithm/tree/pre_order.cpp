#include<bits/stdc++.h>

using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v):val(v),left(nullptr),right(nullptr){}
};

void dfs(TreeNode *root ,vector<int>&ans){
    if(root == nullptr) return;
    ans.push_back(root->val);
    if(root->left) dfs(root->left,ans);
    if(root->right) dfs(root->right,ans);
    return;
}

//根左右
vector<int> pre_order(TreeNode * root){
    vector<int>ans;
    if(root == nullptr) return ans;
    dfs(root,ans);
    return ans;
}

vector<int>sta_pre_order(TreeNode *root){
    stack<TreeNode *> sta;
    vector<int>ans;
    if(root == nullptr) return ans;
    sta.push(root);
    while(!sta.empty()){
        TreeNode *temp = sta.top();
        sta.pop();
        ans.push_back(temp->val);
        if(temp->right) sta.push(temp->right);
        if(temp->left) sta.push(temp->left);
    }
    return ans;
}

int main(){
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(5);
    root->right->left = new TreeNode(6);
    vector<int>ans = pre_order(root);
    for(auto p: ans){
        cout << p << " ," ;
    }
    cout << endl;
    vector<int>sta_ans= sta_pre_order(root);
    for(auto p : sta_ans){
        cout << p << " <";
    }
    return 0;
}