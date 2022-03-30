#include<bits/stdc++.h>

using namespace std;


int main(){
    vector<int>v;
    v.reserve(100);
    cout << v.size() <<endl; //0 
    v.resize(50);
    cout << v.size() << " ," << v.capacity() << endl;// 50 ,100;
    return 0;
}