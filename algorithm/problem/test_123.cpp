/*************************************************************************
	> File Name: test_123.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 19 Mar 2021 07:10:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


#include <bits/stdc++.h>

int main() {

    int n;
    cin >> n;
    vector<int> nums;
    int cnt = n;
    while(cnt--) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    vector<int> help(n);
    for(auto& v: nums) {
        int temp = sqrt(v);

        help.push_back(min(abs(v-temp*temp),abs(v-(temp+1)*(temp+1))));
    }
    int res = 0;

    sort(help.begin(), help.end());

    for(int i = 0; i < n/2; ++i) {
        res+=help[i];
    }

    cout << res << endl;
    return 0;
}
