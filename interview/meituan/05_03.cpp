#include<bits/stdc++.h>

using namespace std;

const int N = 5005;
int a[N];
int b[N];

int main(){
    int n,p,q;
    cin >> n >> p >> q;
    set<int>s1,s2;
    for(int i = 1 ;i <= p ;i++){
        cin >> a[i];
        s1.insert(a[i]);
    }
    for(int i = 1;i <= q;i++){
        cin >> b[i];
        s2.insert(b[i]);
    }
    int a_cnt = 0 ,b_cnt =0,com_cnt =0 ;
    for(auto p : s1){
        if(!s2.count(p)) a_cnt++;
        else com_cnt++;
    }
    cout << a_cnt << " " << q - com_cnt << " "<< com_cnt ;
    return 0;
}