/*************************************************************************
	> File Name: rand.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 15 Jan 2021 03:52:52 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    srand(time(0));
    int arr[26];
    int sum=0;
    for(int i=0;i<26;i++){
        arr[i]=rand()%1000;
        sum+=arr[i];
    }
    printf("26\n");
    for(int i=0;i<26;i++){
        printf("%c %lf\n",i+'A',1.0*arr[i]/sum);
    }
    return 0;
}
