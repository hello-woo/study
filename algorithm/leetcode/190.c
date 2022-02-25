/*************************************************************************
> File Name: 190.c
> Author:zhaozhicai
> Mail:1871259919@qq.com 
> Created Time: Wed 04 Nov 2020 09:31:59 PM CST
************************************************************************/

#include<stdio.h>
#include<math.h>
int is_prime(int n)
{
    float n_sqrt;
    if(n==2 || n==3) return 1;
    if(n%6!=1 && n%6!=5) return 0;
    n_sqrt=floor(sqrt((float)n));
    for(int i=5;i<=n_sqrt;i+=6)
    {
        if(n%(i)==0 | n%(i+2)==0) return 0;

    }
    return 1;

}
int main(){

    long long int n;
    scanf("%lld",&n);
    int cnt=0;
    for(long long int i=2;i<=n;i++){
        for(long long int j=i;j<=n;j++){
            if((i+j==n)&&is_prime(i)&&is_prime(j)){
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
