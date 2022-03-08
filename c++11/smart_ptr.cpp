#include<bits/stdc++.h>

using namespace std;

template<typename T>
class smart_ptr{
public:
    //无参构造
    smart_ptr():_count(0),_ptr((T*)(0)){}
    //有参构造
    smart_ptr(T* ptr = nullptr):_ptr(ptr){
        if(ptr){
            _count = new int(0);
            ++(*_count);
        }
        cout << "Constructor is succeed!" << endl;  
    }
    //左值:复制，拷贝构造函数
    smart_ptr(const smart_ptr<T>&other){
        _count = other._count;
        _ptr = other._ptr;
        ++(*_count);
        cout << "Copy constructor is succeed!" << endl; 
    }

    //右值拷贝：a=b，b里面的所有权给a，b指向空
    smart_ptr(smart_ptr<T>&& other){
        _ptr = other._ptr;
        if(_ptr){
            _count = other._count; //引用计数不用改变
            other._ptr = nullptr;
            cout << "move constructor is succeed!" << endl; 
        }
    }

    T* operator->() const{
        return _ptr;
    }

    T& operator*() const{
        return *_ptr;
    }

    //重载operator= 
    smart_ptr<T>& operator=(const smart_ptr<T>& other){
        if(this == &other){
            return *this;
        }
    // 《C++ primer》：“这个赋值操作符在减少左操作数的使用计数之前使other的使用计数加1，  
    // 从而防止自身赋值”而导致的提早释放内存  
        ++(*other._count);
    // 如果原来的shared_ptr已经有对象，则让其引用次数减少1，判断是否为0，为零调用delete
        --(*_count);
        if(this->_ptr &&(*_count) == 0){
            delete _ptr;
            _ptr =nullptr;
            delete _count;
            _count = nullptr;
        }
        //赋值
        this->_ptr = other._ptr;
        this->_count = other._count;
        cout << "Assignment operator overloaded is succeed!" << endl;  
        return *this;
    }
    //析构函数
    ~smart_ptr(){
        --(*_count);
        if(_ptr && (*_count) == 0){
            delete _ptr;
            _ptr = nullptr;
            delete _count;
            _count = nullptr;
            cout << "Destructor is succeed!" << endl; 
        }
    }

    int get_use_count() const{
        if(_ptr){
            return *_count;
        }
        return 0;
    }
private:
    int * _count;
    T* _ptr;
};

int main() {  
    // Test Constructor and Assignment Operator Overloaded  
    smart_ptr<int> p1(new int(0));  
    cout << "p1 use count " << p1.get_use_count()<<endl;

    // Test Copy Constructor  
    smart_ptr<int> p2(p1);  

    cout << "p2 use count " << p2.get_use_count() <<endl;

    // Test Assignment Operator Overloaded  
    p2 = p1;  
    cout << "p2 use count" << p2.get_use_count() <<endl;

    smart_ptr<string>p4(new string("abc"));

    cout << "p4 use count "<< p4.get_use_count() << endl;

    smart_ptr<string>p5(p4);

    cout << "p4 use count " << p4.get_use_count() <<endl;
    cout << "p5 use count " << p5.get_use_count() << endl;

    return 0;  
} 

/*
Constructor is succeed!
p1 use count 1
Copy constructor is succeed!
p2 use count 2
Assignment operator overloaded is succeed!
p2 use count2
Constructor is succeed!
p4 use count 1
Copy constructor is succeed!
p4 use count 2
p5 use count 2
Destructor is succeed!
Destructor is succeed
*/

