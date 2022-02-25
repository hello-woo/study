/*************************************************************************
	> File Name: observe.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 06 Apr 2021 03:49:17 PM CST
 ************************************************************************/

#include<iostream>
#include<list>
using namespace std;
//抽象观察者
class Observer{
public:
    virtual void Upadate(int )=0;
};
//被观察者抽象；
class Subject{
public:
    virtual void Attach(Observer*)=0;
    virtual void Detach(Observer*)=0;
    virtual void Notify()=0;
};

class ConcreteObserver1:public Observer{
public:
    ConcreteObserver1(Subject *pSubject):m_pSubject(pSubject){}
    void Upadate(int value){
        cout<<"ConcreteObserver1 get the Upadate .New State: "<<value<<endl;
    }
private:
    Subject *m_pSubject;
};

class ConcreteObserver2:public Observer{
public:
    ConcreteObserver2(Subject *pSubject):m_pSubject(pSubject){}
    void Upadate(int value){
        cout<<"ConcreteObserver2 get the Upadate .New State: "<<value<<endl;
    }
private:
    Subject *m_pSubject;
};

class ConcreteSubject:public Subject{
public:
    void Attach(Observer *pObserver);
    void Detach(Observer *pObserver);
    void Notify();
    void SetState(int state){
        m_iState=state;
    }
private:
    list<Observer *>m_ObserverList;
    int m_iState;
};

void ConcreteSubject::Attach(Observer *pObserver){
    m_ObserverList.push_back(pObserver);
}

void ConcreteSubject::Detach(Observer *pObserver){
    m_ObserverList.remove(pObserver);
}

void ConcreteSubject::Notify(){
    list<Observer *>::iterator it=m_ObserverList.begin();
    while(it!=m_ObserverList.end()){
        (*it)->Upadate(m_iState);
        ++it;
    }
}

int main(){
    //创建被观察者
    ConcreteSubject *pSubject = new ConcreteSubject();
    //创建 观察者
    ConcreteObserver1 *pObserver1 = new ConcreteObserver1(pSubject);
    ConcreteObserver2 *pObserver2 = new ConcreteObserver2(pSubject);
    //改变状态
    pSubject->SetState(2);
    //注册观察者
    pSubject->Attach(pObserver1);
    pSubject->Attach(pObserver2);
    //通知观察者
    pSubject->Notify();
    //删除观察者
    pSubject->Detach(pObserver1);

    pSubject->SetState(3);
    pSubject->Notify();

    delete pObserver1;
    delete pObserver2;
    delete pSubject;
    return 0;
}

