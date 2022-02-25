/*************************************************************************
	> File Name: or_singleton.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 06 Apr 2021 01:02:49 PM CST
 ************************************************************************/

#include<iostream>
#include<pthread.h>

using namespace std;

class singleInstance{
public:
    static singleInstance* GetsingleInstance(){
        if(instance==NULL){
            pthread_mutex_t mutex;
            pthread_mutex_lock(&mutex);
            if(instance==NULL){
                instance=new singleInstance();
            }
            pthread_mutex_unlock(&mutex);
        }
        return instance;
    }
private:
    singleInstance(){}
    singleInstance(const singleInstance& other){}
    singleInstance& operator=(const singleInstance& other){return *this;}
    static singleInstance* instance;
};

singleInstance* singleInstance::instance=NULL;
int main(){
    singleInstance* s=singleInstance::GetsingleInstance();
    return 0;
}

