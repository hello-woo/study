#include<bits/stdc++.h>

using namespace std;

/*
[1,2,10]
[2,3,20]
[2,5,25]

n = 5;

  [1   2   3   4   5]
   10  10  
       20  20
       25  25  25  25
toatal：
    10  55 45  25  25 
return :
    10  55 45  25  25 

对于区间修改、单点查询可以考虑使用差分加上前缀和的思想
  [1   2   3   4   5]
   10     -10
       20      -20
       25           
diff:10  45  -10  -20 

preSum:
   10  55  45   25   25 
*/


vector<int> corpFlightBooking(vector<vector<int>>& booking ,int n){
    vector<int>ans(n,0);
    for(int i = 0 ;i < booking.size();i++){
        int left = booking[i][0] - 1;
        int right = booking[i][1] - 1;
        if(right + 1 < n){
            ans[right + 1] -= booking[i][2]; //右边界减去对应的数
        }
        ans[left] += booking[i][2]; // 左边界加对应的数
    }
    for(int i = 1 ; i < n ; i++){
        ans[i] += ans[i - 1];
    }
    return ans;
}

int main(){
    int n ; // n代表航班
    int m ; //m代表几条更新记录
    cin >> n >> m;
    vector<vector<int>>booking(m,vector<int>(3,0)); // first ---last ---seat
    for(int i = 0 ;i < m;i++){
        int first,last ,seat;
        cin >> first >> last >> seat;
        booking[i][0] = first;
        booking[i][1] = last;
        booking[i][2] = seat;
    }
    vector<int>ans = corpFlightBooking(booking,n);
    for(auto p : ans){
        cout << p << " ";
    }
    cout << endl;
    return 0;
}

/*
5 3
1 2 10
2 3 20
2 5 25
10 55 45 25 25 
*/