/*
n行m列 q次操作

n行m列的字符矩阵char board[N][M]；
每次操作将矩阵左上角(x1,y1) 至右下角(x2,y2)的字符串小写变大写，大写变小写。

输入：
2 3 2
aBc
AaD
1 1 1 2
1 2 2 3

输出：
ABC
AAd
*/

#include<bits/stdc++.h>

using namespace std;
int n,m,q;

const int N = 505;
const int M = 505;

char board[N][M];
int b[N][M];

void do_insert(int x1,int y1,int x2,int y2){
    b[x1][y1] += 1;
    b[x1][y2 + 1] -= 1;
    b[x2 + 1][y1] -= 1;
    b[x2 + 1][y2 + 1] += 1;
}

int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n;i++){
        for(int j = 1;j <= m ;j++){
            cin>> board[i][j];
        }
    }

    while(q--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1>> x2>>y2;
        do_insert(x1,y1,x2,y2);
    }

    //得到每个字符变换的次数，如果是奇数，则要变换，如果是偶数，则不用变换
    for(int i = 1; i <= n; i++){
        for(int j = 1;j <=m ;j++){
            b[i][j] = b[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j -1];
        }
    }

    for(int i = 1;i <= n ;i ++){
        for(int j = 1; j <= m;j++){
            if(b[i][j] & 1){
                if(board[i][j] >= 'a' && board[i][j] <= 'z'){
                    board[i][j] -= 32;
                }else{
                    board[i][j] += 32;
                }
            }
        }
    }

    for(int i = 1; i <= n ;i++){
        for(int j = 1 ;j <= m ;j++){
            cout <<  board[i][j];
        }
        cout << endl;
    }
    return 0;
}