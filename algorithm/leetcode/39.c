/*************************************************************************
	> File Name: 39.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 07 Oct 2020 04:25:12 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int begin,n;
    scanf("%d%d",&begin,&n);
    if(begin>0){
        if(begin%2==0){
             for(int i=0;i<n;i++){
                printf("%d\n",begin);
                begin+=2;
            }
        }else{
            for(int i=0;i<n;i++){
                printf("%d\n",begin+1);
                begin+=2;
            }
        }
    }else{
        begin=0;
        for(int i=0;i<n;i++){
            printf("%d\n",begin);
            begin+=2;
        }
    }
    return 0;
}
