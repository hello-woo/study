#include<bits/stdc++.h>

using namespace std;

/*
每个数都有二进制表示，即所有数都可以表示为x个不同的2的幂之和。
 
6(10) = 110(2)

s[i]:表示第1个数到第i个数的和

s[6] = c[4] + c[6] = c[100] + c[110] = 
s[5] = c[4] + c[5] = c[100] + c[101]
*/

//树状数组
/*
单点修改，查询前缀和

arr: 0000000 

*/
class BIT {
private:
    int n; // 容量为n
    vector<int> tree;

public:
    BIT(int _n): n(_n), tree(_n + 1) {}

    static constexpr int lowbit(int x) {
        return x & (-x);
    }
    
#if 0
    //给第x个数加1
    void update(int x) {
        while (x <= n) {
            ++tree[x];
            x += lowbit(x);
        }
    }
#endif


    // 单点更新，将i下标的元素加上delta
    void update(int i ,int delta){
        while(i <= n){
            tree[i] += delta;
            i += lowbit(i);
        }
    }

    //查询前缀和[1,i]
    int query(int x) const {
        int ans = 0;
        while (x > 0) {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    } 
};

/*单点修改，区间查询，第3个数加5
1 2 3 4 5 6
2 4 7 5 4 1 ----> 2 4 12 5 4 1 

presum : 2 6 18 23 27 28

查第2为到第4位的和 query(4) - query(1) = 23 - 2 = 21
*/
int main(){
    int  n;
    cin >> n;
    vector<int>nums(n + 1,0); //注意下标从1开始
    for(int i = 1 ; i <= n ;i++){
        int temp ;
        cin >> temp;
        nums[i] = temp;
    }
    BIT bit(n);
    for(int i = 1 ; i <= n ;i++){
        bit.update(i,nums[i]);
    }
    int x, val;
    cin >> x >> val; //第x位上加上val之后的数据
    bit.update(x,val);

    for(int i = 1 ; i <= n ;i++){
        cout << nums[i] << " ";
    }

    cout << endl;

    for(int i = 1; i <= n ;i++){
        cout << bit.query(i) << endl;
    }
    int preSum = bit.query(4) - bit.query(1); //2到4的和
    cout << preSum <<endl;

    return 0;
}

/* 运行示例
6
2 4 5 7 4 1
3 5
2 4 5 7 4 1 
2
6
16
23
27
28
21
*/