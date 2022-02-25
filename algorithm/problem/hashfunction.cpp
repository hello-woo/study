/*************************************************************************
> File Name: hashfunction.cpp
> Author:zhaozhicai
> Mail:1871259919@qq.com 
> Created Time: Mon 05 Apr 2021 09:33:36 PM CST
************************************************************************/

#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

template<typename T>
inline void hash_combine(size_t& seed, const T& val) {
    seed ^= hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);

}

template<typename T>
inline void hash_val(size_t& seed, const T& val) {
    hash_combine(seed, val);

}

template<typename T,typename...Types>
inline void hash_val(size_t& seed, const T& val, const Types&... args) {
    hash_combine(seed, val);
    hash_val(seed, args...);

}

template<typename...Types>
inline size_t hash_val(const Types&... args) {
    size_t seed = 0;
    hash_val(seed, args...);
    return seed;

}

class Customer {
public:
    string fname;
    string lname;
    int  no;
public:
    Customer(string _fname ,string _lname,int  _no):fname(_fname),lname(_lname),no(_no){}

};
class CustomerHash {
    public:
    size_t operator()(const Customer& c)const {
        return hash_val(c.fname, c.lname, c.no);

    }

};

int main() {
    unordered_set<Customer, CustomerHash>set3;
    set3.insert(Customer("Sabri", "Hou", 1L));
    set3.insert(Customer("afafi", "Fou", 2));
    set3.insert(Customer("Sabri", "Fou", 2));
    cout << "set3 current bucket_conut:" << set3.bucket_count() << endl;

    CustomerHash hh;
    cout << "bucket position of ace =" << hh(Customer("Ace", "Hou", 1)) % 11 << endl;
    return 0;

}
