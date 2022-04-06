//
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 1;
        sort(points.begin(),points.end(),cmp);
        for(int i = 1 ;i  <points.size();i++){
            int preRightPos = points[i - 1][1];
            if(points[i][0] > preRightPos){
                ans++;
            }else{
                //更新交集的最右边界
                 points[i][1] = min(preRightPos,points[i][1]);
                //cout << preRightPos <<endl;
            }
        }
        return ans;
    }
};