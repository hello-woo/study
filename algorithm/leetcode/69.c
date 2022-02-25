/*************************************************************************
	> File Name: 69.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 07 Oct 2020 04:43:05 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int y,m,d;
    scanf("%d%d%d",&y,&m,&d);
    if(m<=0||d<=0){
        printf("No\n");
    }
    if(m==2){
        if(y%4==0&&y%100!=0||y%400==0){
            if(d<=29){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }else{
            if(d<=28){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
        if(d<=31){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }else{
        if(d<=30){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}

