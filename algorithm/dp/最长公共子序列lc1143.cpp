/*
最长公共子序列，不一定要连续
afgedh
agfehb

---ageh  ---->4

if(s1[i - 1]== s2[j - 1]){
    dp[i][j] = dp[i - 1][j - 1] + 1;
}else{
    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m  = text1.size(),n = text2.size();
        int ans = 0;
        vector<vector<int>>dp(m + 1 ,vector<int>(n + 1,0));
        for(int i = 1 ; i  <= m; i++){
            for(int j = 1 ;j <= n;j++){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};