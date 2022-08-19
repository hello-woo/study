/*
给你一个下标从 0 开始的整数数组 nums ，该数组由 互不相同 的数字组成。另给你两个整数 start 和 goal 。

整数 x 的值最开始设为 start ，你打算执行一些运算使 x 转化为 goal 。你可以对数字 x 重复执行下述运算：

如果 0 <= x <= 1000 ，那么，对于数组中的任一下标 i（0 <= i < nums.length），可以将 x 设为下述任一值：

x + nums[i]
x - nums[i]
x ^ nums[i]（按位异或 XOR）
注意，你可以按任意顺序使用每个 nums[i] 任意次。使 x 越过 0 <= x <= 1000 范围的运算同样可以生效，但该该运算执行后将不能执行其他运算。

返回将 x = start 转化为 goal 的最小操作数；如果无法完成转化，则返回 -1 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-operations-to-convert-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

class Solution {
public:
    struct node{
        int x;
        int step;
    };
    const static int N = 1005;
    int vis[N] ={0};
    int minimumOperations(vector<int>& nums, int start, int goal) {
        if(start == goal) return 0;
        queue<node>q;
        q.push({start,0});
        vis[start] = 1;
        while(!q.empty()){
            node temp = q.front();
            q.pop();
            //对于每个数，都有三个操作，遍历每一个数，进行三个操作即可
            for(int i = 0 ; i  < nums.size();i++){
                node nextNum;
                nextNum.x = 0;
                nextNum.step = 0;

                for(int k = 0 ; k < 3;k++){
                    if(k == 0){
                        nextNum.x = temp.x + nums[i];
                    }else if(k == 1){
                        nextNum.x = temp.x - nums[i]; 
                    }else{
                        nextNum.x = (temp.x ^ nums[i]) ; 
                    }
                    
                    if(nextNum.x == goal) return temp.step + 1;

                    
                    //cout << nextNum.x << endl;
                    if(nextNum.x < 0 || nextNum.x >1000 || vis[nextNum.x]) continue;

                    if(!vis[nextNum.x]){
                        vis[nextNum.x] = 1;
                        nextNum.step = temp.step + 1;
                        q.push(nextNum);
                    }

                }
            }
        }
        return -1;
    }
};
