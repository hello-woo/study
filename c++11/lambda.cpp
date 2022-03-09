#include<bits/stdc++.h>

using namespace std;

/*
lambda表达式，就是匿名函数(没有名字的函数)
*/

int Foo(int a ,int b){
    return a + b;
}

int main(){
    //[]捕获列表  ()参数列表  ->返回值
    int c = [](int a,int b)->int{
        //函数体
        return a + b;
    }(1,2); // 等价于 Foo(1,2)

    cout << c  <<endl; 
    auto f = [](int a,int b)->int{
        //函数体
        return a + b;
    };
    int e = f(1,2);

    auto f1 = [](int n){
        return [n](int x ){
            return x + n;
        };
    };

    int ant = f1(1)(2);
    cout << ant << endl;
    cout << e <<endl;

    return 0;
}