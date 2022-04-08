/**
 * @file 广搜走地图.cpp
 * 
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
地图S表示start,T表示end,求从s到t的最短路径
*/

//广度优先搜索，解决地图问题，并且可以直接求出最小步数。
#include<bits/stdc++.h>

using namespace std;

const int N = 2005;
char board[N][N];

int dir[4][2] = {0,1,1,0,0,-1,-1,0};


struct node{
    int x,y,step;//坐标(x,y),到达这里需要step步
};

queue<node>que;
int n,m;

int bfs(int x,int y){
    while(!que.empty()){
        node temp = que.front();
        que.pop();

        for(int i = 0 ;i < 4;i++){
            int x0 = temp.x + dir[i][0];
            int y0 = temp.y + dir[i][1];
            
            if(x0 < 0 || x0 > n||y0 < 0 || y0 > m) continue;

            if(board[x0][y0] == 't'){
                return temp.step + 1;
            }

            if(board[x0][y0] == '.'){
                board[x0][y0] = '0';
                que.push({x0,y0,temp.step + 1});
            }
        }
    }
    return -1;
}

int main(){
    cin >>n >> m;
    int sx,sy;
    for(int i =1 ;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> board[i][j];
            if(board[i][j] == 's'){
                sx = i,sy = j;
            }
        }
    }
    que.push({sx,sy,0});
    int res = bfs(sx,sy);

    if(res == -1) cout << "No"<<endl;
    else cout << res << endl;

    return 0;
}