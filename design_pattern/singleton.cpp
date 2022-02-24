#include<stdlib.h>
#include<cstdio>
#include<iostream>
#include<pthread.h>

using namespace std;

//懒汉模式1 堆区内存泄漏，new没有delete，不支持多线程
#if 0 
class Singleton{
public:
    static Singleton* getInstance(){
        if(m_instance == nullptr){
            m_instance = new Singleton();
        }
        return m_instance;
    }

private:
    Singleton(){
        cout << "this is Singleton design pattern!"<<endl;
    }
    static Singleton *m_instance;
};

//静态成员变量要在类外初始化
Singleton *Singleton::m_instance = nullptr;
#endif

//懒汉模式2 添加析构函数
#if 0
class Singleton{
public:
    static Singleton *getInstance(){
        if(m_instance == nullptr){
            m_instance = new Singleton();
            atexit(Destructor);
        }
        return m_instance;
    }

private:
    static void Destructor(){
        if(m_instance != nullptr){
            delete m_instance;
            m_instance = nullptr;//防止野指针
        }
    }
    static Singleton *m_instance;
    Singleton(){
        cout << "this is Singleton design pattern!"<<endl;
    }
};
//静态成员变量要在类外初始化
Singleton *Singleton::m_instance = nullptr;
#endif

/*
new函数原理
1. 分配内存
2. 调用构造函数
3. 赋值指针，多线程环境下，cpu指令reorder，1，3，2，这样先赋值指针，是一个野指针。
*/

//懒汉模式 3 双重检测 支持多线程
/*
*/
#if 0
class Singleton{
public:
    static Singleton* getInstance(){
        if(m_instance == nullptr){
           pthread_mutex_t mutex;
           pthread_mutex_lock(&mutex); //加锁
            if(m_instance == nullptr){
                m_instance = new Singleton();
                atexit(Destructor);
            }
            pthread_mutex_unlock(&mutex);//解锁
        }
        return m_instance;
    }
private:
    static void Destructor(){
        if(m_instance != nullptr){
            delete m_instance;
            m_instance = nullptr;//防止野指针
        }
    }
    static Singleton *m_instance;
    Singleton(){
        cout << "this is Singleton design pattern!"<<endl; 
    }
};
//静态成员变量要在类外初始化
Singleton *Singleton::m_instance = nullptr;
#endif

/*
懒汉模式4 C++11特性，使用静态局部变量不用加锁
1、利用静态局部变量的特性，延迟加载；
2、利用静态局部变量的特性，系统自动回收内存，自动调用析构函数;
3、静态局部变量初始化时，没有new操作带来的cpu指令reoder操作；
4、c++ 11静态局部变量初始化时，具备线程安全;
*/
#if 0
class Singleton{
public:
    ~Singleton(){}
    static Singleton* getInstance(){
        static Singleton m_instance; //一定要加static关键字
        return &m_instance;
    }
private:
    Singleton(){
        cout << "this is Singleton design pattern!"<<endl; 
    }
};
#endif

/*饿汉模式：初始即实例化
饿汉模式会提前浪费内存空间和资源，一般推荐使用懒汉式
*/
#if 1
class Singleton{
public:
    static Singleton* getInstance(){
        return m_instance;
    }
private:
    static Singleton *m_instance;
    Singleton(){
        cout << "this is Singleton design pattern!"<<endl; 
    }
};

Singleton* Singleton::m_instance = new Singleton();
#endif


int main(){
    //Singleton s;
    Singleton:: getInstance(); //静态成员函数通过类名来访问
    return 0;
}