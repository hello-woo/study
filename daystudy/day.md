
# 寒假目标
（1） 完成一篇小论文投老板期刊

（2） 读懂完成一个服务器的项目

（3） 补充操作系统和数据库的学习

（4） 按照codetop每日刷题3道

--------------------------------------
zzc 密码：12345678

```
IEEE transactions on industrial informatics

2022/01/17 submited awaiting co-eic assignment

2022/01/21 awaiting ae assignment

2022/01/25 assigning reviewers

2022/01/30 assign additional reviewers

2022/02/05 assigning reviewers

2022/02/11 assign additional reviewers

2022/02/13 assigning reviewers

2022/02/24 assign additional reviewers

2022/04/11 email to lisa

2022/04/14 awaiting review scores

2022/06/20 awaiting ae recommendation

2022/06/27 major reversion

2022/08/03/ submitted revision(Inviting reviewers)

2022/08/05 Waiting for Reviews

2022/08/20 Selecting reviewers

2022/08/21 Waiting for Reviews
```
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

# 2022/02/12

(1)合并两个升序链表注意事项

(2)合并K个升序链表

(3)K路归并排序（常考）

利用优先队列进行排序


完成codetop以下三题
![image-20220212233423878](https://s2.loli.net/2022/02/12/zU6bvB1EfdRW3lp.png)

其中第一题有困难，最后一题需要尝试O(NlogN)的解法

# 2022_02_13
(1) 完成黑马程序员MySQL数据库入门到精通的p1-p32

(2) 完成每日一题打卡，后续补充codetop3题打卡

# 2022/02/14- 2022/02/15

(1) 完成黑马程序员MySQL数据库入门到精通的p33-p88

(2)完成codetop几道题的练习。

# 2022/02/15 - 2022/02/19

(1)完成所有黑马数据库学习

(2)整理linux服务器项目学习

# 2022/02/19 - 2022/02/24
(1)整理项目相关问题，懂了信号、锁、线程池及项目运行流程

(2)复习有关面经知识，刷了每日一题

# 2022/03/27 

今天做了网易的笔试，看见好多人都全部ac了，自己只做了86%,40%,7%(4道题)，感觉自己真的好菜啊，笔试题真的好拉跨

以后还是要自己多做做笔试题，不能依赖别人，第二题和第四题自己想到了是动态规划，但是没有坚持的写下去，都只写了个大概

以后还是要坚定一点，

# 2022/05/17
字节教育后端一面
2022/05/17 字节教育后端一面

1. 自我介绍
2. 五层网络模型
3. 应用层协议有哪些？

> 回答了HTTP、DNS、FTP、telnet
>
> 其中Telnet不知道是啥，被追问

4. TCP三次握手具体，为什么三次

5. TCP四次挥手？
6. HTTPS和HTTP区别
7. HTTPS加密通信详细过程
8. 为什么要使用非对称加密和对称加密混合加密算法？
9. 数据库四大特性ACID什么意思？各自的实现原理是什么
10. 数据库的事务隔离级别，有什么区别
11. Mysql默认事务隔离级别是什么？解决了幻读嘛？
12. MySQL怎么解决幻读的？
13. 进程和线程的区别
14. 进程间通信方式
15. 死锁的四个条件
16. 怎么避免死锁？银行家算法知道吗？(不知道)

算法题：

1. 一个course表，teacher_id、course_id，统计每个老师的科目数量，按降序排列

2. 冒泡排序以及优化

(提示了一轮如果是有序的，那就什么都不做，没写出了，我是真的蠢)

```cpp
void bubble_sort(vector<int>&nums){
    for(int i = 0 ; i< nums.size();i++){
        bool flag = false;
        for(int j = 0 ;j < nums.size() - i - 1;j++){
            if(nums[j] > nums[j + 1] ){
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                flag = true;
            }
        }
        if(flag == false) break;
    }
}
```






