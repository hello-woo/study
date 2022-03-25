#include<bits/stdc++.h>

using namespace std;

string jiami(string &s ,int n){
    string t = "";
    while(s.size() != 0){
        double len = s.size();
        //cout << " len " << len <<endl;
        int index = ceil(len / 2 );
       // cout << "index "<< index<<endl;
        t += s[index - 1];

        s.erase(s.begin() + index - 1);
       // cout << "eras: " << s<<endl;
        //cout << "size : "<<s.size() <<endl;
    }
    return t;
}

// string jiemi(string & s,int n){
//     string t = "";

//     while(s.size()!=0){
//         char temp = s.back();
//         s.pop_back();
//         double len = s.size();
//         int indx = floor(len / 2);
//         t.insert(s.begin() + indx ,temp);
//     }
//     return t;
// }

string jiemi(string &s ,int n){
    string res(n,'0');
    int indx = 0;

}

int main(){
    int n ,t;
    cin >> n >> t; //长度为n,t = 1，加密，t = 2 解密
    string s ;//字符串s
    cin >> s;
    string res;
    if(t == 1){
        res = jiami(s,n);
    }else{
        res = jiemi(s,n);
    }
    cout << res << endl;
    return 0;
}