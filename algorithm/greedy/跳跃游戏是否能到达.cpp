class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int maxpos = 0;
        //从左到右维护一个可以跳的最大值
        for(int i = 0 ;i < n;i++){
            //当前坐标能到达的最远点
            int cur = nums[i] + i;

            //全局最远点
            if(cur > maxpos){
                maxpos = cur;
            }

            //如果当前最远点==全局最优点，而且当且为0，说明跳不动了，即不可达
            if(cur == maxpos && nums[i] == 0){
                return false;
            }

            if(maxpos >= n - 1){
                return true;
            }
        }
        //cout << maxpos <<endl;
        return false;
    }
};