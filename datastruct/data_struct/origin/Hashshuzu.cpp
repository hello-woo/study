/*************************************************************************
	> File Name: Hashshuzu.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 24 Mar 2021 10:05:45 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

class MyHashSet{
private:
    const static int base=769;
    vector<list<pair<int,int>>>data;
    static int hash(int key){
        return key%base;
    }
public:
    MyHashSet():data(base){}
    /*像哈希表中插入元素,如果存在，更改元素*/
    void put(int key,int value){
        int h=hash(key);
        for(auto it=data[h].begin();it!=data[h].end();it++){
            if((*it).first==key){
                (*it).second=value;
                return ;
            }
        }
        data[h].push_back(make_pair(key,value));
    }
    int get(int key){
        int h=hash(key);
        for(auto it=data[h].begin();it!=data[h].end();it++){
            if((*it).first==key){
                return (*it).second;
            }
        }
        return -1;
    }
    void remove(int key){
        int h=hash(key);
        for(auto it=data[h].begin();it!=data[h].end();it++){
            if((*it).first==key){
                data[h].erase(it);
                return ;
            }
        }
    }
};

int main(){
    MyHashSet *obj=new MyHashSet();
    obj->put(1,3);
    obj->put(2,4);
    int ret=obj->get(2);
    cout<<ret<<endl;
    obj->put(2,5);
    ret=obj->get(2);
    cout<<ret<<endl;
    obj->remove(1);
    cout<<obj->get(1)<<endl;
    return 0;
}
