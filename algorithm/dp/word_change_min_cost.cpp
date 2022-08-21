/* 
给定两个字符串str1和str2，
再给定三个整数ic，dc，rc，分别代表插入、删除、替换一个字符的代价，
返回将str1编辑成str2的最小代价。

[input]
str1=“abc” str2=“adc”
ic=5 dc=3 rc=2

[output]
2
 */

#include<bits/stdc++.h>

using namespace std;

int main(){
    string str1,str2;
    cin >> str1 >> str2;
    int ic,dc,rc;
    cin >> ic >> dc >> rc;
    int n = str1.size(), m = str2.size();

    //dp[i][j];将a[0:i - 1]编辑为b[0:j - 1]相同的最小代价
    vector<vector<int>>dp(n + 1, vector<int>(m + 1,0));
    //dp初始化
    //dp[i][0]:即把str1[0~i-1]编辑为空串的代价,即将i个字符全部删除即dp[i][0] = i*c1

    for(int i = 1; i <= n;i++){
        dp[i][0] = i * dc;
    }

    //dp[0][j]:即把一个空串编辑乘str2[0~j-1]的代价则即将j个字符全部插入即dp[0][j] = j*c0;
    for(int j = 1 ;j <= m;j++){
        dp[0][j] = j * ic;
    }
/* 
    dp[i][j]:分四种情况：
    1) 先把str1[0~i-1]编辑成str1[0~i-2],在把str1[0~i-2]编辑成str2[0~j-1]
        dp[i][j] = dp[i-1][j] + dc;
    2) 先把str1[0~i-1]编辑成str2[0~j-2],在把str2[0~j-2]编辑成str2[0~j-1]
        dp[i][j] = dp[i][j-1] + ic;
    3) 如果str1[i-1] != str2[j-1],则可以先将str1[0~i-2]编辑成str2[0~j-2],然后进行替换
        dp[i][j] = dp[i-1][j-1] + rc;
    4) 如果str1[i-1] == str2[j-1],则直接将str1[0~i-2]编辑成str2[0~j-2]
        dp[i][j] = dp[i-1][j-1]
    从以上情况中选择代价最小的一种情况
*/
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= m ;j++){
            if(str1[i - 1]== str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                //删除str1元素 aaad aaa
                int cost1 = dp[i - 1][j] + dc;
                //添加元素 aaa aaad
                int cost2 = dp[i][j - 1] + ic;
                //改str1 adc abc
                int cost3 = dp[i - 1][j - 1] + rc;
                dp[i][j] = min({cost1,cost2,cost3});
            }
        }
    }
    cout << dp[n][m];
    system("pause");
    return 0;
}