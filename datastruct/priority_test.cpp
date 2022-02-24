#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int x ,y;
    int val;
    #if 0
    friend bool operator<(const Node& l1,const Node& l2){
        return l1.val > l2.val;
    }
    #endif
    bool operator<(const Node& l) const{
        return val > l.val;
    }
};

priority_queue<Node>pri;
vector<int>help(vector<vector<int>> &matrix,int k){
    vector<int>res;
    for(int i = 0 ;i < matrix.size();i++){
        pri.push(Node{i,0,matrix[i][0]});
    }
    while(!pri.empty()){
        auto temp = pri.top();
        pri.pop();
        res.push_back(temp.val);
        if(res.size() == k) break;
        if(temp.y + 1 < matrix[0].size()){
            pri.push(Node{temp.x ,temp.y + 1,matrix[temp.x][temp.y + 1]});
        }
    }
    return res;
}

int main(){
    int n ,m ,k;
    cin >> n >> m;
    cin >> k;
    vector<vector<int>>matrix(n,vector<int>(m ,0));
    for(int i = 0 ;i < n; i++){
        for(int j = 0; j < m ;j++){
            int temp;
            cin >> temp;
            matrix[i][j] = temp;
        }
    }
    auto res = help(matrix,k);
    for(auto &v : res){
        cout << v << " ";
    }
    return 0;
}