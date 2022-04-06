/*
给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。

示例 1:

输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-overlapping-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

//解答1 ：贪心，按照右端点升序排序，每次满足取最小右区间，使得无重叠区间最多，
class Solution {
public:
    //先按右区间排序
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int cnt = 1;
        //先统计不重复的区间个数
        int preRightPos = intervals[0][1];
        for(int i = 1 ; i< intervals.size();i++){
            //更新右区间
            if(intervals[i][0] >= preRightPos){
                preRightPos = intervals[i][1];
                cnt++;
            }
        }
        return intervals.size() - cnt;
    }
};

//解法2：思路同452题，
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        //先计算没有重叠区间的个数，然后n减去即可
        int ans = 1;
        for(int i = 1 ;i < intervals.size();i++){
            int preRightPos = intervals[i - 1][1];
            if(intervals[i][0] >= preRightPos){
                ans++;
            }else{
                intervals[i][1] = min(intervals[i][1],preRightPos);
            }
        }
        return intervals.size() - ans;
    }
};