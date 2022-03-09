#include<bits/stdc++.h>

using namespace std;

#define LEN 10

/*
1.编译期： cpp--编译器-->exe
2.运行期：双击exe，exe被执行期间
*/

constexpr int len_foo(){
#if 0
    if(1) return 0; //constexpr 里面不能用if else
#endif
    return 5;
}

int main(){
    //局部变量，在栈上开辟空间，在编译期间分配
    char arr_1[10];
    char arr_2[LEN];

    int len = 5;
    char arr_3[len]; //错误，编译器在运行期间才能确定该变量的大小，从而分配空间

    char arr_4[len_foo() + 5]; //非法，可以在函数之前加上constexpr，常量表达式
    return 0;
}