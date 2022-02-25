/*************************************************************************
	> File Name: factory.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 06 Apr 2021 03:13:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//产品类，抽象类，不能实例化;
class Product{
public:
    Product(){};
    virtual void show()=0;//纯虚函数；
};

class ProductA:public Product{
public:
    ProductA(){};
    void show(){ cout<<"Product A Created!"<<endl; }
    ~ProductA();
};
class ProductB:public Product{
public:
    ProductB(){};
    void show(){ cout<<"Product B Created!"<<endl; }
    ~ProductB();
};

class Factory{
public:
    virtual Product* CreateProduct()=0;
};
//工厂类A，只生产A类产品：
class FactoryA:public Factory{
public:
    Product* CreateProduct(){
        Product* _Product =nullptr;
        _Product =new ProductA();
        return _Product;
    }
};

class FactoryB:public Factory{
public:
    Product* CreateProduct(){
        Product* _Product =nullptr;
        _Product =new ProductB();
        return _Product;
    }
};
int main(){
    Product* _Product=nullptr;
    auto MyFactoryA=new FactoryA();
    _Product=MyFactoryA->CreateProduct();//调用产品A的工厂来生产A产品;
    _Product->show();
    delete _Product;

    _Product=nullptr;
    auto MyFactoryB=new FactoryB();
    _Product=MyFactoryB->CreateProduct();//调用产品A的工厂来生产A产品;
    _Product->show();
    delete _Product;
    return 0;
}
