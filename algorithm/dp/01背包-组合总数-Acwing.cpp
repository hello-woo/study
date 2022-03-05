/*给定一个有n个正整数的数组A和一个整数sum,求选择数组A中部分数字和为sum的方案数。
当两种选取方案有一个数字的下标不一样,我们就认为是不同的组成方案。*/

/*解题思路：
选一个，01背包问题，恰好等于sum，组合总数
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 10005;
int nums[N];

int getNum(int *nums,int n,int sum){
    vector<int>dp(sum + 1,0);
    dp[0] = 1;
    for(int i = 0;i < n;i++){
        for(int j = sum ;j >= nums[i];j--){
            dp[j] += dp[j - nums[i]];
        }
    }
    return dp[sum];
}

int main(){
    int n ,sum;
    cin >> n >> sum;
    for(int i = 0 ;i < n ;i++){
        int temp ;
        cin >> temp;
        nums[i] = temp;
    }
    int res = getNum(nums,n,sum);
    cout << res <<endl;
    
    return 0;
}