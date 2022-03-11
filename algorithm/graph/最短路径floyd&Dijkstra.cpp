#include<bits/stdc++.h>

using namespace std;

const int N = 110;
int mmap[N][N]; //用来存图

int INF = 0x3f3f3f3f;

//初始化邻接矩阵 ,注意下标从1开始
void init(int n){
    for(int i = 1;i <= n;i++){
        for(int j = 1 ; j <= n ;j++){
            mmap[i][j] = mmap[j][i] = i == j ? 0 :INF; //自己到自己的初始化为0,其余均为无穷大
        }
    }
}



//Floyd（邻接矩阵）
// floyd 基本流程为三层循环：
// 枚举中转点 - 枚举起点 - 枚举终点 - 松弛操作  
void floyd(int n){
    for(int p = 1; p <= n ;p++){
        for(int i = 1; i <= n ;i++){
            for(int j = 1; j <= n; j++){
                mmap[i][j] = min(mmap[i][j],mmap[i][p] + mmap[p][j]);
            }
        }
    }
}


//朴素 Dijkstra（邻接矩阵）
// dist[x] = y 代表从「源点/起点」到 x 的最短距离为 y
int dist[N];
 // 记录哪些点已经被更新过
bool vis[N];
void dijkstra(int k,int n){
    // 起始先将所有的点标记为「未更新」和「距离为正无穷」
    memset(vis,false,sizeof(vis));
    memset(dist,INF,sizeof(dist));

  // 只有起点最短距离为 0
    dist[k] = 0;

    for(int  p = 1 ;p <= n ;p++){
        // 每次找到「最短距离最小」且「未被更新」的点 t
        int t = -1;
        for(int i = 1; i <= n ;i++){
            if (!vis[i] && (t == -1 || dist[i] < dist[t])) t = i;
        }
        // 标记点 t 为已更新
        vis[t] = true;
        // 用点 t 的「最小距离」更新其他点
        for (int i = 1; i <= n; i++) {
            dist[i] = min(dist[i], dist[t] + mmap[t][i]);
        }
    }
}


int main(){
    int n ,m;//n个点，m条边
    cin >> n >> m;
    vector<vector<int>>times(m,vector<int>(3,0));
    init(n);
    for(int i = 0 ; i < m ; i++){
        int u,v,w;
        cin >> u >> v >> w;
        mmap[u][v] = w;
    }
    //floyd(n); //n为节点个数
    //求从k节点出发最短距离的最大值
    int k ;
    cin >> k;
    int ans = 0;
//dijkstra算法最短距离存在dist里面
    dijkstra(k,n);
    for(int i = 1; i <= n ;i++){
        ans = max(ans,dist[i]);
    }
//以下为floyed
#if 0 
    for(int i = 1; i <= n ;i++){
        ans = max(ans,mmap[k][i]);
    }
#endif
    ans >= INF / 2 ? -1 :ans;
    cout << ans <<endl;
}

/*
4 3
2 1 1
2 3 1
3 4 1
2
2*/