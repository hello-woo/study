/*************************************************************************
	> File Name: 111.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 15 Mar 2021 09:13:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class Test{
public:
    const int b=3;
    static const int i=3;
   /* static  void fun() const{
        cout<<"hello";
    }*/ //error 错误 静态成员函数没有this指针，而const初始化需要实例化对象；
};
//const int  Test::i=2;
int main(){
    cout<<Test::i<<endl;
  //  Test::fun();
    int a=3;
    const int *p= &a;
    int *const m=&a;
    *m=4;
   // *p=4;(错误，常量指针，指针所指向的值不能改变，只读（readonly)
    cout<<*p<<endl;
    cout<<*m<<endl;
    return 0;
}
