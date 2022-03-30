#include<bits/stdc++.h>

using namespace std;

int main(){
    unordered_map<char,int>mp1,mp2;
    mp1['a'] = 1;
    mp1['b'] = 1;

    mp2['b'] = 1;
    mp2['a'] = 1;

    if(mp1 == mp2){
        cout << "eqaul ! "<<endl;
    }else{
        cout <<"not equal"<<endl;
    } 

    return 0;
}