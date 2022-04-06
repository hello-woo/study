#include<bits/stdc++.h>

/*
 1 2 3 4

*/

using namespace std;

const int N = 100010;
int a[N]; //原始数组；
int b[N]; //差分数组；


/**
 * @brief 
 * 计算差分数组【l,r]插入数值val
 * @param l 左边界
 * @param r 有边界
 * @param val 插入的值
 */
void do_insert(int l,int r,int val){
    b[l] += val;
    b[r + 1] -= val;
}

int main(){
    int n ,m;
    cin >> n >>m; //长度为n的数组，m次操作
    
    for(int i = 1; i <= n;i++){
        cin >> a[i];
        b[i] = a[i] - a[i - 1]; //初始化差分数组，或者do_insert(i,i,a[i]);
    }

    while(m--){
        int l ,r ,c; //每次操作在[l,r]上加上c;
        cin >> l >> r >> c; 
        do_insert(l,r,c);
    }

    for(int i = 1; i <= n;i++){
        //a[i] = a[i - 1] + b[i]; //差分数组求前缀和，计算出操作之后的数组。
        //printf("%d,",a[i]);

        b[i] += b[i - 1];
        printf("%d,",b[i]);
 
    }
    return 0;
}