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

class SimpleFactory{
private:
    Product *m;
public:
    SimpleFactory(){};
    Product* Produce(const string str){
        if(str=="ProductA") m=new ProductA();
        if(str=="ProductB") m=new ProductB();
        return m;
    }
};

int main(){
    SimpleFactory obj;
    Product* pro;
    pro=obj.Produce("ProductA");
    pro->show();
    pro=obj.Produce("ProductB");
    pro->show();
    delete pro;
    return 0;
}
