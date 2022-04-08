#include<bits/stdc++.h>

using namespace std;

int main(){
    int val ;
    cin >> val;
    int cnt = 0 ;
    while(val){
        if(val & 1) cnt++;
        val >>= 1;
    }
    cout << cnt << endl;
    return 0;
}