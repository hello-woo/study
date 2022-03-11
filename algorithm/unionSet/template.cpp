    class UnionFind
    {
        vector<int> parent; // 并查集数组
        int count = 0; //并查集连通域个数
    public:
        UnionFind(int n) : parent(n)
        {
            count = n;
            for (int i = 0; i < n; ++i)
                parent[i] = i;
        }
        
        int Find(int idx)
        {
            if (idx == parent[idx]) return idx;
            return parent[idx] = Find(parent[idx]);
        }

        bool Union(int idx1, int idx2)
        {
            int p1 = Find(idx1), p2 = Find(idx2);
            if (p1 == p2) return false;
            parent[p1] = p2;
            count--;
            return true;
        }

        //得到最大的连通域中元素个数
        int GetMax()
        {
            vector<int> cnt(parent.size(), 0);
            for (int i = 0; i < parent.size(); ++i)
                ++cnt[Find(i)];
            return *max_element(cnt.begin(), cnt.end());
        }

        bool isConnnected(int x,int y){
            return Find(x) == Find(y);
        }

        int getCount(){
            return count;
        }
    };