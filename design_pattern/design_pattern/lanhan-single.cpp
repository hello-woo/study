/*************************************************************************
	> File Name: lanhan-single.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 06 Apr 2021 02:21:34 PM CST
 ************************************************************************/

#include<iostream>
#include<pthread.h>
using namespace std;

class Singleton{
public:
    static Singleton* GetInstance(){
        if(instance==NULL){
            pthread_mutex_t mutex;
            pthread_mutex_lock(&mutex);
            if(instance==NULL){
                instance=new Singleton();
                atexit(Destructor);
            }
            pthread_mutex_unlock(&mutex);
        }
        return instance;
    }
private:
    static void Destructor(){
        if(instance!=nullptr){
            cout<<"Singleton Destructor!"<<endl;
            delete instance;
            instance=nullptr;
        }
    }
    static Singleton* instance;
    Singleton(){
        cout<<"Singleton construct!"<<endl;
    };
    Singleton(const Singleton& other){};
    Singleton& operator=(const Singleton& other){ return *this; }
};
Singleton* Singleton::instance=NULL;

int main(){
    Singleton* s=Singleton::GetInstance();
    return 0;
}
