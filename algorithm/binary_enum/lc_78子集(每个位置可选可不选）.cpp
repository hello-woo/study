/**
 * @file lc_78子集(每个位置可选可不选）.cpp
 * 
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>>ans;
    if(nums.size() == 0) return ans;
    int n = nums.size();
    int limit = 1 << n;//等价于pow(2,n);

    //因为n最大只有10，可以枚举所有情况
    for(int i = 0 ;i < limit;i++){
        vector<int>now;
        //枚举每一位
        for(int j = 0 ;j < n;j++){
            //如果第j位选的话
            if((i >> j) & 1){
                now.push_back(nums[j]);
            }
        }
        ans.push_back(now);
    }
    return ans;
}
