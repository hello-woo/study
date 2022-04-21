#include<bits/stdc++.h>

using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v):val(v),left(nullptr),right(nullptr){}
};

//左根右
void dfs(TreeNode *root ,vector<int>&ans){
    if(root == nullptr) return;
    if(root->left) dfs(root->left,ans);
    if(root->right) dfs(root->right,ans);
    ans.push_back(root->val);
    return;
}


vector<int> post_order(TreeNode * root){
    vector<int>ans;
    if(root == nullptr) return ans;
    dfs(root,ans);
    return ans;
}

//左右根
vector<int>sta_post_order(TreeNode *root){
    stack<TreeNode *> sta;
    vector<int>ans;
    if(root == nullptr) return ans;
    sta.push(root);
    while(!sta.empty()){
        TreeNode *temp = sta.top();
        sta.pop();
        ans.push_back(temp->val);
        if(temp->left) sta.push(temp->left);
        if(temp->right) sta.push(temp->right);

    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(5);
    root->right->left = new TreeNode(6);
    vector<int>ans = post_order(root);
    for(auto p: ans){
        cout << p << " ," ;
    }
    cout << endl;
    vector<int>sta_ans= sta_post_order(root);
    for(auto p : sta_ans){
        cout << p << " <";
    }// 5 3 2 6 4
    return 0;
}