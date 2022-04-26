#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v),left(nullptr) ,right(nullptr){}
};

TreeNode* buildTree(vector<int>& nums){
    vector<TreeNode *>vecTree(nums.size(),nullptr);
    TreeNode* root = nullptr;
    for(int i = 0 ;i < nums.size();i++){
        TreeNode *node = nullptr;
        if(nums[i] != -1) node = new TreeNode(nums[i]);
        vecTree[i] = node;
        if(i == 0) root = node;
    }

    for(int i = 0 ;i * 2 + 2 < nums.size();i++){
        if(vecTree[i] != nullptr){
            vecTree[i]->left  = vecTree[i * 2 + 1];
            vecTree[i]->right = vecTree[i * 2 + 2];
        }
    }
    return root;
}

void bfs(TreeNode *root){
    queue<TreeNode*>que;
    if(root != nullptr) que.push(root);
    vector<vector<int>>ans;
    while(!que.empty()){
        int sz= que.size();
        vector<int>path;
        while(sz--){
            TreeNode *temp = que.front();
            que.pop();
            if(temp != nullptr) {
                path.push_back(temp->val);
                que.push(temp->left);
                que.push(temp->right);
            }else {
                path.push_back(-1);
            }
        }
        ans.push_back(path);
    }

    for(auto p : ans){
        for(auto num : p){
            cout <<num<< ",";
        }
        cout <<endl;
    }
}

int main(){
    vector<int>nums={1,2,3,4,-1,5,6,7,-1};
    TreeNode *root = buildTree(nums);
    bfs(root);
    
    return 0;
}