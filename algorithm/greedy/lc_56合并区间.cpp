/* 
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(int i = 0 ; i  < intervals.size();i++){
            int left = intervals[i][0];
            int right = intervals[i][1];
            int j = i + 1;
            while(j < intervals.size() && intervals[j][0] <= right){
                right = max(right,intervals[j][1]); 
                j++;
            }
            //right = max(right,intervals[j - 1][1]);[1,4],[1,6],[2,3],[5,6]不能是[j - 1]和之前的比较，因为中间也会有更大的
            ans.push_back({left,right});
            i = j - 1;//这里因为j++跳出上一个循环已经+1,而且主循环还有+1,这里减1保持一致
        }
        return ans;
    }
};