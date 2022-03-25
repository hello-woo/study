#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v = { 1,2,3,4,5,6,7,8,9};
    for(auto iter = v.begin() ;iter != v.end();){
        if((*iter) % 3 == 0){
            iter = v.erase(iter);
            //v.erase(iter++); 错误，因为序列式容器的迭代器删除位置后的全部失效
        }
        else{
            iter++;
        }
    }
    for(auto p : v){
        cout << p <<endl;
    }
    list<int>l = { 1,2,3,6,3,7,9};
    for(auto iter= l.begin();iter != l.end();){
        if((*iter) == 3){
            //l.erase(iter++);
            iter = l.erase(iter);
        }else{
            iter++;
        }
    }
    for(auto p : l){
        cout << p <<endl;
    }
    map<string,int>mp={{"1",2},{"2",3},{"3",4}};
#if 0
    for(auto iter = mp.begin();iter != mp.end();){
        if((*iter).first == "1"){
            mp.erase(iter++);//对于关联式的容器，红黑树，只删除一个节点，下一个迭代器有效
        }else{
            iter++;
        }
    }
#endif
    for(auto iter = mp.begin();iter != mp.end();){
        if((*iter).first == "1"){
            iter = mp.erase(iter);
        }else{
            iter++;
        }
    }

    for(auto &[key,value] : mp){
        cout << "key :" <<key << "value :" <<value<<endl;
    }
    return 0;
}