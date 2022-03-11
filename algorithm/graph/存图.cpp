#include<bits/stdc++.h>

using namespace  std;

//邻接矩阵
//vector<vector<int>>w(n,vector<int>(n,0));

//a到b的距离(权重为c)
// void add1(int a,int b,int c){
//     w[a][b] = c;
// }

//邻接表(常用、又叫链式前向星存图)
const int MAX_M = 1e5;
const int n = 1000;

struct Edge{
    int to; // 到下一个节点
    int w;  //距离或者权重为多少
    int next; // 以某个节点的上一条边的编号
}Edges[MAX_M];

int idx,first[MAX_M];//idx为边的编号，first为某个节点的最后一条边的编号


//节点u到节点v的距离(权重为w)
void add(int u,int v,int w){
    Edges[++idx].to = v; //注意编号从1开始编号，因为初始化都是0,下面遍历的时候i ！=0
    Edges[idx].w = w;
    Edges[idx].next = first[u]; // 以u为终点的上一条边的编号
    first[u] = idx;
}

//遍历以u为起点的边
void visit(int u){
    for(int i = first[u]; i != 0 ; i = Edges[i].next){
        printf("%d--%d:%d\n",u,Edges[i].to,Edges[i].w);
    }
}

int main(){
    int m ,n;//m 个点，n条边
    cin >> m >>n ;
    for(int i = 0 ;i < n ;i++){
        int u,v,w;
        cin >> u >> v >> w;
        add(u,v,w);
    }
    visit(1);
    return 0;
}

/*
5 7
1 2 6
1 4 8
1 5 9
1 3 7
2 4 4
3 5 5
4 5 2
1--3:7
1--5:9
1--4:8
1--2:6
*/