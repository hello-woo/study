/*************************************************************************
	> File Name: 113.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 07 Oct 2020 03:30:32 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int y,m;
    scanf("%d%d",&y,&m);
    if(y%4==0&&y%100!=0||y%400==0){
        if(m==2){
            printf("%d",29);
        }else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
            printf("%d",31);
        }else{
            printf("%d",30);
        }
     }
    else{
        if(m==2){
            printf("%d",28);
        }else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
            printf("%d",31);
        }
        else{
            printf("%d",30);
        }
    }
    return 0;
}
