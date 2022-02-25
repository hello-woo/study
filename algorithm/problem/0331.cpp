/*************************************************************************
	> File Name: 0331.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 31 Mar 2021 07:17:57 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> nums; 
    int temp;
    while(cin >> temp) {
        nums.push_back(temp);
    }

    sort(nums.begin(), nums.end());
    int n = nums.size();
    int res = 0;
    for(int i = 0; i < n;) {
        int cur = i;
        while(cur + 1 < n && nums[cur] == nums[cur + 1]) cur++;
        int cnt = cur - i + 1;
        int a = (cnt % (nums[i] + 1) == 0)? cnt / (nums[i] + 1) : cnt / (nums[i] + 1) + 1;
        res += a * (nums[i] + 1);
        i = cur + 1;
    }

    cout << res << endl;
    return 0;
}
