#include<bits/stdc++.h>

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

int main(){
    int n,m;
    cin >> n >> m;
    UnionSet s(n);
    for(int i = 0 ;i < m;i++){
        int x,y;
        cin >> x >> y;
        s.unionfind(x,y);
    }
    int cnt = s.getCnt();

    cout << cnt <<endl;
    set<int>anSet = s.getSet(n);
    vector<vector<int>>res;
    for(auto p : anSet){
        vector<int>ans;
        for(int i = 1 ;i <= n;i++){
            if(s.Find(i) == p){
                ans.push_back(i);
            }
        }
        res.push_back(ans);
    }
    sort(res.begin(),res.end());
    for(auto p : res){
        for(auto num : p){
            cout << num << " ";
        }
        cout <<endl;
    }
    return 0;
}