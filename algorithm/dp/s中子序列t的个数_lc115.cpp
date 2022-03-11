/*给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。

字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

题目数据保证答案符合 32 位带符号整数范围。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distinct-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
rabbbit
rabbbit
rabbbit
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        //dp[i][j]:以i- 1结尾的s子序列中包含以j- 1结尾的t序列的个数
        long long  m = s.size(),n = t.size();
        if(m < n) return 0;
        vector<vector<uint64_t >>dp(m + 1,vector<uint64_t>(n + 1,0));
        //任何字符串匹配空串都有一个
        for(int i = 0 ; i <= m ;i++) dp[i][0] = 1;
        for(int i = 1; i <= m;i++){
            for(int j = 1; j <= n;j++){
                //如果两个字符相等，可以用或者不用s[i - 1]两种情况来匹配
                //不用第i- 1位,即用i-2位匹配j-1位:dp[i][j] = dp[i - 1][j]
                //用i - 1位 :用i - 1位去匹配j - 1 位,两者相同，那么dp[i][j]就等价于i-2位去匹配j-2的情况:dp[i][j] = dp[i- 1][j - 1];
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }else{
                    dp[i][j]  = dp[i - 1][j];//不相等，就只能用s[i-2]去匹配t[j  - 1]了
                }
            }
        }
        return dp[m][n];
    }
};

