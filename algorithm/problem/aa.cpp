/*************************************************************************
	> File Name: aa.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 22 Mar 2021 07:37:06 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int mainFunc(vector<int>& nums) {
    vector<int> sums(nums.size(), 0);
    sums[0] = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        sums[i] = nums[i] + sums[i-1];
    }
    int midSum = sums.back()/2;
    int left = 0;int right = 1;
    while(left != right) {
        midSum = (sums[right] - sums[left])/2;
        for(int i = left; i < right; ++i) {
            if(sums[i] - sums[left] > midSum) {
                if((sums[i-1] - sums[left]) > (sums[right] - sums[i])) 
                {
                    right = i;
                    break;
                } else {
                    left = i + 1;
                    break;
                }
            } else {
                right++;
            }
        }
        res+= sums[right] - sums[left];
    }
}
