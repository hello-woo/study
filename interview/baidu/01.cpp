#include<bits/stdc++.h>

using namespace std;

const int N = 1e8 + 5;
long long  prime[N];
bool isprime[N];
long long  cnt = 0;

void getprim(long long  n){
    cnt = 0;
    for(int i = 2; i <= n;i++){
        if(!isprime[i]) prime[++cnt] = i;
        for(int j = 1; j <= cnt ;j++){
            if(i * prime[j] > n) break;
            isprime[i* prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

int getgcd(int n1 ,int n2){
    int k = n1 % n2;
    if(k == 0) return n2;
    else{
        return  getgcd(n2, k);
    }
}


int getNum(int n){
    set<pair<int,int>>s;
    getprim(n);
    // for(int i = 1 ; i <= cnt;i++){
    //     cout << prime[i] << " , ";
    // }
    // cout << endl;
    //这里不能
    s.insert(make_pair(1,n));
    for(int i = 1 ;i <= cnt;i++){
        //cout<< prime[i] <<", ";
        int modeval = n % prime[i];
        long long  chu = n / prime[i];
        if(modeval != 0) continue;
        int gcd = getgcd(chu,prime[i]);
        //cout << gcd <<"---"<<endl;
        if( modeval == 0 && gcd == 1){
            if(chu < prime[i]) swap(chu ,prime[i]);
            
            s.insert(make_pair(prime[i], chu));
        }
    }
    // for(auto p : s){
    //     cout <<  p.first << " ," <<p.second<<endl;
    // }
    return s.size() ;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long  n ;
        scanf("%lld",&n);
        cout << getNum(n) <<endl;
    }
    return 0;
}