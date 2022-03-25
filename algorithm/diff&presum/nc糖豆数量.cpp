/*
https://ac.nowcoder.com/acm/contest/5158/D
链接：https://ac.nowcoder.com/acm/contest/5158/D
来源：牛客网

牛妹为了打比赛经常不吃饭，但是牛妹非常喜欢吃豆子，她经常会吃很多很多的豆子，所以牛妹不会感觉到饿， 自然就不想吃饭了。
现在牛妹有一个 n∗mn∗m 个格子的棋盘.左下角的格子坐标为 (1, 1)(1,1)， 右上角的格子坐标为 (n,m)(n,m).棋盘的每个格子都能放任意个豆子.
这时牛可乐带着一袋豆子走了过来， 打算跟牛妹分享这些豆子， 但是牛可乐并不想就这么简单的让牛妹吃到豆子， 所以牛可乐给牛妹出了一个难题.
现在牛可乐有 kk 次操作，每次操作给出四个数字 x1,y1,x2,y2x1,y1,x2,y2 : 表示牛可乐会将所有满足 x1\leq x\leq x2,y1\leq y \leq y2x1≤x≤x2,y1≤y≤y2 这两个条件的位置上放一个豆子。
牛可乐放完豆子后给出了 qq 次询问， 每次询问给出四个数字 x1,y1,x2,y2x1,y1,x2,y2 : 表示询问所有满足 x1\leq x\leq x2,y1\leq y \leq y2x1≤x≤x2,y1≤y≤y2 这两个条件的位置上中总共有多少个豆子.
这个问题可难住牛妹了， 牛妹想要吃到豆子就必须答对牛可乐的所有询问。


输入描述:
输入一行四个数字 n,m,k,qn,m,k,q

n,mn,m 表示棋盘的大小.有 kk 次操作和 qq 次询问

下面 kk 行,每行四个数字 x1,y1,x2,y2x1,y1,x2,y2

表示牛可乐会将所有满足 x1\leq x\leq x2,y1\leq y \leq y2x1≤x≤x2,y1≤y≤y2 这两个条件的位置上放一个豆子。

下面 qq 行,每行四个数字 x1,y1,x2,y2x1,y1,x2,y2

表示询问所有满足 x1\leq x\leq x2,y1\leq y \leq y2x1≤x≤x2,y1≤y≤y2 这两个条件的位置上中总共有多少个豆子。
输出描述:
每次询问，输出一行一个数字表示答案。
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2005;
const int M = 2005;

ll b[N][M];//差分数组
ll ans = 0;
ll n,m,k,q;

//二维差分数组,差分数组
void insert_num(int x1,int y1,int x2,int y2){
    b[x1][y1] += 1;
    b[x1][y2 + 1] -= 1;
    b[x2 + 1][y1] -= 1;
    b[x2 + 1][y2 + 1] += 1;
}

//真实个数，表示每个坐标对应的豆数
void getRealVal(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ;j++){
            b[i][j] = b[i - 1][j] + b[i][j - 1] + b[i][j] - b[i - 1][j - 1];
        }
    }
}

int main(){
    cin >> n >> m >> k >> q;
    while(k--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >>  x2 >> y2;
        insert_num(x1,y1,x2,y2);
    }
    //求得到真实的矩阵。
    getRealVal();
    
    //得到前缀和数组
    getRealVal();
    
    //求(x1,y1) 到(x2,y2)矩阵的和；
    while(q--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        //求(x1,y1)到(x2,y2)的所有数字的和
        ans = b[x2][y2] -b[x1 - 1][y2] - b[x2][y1 - 1] + b[x1 - 1][y1 - 1];
        cout << ans << endl;
    }
    return 0;
}