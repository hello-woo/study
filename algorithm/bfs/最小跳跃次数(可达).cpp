/**
 * @brief 
 * 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

假设你总是可以到达数组的最后一个位置。


示例 1:

输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
//bfs 解法：
class Solution {
public:
    struct Node{
        int x;
        int val;
        int step;
    };
    queue<Node>que;
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 ) return 0;
        vector<bool>vis(n,false);
        que.push({0,nums[0],0}); // x, val ,step
        vis[0] = true;
        while(!que.empty()){
            Node temp = que.front();
            que.pop();
            
            //可选的操作
            int maxpos = temp.x + temp.val;

            if(maxpos >= n - 1){
                return temp.step + 1;
            }

            while(maxpos){
                if(vis[maxpos] == false){
                    vis[maxpos] = true;
                    que.push({maxpos,nums[maxpos],temp.step + 1});
                }
                maxpos--;
            }
        }
        return 0;
    }
};