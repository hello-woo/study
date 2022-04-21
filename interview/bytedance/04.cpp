#include<bits/stdc++.h>

using namespace std;

bool vis[15];

const int M =505;
string names[M];

struct Node{
    char x[3];
    int val;
};

bool cmp(Node&a,Node&b){
    return a.val > b.val;
}

int main(){
    string temp;
    vector<Node>v;
    int cnt = 0;
    while(cin >> temp){
        names[cnt++] = temp;
    }
    for(int i = 0 ;i < cnt ;i++){
        unordered_set<char>s;
        Node temp;
        int j = 0;
        for(auto c : names[i]){
            if(!s.count(c)){
                temp.x[j++] = c;
                s.insert(c);
            }
        }
        temp.val = s.size();
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),cmp);
    int ans = 0;
    // for(auto p : v){
    //     cout << p.val  << "," <<p.x[0]<<endl;
    // }
    for(int i = 0 ; i < 10;i++){
        if()
    }

    return 0;
}