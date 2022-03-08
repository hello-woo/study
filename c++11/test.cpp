#include<bits/stdc++.h>

using namespace std;

int main(){
    int a = 10;
    shared_ptr<int>pa = make_shared<int>(a);
    cout << pa.use_count() << endl;
    return 0;
}

