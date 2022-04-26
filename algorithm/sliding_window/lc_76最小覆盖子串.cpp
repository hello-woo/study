/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-window-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>smp,tmp;
        //先统计字符串t中每个字符的数量
        for(auto p : t){
            tmp[p]++;
        }
        int l = 0,r = 0;//滑动窗口
        int cnt = 0; //统计能够匹配t的字符个数，如果cnt == t.size()，说明满足条件，取最短的字符串。
        string ans;
        while(r < s.size()){

            ++smp[s[r]];
            //如果s中字符个数小于t中个数，说明该字符满足要求
            if(smp[s[r]] <= tmp[s[r]])  cnt++;


            while(smp[s[l]] > tmp[s[l]]){
                smp[s[l]]--;
                l++;
            }

            r++;

            if(cnt == t.size()){
                //cout << "r :" << r << " l:" <<l <<endl;
                if(ans.empty() || r - l < ans.size()){
                    ans = s.substr(l,r - l);
                }
            }
        }
        return ans;
    }
};