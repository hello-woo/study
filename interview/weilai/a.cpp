#include<bits/stdc++.h>
using namespace std;

bool check(int n){
    string str = to_string(n);
    for(auto p : str){
        if(p == '5') return false;
    }
    return true;
}

void Myprint(){
    for(int i = 1; i <= 99;i++){
        if(check(i)){
            cout << i << endl;
        }
    }
}
int main(){
    Myprint();
    system("pause");
    return 0;
}