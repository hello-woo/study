/*************************************************************************
	> File Name: singleton.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 29 Dec 2020 05:01:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class Singleton{
public:
    static Singleton* getInstance(){
        if(_instance==0){
            _instance=new Singleton();
        }
        return _instance;
    }
private:
    static Singleton* _instance;
    Singleton(){
        cout<<"singleton..."<<endl;
    }

};
Singleton *Singleton::_instance=0;

int main(){
    Singleton *sgn1=Singleton::getInstance();
    Singleton *sgn2=Singleton::getInstance();
    delete sgn1;
    return 0;
}
