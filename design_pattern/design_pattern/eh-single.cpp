/*************************************************************************
	> File Name: eh-single.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 06 Apr 2021 03:02:38 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


class Singleton{
public:
    static Singleton& GetInstance(){
        static Singleton _instance;
        return _instance;
    }
    ~Singleton(){};
private:
    Singleton(){}
    Singleton(const Singleton& other){}
    Singleton& operator=(const Singleton &other){ return *this; }
};


