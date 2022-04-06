#include<bits/stdc++.h>

using namespace std;


typedef long long ll;

const int M = 1e9 + 7;//很大的一个质数
const int B = 679;

ll get_hash(const string a){
    ll res = 0;
    for(int i= 0 ;i < a.size();i++){
        res = (res * B + a[i] ) % M;
    }
    return res;
}

bool cmp(const string& a,const string& b){
    return get_hash(a) == get_hash(b);
}


int main(){
    string a,b;
    cin >> a >> b;
    if(cmp(a,b)) cout << " equal !" <<endl;
    else cout << " not equal!" <<endl;
    return 0;
}