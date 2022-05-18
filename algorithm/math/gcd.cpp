#include<stdio.h>
int gcd(int a,int b){
    //递归，当b=0时，返回a;b不为零时，求b和a%b最大公因子。
    return (b?gcd(b,a%b):a);
}
int main(){
    int a,b;
    while(~scanf("%d%d",&a,&b)){
        printf("%d\n",gcd(a,b));
    }
    return 0;
}