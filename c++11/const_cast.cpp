#include<bits/stdc++.h>

using namespace std;
/*
const_cast 只能用于指针、引用或者去除常成员函数去除this指针的const属性
*/

#if 0
int main(){
    int n = 5;
    const int *p = &n;
    //*p= 5 错误，常量指针，指针指向的值不能修改
    cout << *p << endl; // 5

    int* const a = &n;
   // a = 0x31;  错误，指针常量，指针的值不能改变；
   cout << *a << endl; //5
    return 0;
}
#endif

#if 0
int main (){
    const int n = 5;
    const std::string s = "abc";
    //invalid use of const_cast with type ‘int’, which is not a pointer, reference, 
    //nor a pointer-to-data-member type
    //int k = const_cast<int>(n); const_cast只能针对指针或者引用
    int* k = const_cast<int*>(&n);
    cout << *k << endl; //5

    int& ref = const_cast<int&>(n);
    cout << ref << endl; //5
    return 0 ;
}
#endif

class Test{
public:
    Test():m_ntest(2){}

    void foo(int nTest) const{
        //m_ntest = nTest; //错误，常量成员函数不能修改成员变量的值
        //把this指针(const Test* const)转化为Test* ;
        const_cast<Test* const>(this)->m_ntest = nTest;
    }
private:
    int m_ntest;
};

int main(){
    Test t;
    t.foo(1);
    return 0;
}