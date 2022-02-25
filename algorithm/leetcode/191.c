/*************************************************************************
> File Name: 191.c
> Author:zhaozhicai
> Mail:1871259919@qq.com 
> Created Time: Sun 25 Oct 2020 03:53:18 PM CST
************************************************************************/

#include<stdio.h>
#include<math.h>
int is_prime(int n){
    //返回1表示判断为质数，0为非质数，在此没有进行输入异常检测
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

int min_distance(int arr[],int n){
    int min=arr[0];
    int min_index=0;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
            min_index=i;

        }

    }
    return min_index;

}
int max_distance(int arr[],int n){
    int max=arr[0];
    int max_index=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
            max_index=i;

        }

    }
    return max_index;

}
void prime_distance(int l,int r){
    int prime[r-l];
    int cnt=0;
    for(int i=l;i<=r;i++){
        if(!is_prime(i)) continue;
        prime[cnt++]=i;

    }
    int distance[cnt-2];
    for(int i=0;i<cnt-1;i++){
        distance[i]=prime[i+1]-prime[i];

    }

    if(cnt<=1){
        printf("There are no adjacent primes.\n");

    }else{
        int ret1=min_distance(distance,cnt-1);
        int ret2=max_distance(distance,cnt-1);
        printf("%d,%d are closest,"" " "%d,%d are most distant.\n",
               prime[ret1],prime[ret1+1],
               prime[ret2],prime[ret2+1]);
    }

}


int main(){
    int l,r;
    scanf("%d%d",&l,&r);
    prime_distance(l,r);
    return 0;

}

