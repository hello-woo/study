/*************************************************************************
	> File Name: static_const.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 14 Mar 2021 01:35:59 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Test{
public:
    Test(int val);//常量成员变量初始化
//    Test(int val):a(val){} //常量成员变量初始化
    enum{size1=100,size2=200};
    static void print();
private:
    const int a;//只能在构造函数初始化列表中初始化
    static int b;//在类的实现文件中定义和初始化
    const static int c;//与static const int c相同;一个是常量静态，一个是静态常量，静态都储存在全局变量区；
};
Test::Test(int val):a(val){
    b+=1;
}
int Test::b=0;//static成员变量不能在构造函数初始化列表中初始化，因为它不属于某个对象;前面也不能加static
const int Test::c=0;//注意：给静态常量成员变量赋值时，不需要加static关键字，但要加const;
void Test::print(){
    cout<<"b="<<b<<endl;
    cout<<"c="<<c<<endl;
}

int main(){
    Test t1(10);
    t1.print();
    Test::print();
    return 0;
}
