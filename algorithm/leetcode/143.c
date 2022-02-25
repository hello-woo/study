/*************************************************************************
	> File Name: 143.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 25 Oct 2020 10:18:29 AM CST
 ************************************************************************/

#include<stdio.h>
int is_prime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return 0;
            break;
        }
    }
    return 1;
}  
int is_square(int n){
    int temp[10]={1,4,9,16,25,36,49,64,81};
    for(int i=0;i<10;++i){
        if(n==temp[i]){
            return 1;
        }
    }
    return 0;
}

int is_ok(int n){
    if(n%6==0&&is_prime(n/100)&&is_square(n%100)){
        return 1;
    }
    return 0;
}
int main(){
    int a,b;
    int cnt=0;
    int ok[100];
    scanf("%d%d",&a,&b);
    for(int i=a;i<=b;i++){
        if(is_ok(i)){
            ok[cnt++]=i;
        }
    }
    for(int i=0;i<cnt;i++){
        printf("%d",ok[i]);
        i!=cnt-1&&printf(" ");
    }
    printf("\n");
    printf("%d\n",cnt);
    return 0;
}
