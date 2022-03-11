/*
当nums[i] > nums[j] 时有：  最长递增子序列 dp[i]  = dp[j] + 1 
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n , 1);
        if(n == 1) return 1;
        dp[0] = 1;
        int ans  = 0;
        for(int i = 1 ; i < n ;i++){
            for(int j = 0; j < i ;j++){
                if(nums[j] < nums[i]){
                    dp[ i ]  = max(dp[i],dp[j] + 1);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    } 
};