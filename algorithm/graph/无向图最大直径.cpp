#include<bits/stdc++.h>

//无向无环图，一个图 n个点，m条边，求最大直径；
/*4 3
[1,2],[2,3],[2,4]

7 7
1 2
2 3
2 4
4 5
3 6
6 7
5 7

*/
using namespace std;


//最多15个点
const int MAXN = 20;
vector<int>edge[MAXN];//edge[i]：表示以i为起点的，终点的集合

int dis[MAXN];
queue<int>que;


//从点x开始，一共有n个点
void bfs(int x,int n){
    while(!que.empty()) que.pop();
    memset(dis,-1,sizeof(dis));
    que.push(x);dis[x] = 0;// 这里一定要初始化为0
    while(!que.empty()){
        int now = que.front();que.pop();
        //遍历点now的所有相连的点
        for(int v : edge[now]){
            //如果这个点没访问过 +1；
            if(dis[v] == -1){
                dis[v] = dis[now] + 1;
                que.push(v);
            }
        }
    }
}

int main(){
    int n,m;//n个点，m条边
    //edges[from,to];
    vector<vector<int>>edges(m,vector<int>(2,0));

    cin >> n >> m;

    for(int i = 0; i < m;i++){
        for(int j = 0 ; j < 2 ;j++){
            int temp;
            cin >> temp;
            edges[i][j] = temp;
        }
    }

    for(int i = 0 ;i < m;i++){
        int a = edges[i][0] - 1;
        int b = edges[i][1] - 1;
        edge[a].push_back(b);
        edge[b].push_back(a); 
    }

    int root = 0;//随机找一个点0，开始bfs，找到最远距离；
    bfs(root,n);

    int mx = root;

    for(int i = 0;i < n;i++){
        if(dis[i] > dis[mx]) mx= i;
    }

    cout << " ---- mx--- :" <<mx << "," << dis[mx] <<  endl;
    //然后从最远点开始再一次bfs
    bfs(mx,n);

    for(int i = 0 ;i < n ;i++){
        if(dis[i] >=0 && dis[i] >dis[mx]) mx = i;
    }

    cout << "mx: "<<mx <<" maxDistance :" << dis[mx] <<endl; 
    return 0;
}