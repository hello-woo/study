#include<bits/stdc++.h>

using namespace std;

int foo(char *p){
    cout << "char * :" << endl;
}

void foo(int n ){
    cout << "int " << endl;
}

int main(){
    char *p = NULL;
    //以下错误，call of overloaded ‘foo(NULL)’ is ambiguous 二义性
    //c++中NULL代表0，
    //foo(NULL);
    foo(nullptr); // char * ,nullptr表示空指针
    return 0;
}