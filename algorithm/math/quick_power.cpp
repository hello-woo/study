#include<bits/stdc++.h>

using namespace std;

//计算 a ^ b % p;
typedef unsigned long long ull;

ull quick_mod(ull a,ull b,ull p){
    ull ans = 1;
    a = a % p;
    while(b){
        //如果b是奇数，例如 3 ^ 5 = 3 * (9)^2; 
        if(b & 1){
            ans = (a * ans) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return ans;
}

int main(){
    cout << quick_mod(3,9,47) << endl;
    return 0;
}