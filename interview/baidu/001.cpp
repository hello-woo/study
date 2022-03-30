#include<bits/stdc++.h>

using namespace std;

const int N = 1e8 + 5;
long long  prime[N];
bool isprime[N];
long long  cnt = 0;

void getprime(long long  n){
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

int main(){
    int n ;
    cin >> n ;
    getprime(n);
    int maxprime  = prime[cnt];
    cout << maxprime <<endl;
    if(maxprime == n){
        cout << (n - 1) * maxprime - 1<<endl;
    }else{
        cout << maxprime * n - 1 <<endl;
    }
    return 0;
}