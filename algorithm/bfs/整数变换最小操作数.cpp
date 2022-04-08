/**
 * @file 整数变换最小操作数.cpp
 * 给定两个-100到100的整数x和y,对x只能进行加1，减1，乘2操作，问最少对x进行几次操作能得到y？
例如：
a=3,b=11: 可以通过 3 * 2 * 2 - 1 ，3次操作得到11；
a=5,b=8：可以通过(5-1)*2，2次操作得到8；

输入描述:
输入以英文逗号分隔的两个数字，数字均在32位整数范围内。
输出描述:
输出一个数字
输入：
3,11
输出：
3
————————————————
版权声明：本文为CSDN博主「Ypopstar」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/Ypopstar/article/details/105149078
 * @author your name (you@domain.com)
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
    int x ,step;//数值，到这个数值的操作数
};

const int N  = 1e7+ 5;
int vis[N];

int getNum(int x,int y){
    if(x == y) return 0;
    queue<node>q;
    q.push({x,0});
    vis[x] = 1;
    while(!q.empty()){
        node temp = q.front();
        q.pop();

        //可选的操作数
        for(int i = 1 ;i <= 3;i++){
            node nextNode;
            if(i == 1) {
                nextNode.x = temp.x - 1;
            }else if( i == 2){
                nextNode.x= temp.x + 1;
            }else if(i == 3){
                nextNode.x = temp.x * 2;
            }

            if(nextNode.x < 0 ||nextNode.x > N ) continue;

            if(!vis[nextNode.x]){
                vis[nextNode.x] = 1;
                nextNode.step = temp.step + 1;
                q.push(nextNode);
            }

            if(nextNode.x == y) return temp.step + 1;
        }
    }
    return -1;
}

int main(){
    int x,y;
    cin >> x >> y;
    int res = getNum(x,y);
    cout << res << endl;
    return 0;
}