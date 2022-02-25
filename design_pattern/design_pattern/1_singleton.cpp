/*************************************************************************
	> File Name: 1_singleton.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 24 Mar 2021 03:44:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Singleton{
public:
    //共有静态成员函数
    static Singleton* GetInstance(){
        if(_instance==nullptr){
            _instance=new Singleton();
            atexit(Destructor);
        }
        return _instance;
    }
private:
    static void Destructor(){
        if(_instance!=nullptr){
            delete _instance;
            _instance=nullptr;
        }
    }
    Singleton(){}//私有构造函数
    static Singleton *_instance;//私有静态成员变量；
};

Singleton* Singleton::_instance=nullptr;//静态成员变量类外初始化；
