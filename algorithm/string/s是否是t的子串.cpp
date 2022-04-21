#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a="abcdefghigklmn";
    string b="def";
    string c="123";
    string::size_type idx; 
    idx=a.find(b);//在a中查找b.
    if(idx == string::npos )//不存在
        cout << "not found\n";
    else//存在
        cout <<"found\n"; 

    idx=a.find(c);//在a中查找c。
    if(idx == string::npos )//不存在
        cout << "not found\n";
    else//存在
        cout <<"found\n"; 
    return 0;
}
