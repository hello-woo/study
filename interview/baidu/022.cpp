#include<bits/stdc++.h>

using namespace std;

int getgcd(int n1 ,int n2){
    int k = n1 % n2;
    if(k == 0) return n2;
    else{
        return  getgcd(n2, k);
    }
}

int getNum(int n){
    int cnt = 0;
    for(int i = 1 ;i <= sqrt(n);i++){
        int modval = n % i;
        if(modval != 0) continue;
        int chu = n / i;
        int gcd= getgcd(chu,i);
        if(modval == 0 && __gcd(chu,i) == 1){
            cout << "chu :" << chu << " i: " <<i <<endl;
            cnt++;
        }
        cout<< " ----------end ----------"<<endl;
    }
    return cnt;
}


int main(){
    int t ;
    cin >> t ;
    while(t--){
        int n;
        cin >> n;
        cout << getNum(n) <<endl;
    }
    return 0;
}