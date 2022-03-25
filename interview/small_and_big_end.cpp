#include<bits/stdc++.h>

using namespace std;


int main(){
    union u{
        char c;
        int a;
    };
    u un;
    un.a = 0x000012;//数据高位----->低位
    printf("%X\n",un.c);
    return 0;
    /*12 是s.c和s.a的起始地址是一样的我们用printf以16进制的格式输出un.c，这个时候就是s的起始地址的第一个字节的内容，
    在我的平台上输出结果是12，表示低地址存的是整数值的低位，我的平台字节序是小端表示的*/
}