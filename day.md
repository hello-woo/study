
# 寒假目标
（1） 完成一篇小论文投老板期刊

（2） 读懂完成一个服务器的项目

（3） 补充操作系统和数据库的学习

（4） 按照codetop每日刷题3道

--------------------------------------
zzc 密码：12345678

IEEE transactions on industrial informatics

2022/01/17 submited Awaiting Co-EIC Assignment

2022/01/21 Awaiting AE assignment

2022/01/25 Assigning Reviewers

2022/01/30 	Assign additional Reviewers

2022/02/05 Assigning Reviewers

2022/02/11 Assign additional Reviewers

# 2022/01/23
通过PLC完成了电机x,y轴的点动前进和后退

git新建文件夹并且push过程
```cpp
git init 
git add Read.md
git commit -m "first commit"
git branch -M main
git remote add origin git@github.com:hello-woo/myhttp.git 
git push -u origin main
```
![image-20220123225957174](https://s2.loli.net/2022/01/23/YLiZlE6BV8PrSMX.png)

# 2022/01/24

阅读实验室plc通信控制送丝速度和焊接电流的代码

完成codetop 206 146 3 代码题

晚上看《中国医生》

# 2022/01/25
完成codetop 215、25和手撕快速排序三道题

睡到12点，玩了一下午吃鸡，晚上看开端大结局，写了三道题

# 2022/01/26
(1)完成codetop 15,53,1 总共三道题，分别是双指针，动态规划和哈希表的题

(2)阅读游双 《高性能服务器编程》
# 第一章TCP/IP协议族
数据链路层（ARP<地址解析协议>、RARP----》网络层-》传输层----》应用层

数据链路层：实现IP地址和机器物理地址(MAC地址的相互转换)。网络层通过ip地址寻址一台机器，数据链路层使用物理地址寻址一台机器。

网络层：实现数据包的选路和转发，IP协议，ICMP协议。

传输层的协议：TCP、UDP、SCTP协议。

（1）TCP协议提供可靠的、面向连接的和基于流的服务。超时重传，数据确认等方式确保数据包被正确地发送至目的地。基于流的数据没有边界限制，

（2）UDP协议则与TCP协议完全相反,它为应用层提供不可靠、无连接和基于数据报文的服务。无连接是指通信双方不保持一个长久的联系，应用程序每次发送数据都要明确指定接收端的地址。基于数据报文，相对于基于流的服务而言，每个数据报文都有一个长度，接收端必须以该长度为最小单位将其所有内容一次性读出，否则数据将被截断。

应用层：负责处理应用程序的逻辑，ping,telnet,OSPF,DNS(域名服务)

封装：每层协议将在上层数据的基础上加上自己头部的信息，以实现该过程的功能。

ARP协议工作原理：实现了IP地址到MAC地址的转换，其工作原理是：主机向自己所在的网络广播一个ARP请求，该请求包含目标机器的网络地址。此网络上的其他机器都将收到这个请求，但只有被请求的及其会回应一个ARP应答，其中包含自己的物理地址。

# 2022.01.27 
完成以下三题打卡
![image-20220127225553018](https://s2.loli.net/2022/01/27/tiQOjoru723Wdag.png)


# 2022/01/28
完成以下三题打卡
![image-20220128225451501](https://s2.loli.net/2022/01/28/A2h9qLc8HY6QOty.png)
吃完饭，中午写了每日一题，下午晚上追完开端，之后要看书补充操作系统数据库学习，还有项目介绍没看完，科研也没有进展.

# 2022/01/29 
![image-20220129215658313](https://s2.loli.net/2022/01/29/PmB4fNIv1z5abAX.png)
完成下面三道题
![image-20220129221651457](https://s2.loli.net/2022/01/29/JWreAOnMsufvUBm.png)

和每日一题 多源BFS的应用，碰到水域加入到队列中，
```cpp
queue<pair<int,int>>que;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
if(grid[i][j] == 1) que.push(make_pair(i,j));
while(!que.empty()){
    auto p = que.front();
    que.pop();
    for(int i = 0;i < 4; i++){
        int  x0 = p.first + dir[i][0];
        int y0 = p.second + dir[i][1];
        if(x0 >= 0&& x0 < Row && y0 >= 0 && y0 < Col  && vis[x0][y0] = false){
            vis[x0][y0] = true;
            ans[x0][y0] = ans[p.first][p.second] + 1;
            que.push(make_pair(x0,y0));
        }
    }
}
```

# 2022/01/30
完成codetop 3题以及每日一题
其中大整数加法，和旋转数组找target和最长回文串

（1）大整数加法
```cpp
string add(string num1,string num2){
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string ans;
    while(i >=0 || j >= 0 || carry){
        int a = (i >= 0)? num1[i] - '0' : 0;
        int b = (j >= 0) ? num2[j] - '0' : 0;
        int curVal = a + b + carry;
        carry = curVal % 10;
        ans += curVal / 10 + '0;
    }
    reverse(ans.bengin(),ans.end());
    return ans;
} 
```

(2）旋转数组，可以分成四段，如果mid的值大于nums[0]，说明在前半段，这其中分为target在nums[0]和nums[mid]中间和其他
```cpp
if(target == nums[mid]) return mid;
if(nums[0] < nums[mid]){
    if(nums[0] <= tagert && target <= nums[mid]){
        right = mid - 1;
    }else{
        left = mid + 1;
    }
}else{
    if(nums[mid] <= target && target <= nums[nums.size() - 1]){
        left = mid + 1;
    }else{
        right = mid - 1;
    }
}
```

（3）最长回文子串

思路：利用动态规划预处理字符串，找出回文子串；
```cpp
string maxlenhuiwen(string str){
    int n = str.size();
    int maxlen,left,right;
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    for(int i = n -1 ;i >=0;i--){
        for(int j = i ;j < n ;j ++){
            if(s[i] == s[j] && ( j- i <=1 || dp[i+1][j-1] == true)){
                dp[i][j] = true;
            }
            if(dp[i][j] == true && j- i + 1 > maxlen){
                left = i;
                right = j;
                maxlen = right - left + 1;
            }
        }
    }
    return str.substr(left,maxlen);
}
```

# 2022/02/11
上午睡到11点；下午和老师交流延期毕业时间问题，没想到老师可以让我提前毕业，但是自己没有论文产出，还是自己不争气，晚上完成以下三题并且打卡每日一题；
后面继续加油！
![image-20220212001403364](https://s2.loli.net/2022/02/12/u379VoCt8JUlBSh.png)
（1）全排列问题：不同于组合问题，不需要startIndex,但是需要used数组，标记每个字符是否被用到过！，每轮都是从0开始;需要一个path数组和一个记录答案得数组。

```cpp
vector<vector<int>>ans;
vector<int>path;
void dfs(vector<int>& nums,vector<bool>&used){
    if(path.size() == nums.size()){
        ans.push_back(path);
        return;
    }
    for(int i = 0 ;i < nums.size();i++){
        if(used[i]) continue;
        used[i] = true;
        path.push_back(nums[i]);
        dfs(nums,used);
        used[i] = false;
        path.pop_back();
    }
}
vector<vector<int>>pumute(vector<int>&nums){
    vector<bool>used(nums.size(),false);
    dfs(nums,used);
    return ans;
}
```