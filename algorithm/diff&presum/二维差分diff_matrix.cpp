/*
输入一个n行m列的整数矩阵，再输入q个操作，每个操作包含五个整数x1, y1, x2, y2, c，其中(x1, y1)和(x2, y2)表示一个子矩阵的左上角坐标和右下角坐标。
每个操作都要将选中的子矩阵中的每个元素的值加上c。
请你将进行完所有操作后的矩阵输出。

输入格式
第一行包含整数n,m,q。
接下来n行，每行包含m个整数，表示整数矩阵。
接下来q行，每行包含5个整数x1, y1, x2, y2, c，表示一个操作。

输出格式
共 n 行，每行 m 个整数，表示所有操作进行完毕后的最终矩阵。
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 500;
const int M = 500;

int a[N][N]; //原数组
int b[N][N];//差分数组

int n ,m ,q;

void do_insert(int x1,int y1,int x2,int y2,int c){
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main(){
    cin >> n >> m >> q;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= m ;j ++){
            cin >> a[i][j];
            do_insert(i,j,i,j,a[i][j]);//初始化差分矩阵
        }
    }

    //得到操作之后的差分数组
    while(q--){
        int x1,y1,x2,y2,c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        do_insert(x1,y1,x2,y2,c); 
    }

    //求前缀和得到操作之后的矩阵
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= m ;j++){
            b[i][j] = b[i - 1][j] + b[i][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    }

    //打印矩阵
    for(int i = 1 ;i <= n;i++){
        for(int j = 1; j <= m ;j++){
            j != 1 && cout << " ";
            cout << b[i][j];
        }
        cout << endl;
    }
    return 0;
}