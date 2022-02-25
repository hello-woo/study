/*************************************************************************
	> File Name: lh-single.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 06 Apr 2021 02:45:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Singleton{
public:
    static Singleton* GetInstance(){
        if(_instance==nullptr){
            _instance=new Singleton();
            atexit(Desconstructor);
        }
        return _instance;
    }
private:
    static void Desconstructor(){
        if(_instance!=nullptr){
            cout<<"Desconstructor !"<<endl;
            delete _instance;
            _instance=nullptr;
        }
    }
   static Singleton* _instance;
    Singleton(){
        cout<<"Singleton constructor!"<<endl;
    }
    Singleton(const Singleton& other){}
    Singleton& operator=(const Singleton& ){ return *this; }
};
Singleton* Singleton::_instance=nullptr;

int main(){
    Singleton *s=Singleton::GetInstance();
    Singleton *s1=Singleton::GetInstance();
    return 0;
}
