/**
 * @file 
 * 对于坐标(x,y),只有两种操作，+1，或者 *2 
 * (1) +1  (x,y) ---> (x+ 1,y + 1);
 * (2) *2  (x,y) ---> (x* 2,y *2);
 * 问(x1,y1)到(x2,y2)的最少操作次数
 * 
 * @brief 
 * @version 0.1
 * @date 2022-04-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>

using namespace std;

struct node{
    int x,y,step;//数值，到这个数值的操作数
};

const int N  = 20003;
int vis[N][N];

int getNum(int x1,int y1,int x2,int y2){
    if(x1 == x2 && y1 == y2) return 0;

    queue<node>q;
    q.push({x1,y1,0});
    vis[x1][y1] = 1;

    while(!q.empty()){
        node temp = q.front();
        q.pop();

        //可选的操作数
        for(int i = 1 ;i <= 2;i++){
            node nextNode;
            if(i == 1) {
                nextNode.x = temp.x + 1;
                nextNode.y = temp.y + 1;
            }else if( i == 2){
                nextNode.x = temp.x * 2;
                nextNode.y = temp.y * 2;
            }

            if(nextNode.x < 0 || nextNode.x > N || nextNode.y < 0 || nextNode.y > N ) continue;

            if(!vis[nextNode.x][nextNode.y]){
                vis[nextNode.x][nextNode.y] = 1;
                nextNode.step = temp.step + 1;
                q.push(nextNode);
            }

            if(nextNode.x == x2 && nextNode.y == y2) return temp.step + 1;
        }
    }
    return -1;
}

int main(){
    int x1,y1,x2,y2;
    cin >> x1 >> y1>>x2>>y2;
    int res = getNum(x1,y1,x2,y2);
    cout << res << endl;
    return 0;
}