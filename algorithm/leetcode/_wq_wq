/*************************************************************************
	> File Name: 142.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 07 Oct 2020 10:33:25 PM CST
 ************************************************************************/
#include<stdio.h>
#include<math.h>
int prime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
            break;
        }
    }
    return 1;
}
int huiwen(int n){
    int y=0;
    int temp=n;
    while(n){
        y=y*10+n%10;
        n=n/10;
    }
    return temp==y;
 }
int main(){
    int a,b;
    int cnt=0;
    int arr[100];
    scanf("%d%d",&a,&b);
//    int ret=prime(19);
//  int ret2=huiwen(101);
//    printf("%d%d",ret,ret2);
    for(int i=a;i<=b;i++){
        if(prime(i)&&huiwen(i)){
            arr[cnt]=i;
            cnt++;
        }
    }
    //printf("%d\n",cnt);
    for(int i=0;i<cnt;i++){
        printf("%d",arr[i]);
        i!=cnt-1&&printf(" ");
    }
    return 0;}
