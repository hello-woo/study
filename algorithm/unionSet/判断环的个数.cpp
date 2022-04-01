#include<bits/stdc++.h>
/*
https://www.nowcoder.com/questionTerminal/84a34b5befab43ff9adb2615f8d1a703
*/
using namespace std;

class UnionSet{
 private :
      vector<int>parent;
      int cnt;
 public:
       UnionSet(int n):parent(n + 1),cnt(n){
           for(int i = 1 ;i <= n;i++){
               parent[i] = i;
           }
       }
       
       int Find(int x){
           if(x == parent[x]) return x;
           return parent[x] = Find(parent[x]);
            
       }
        //如何输出每个集合中的元素？？？？
        //输出与x每个集合的坐标
    //    vector<int>getNum(int x){
    //        vector<int>temp;
    //        int parent_node = Find(x);
    //        for(int i = 1 ;i <= n;i++){
    //            if(parent_node == Find(i) && i != x){
    //                temp.push_back(i);
    //            }
    //        }
    //        return temp;
    //    }
       set<int> getSet(int n){
           set<int>s;
           for(int i = 1; i <= n;i++){
               int parent_val = Find(i);
               s.insert(parent_val);
           }
           return s;
       }

       bool unionfind(int x,int y){
           int p1 = Find(x),p2 = Find(y);
           if(p1 == p2) return false;
           parent[p1] = p2;
           cnt--;
           return true;
       }
       int getCnt(){
           return cnt;
       }
};

//int father[N];

int main(){
    int n;
    cin >> n;
    map<string,int>mp;
    UnionSet s(n);
    int cnt = 1;
    int ans = 0;
    for(int i = 0 ; i < n;i++){
        string s_a,s_b;
        cin >> s_a >> s_b;
        if(!mp.count(s_a)){
            mp[s_a] = cnt++;
        }
        if(!mp.count(s_b)){
            mp[s_b] = cnt++;
        }
        //如果成环，则cnt++
        if(s.unionfind(mp[s_a],mp[s_b]) == false){
            ans++;
        }
        s.unionfind(mp[s_a],mp[s_b]);
    }
    cout << ans <<endl;
    //cout << s.getCnt() <<endl;
    return 0;
}