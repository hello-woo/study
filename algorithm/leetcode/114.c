/*************************************************************************
	> File Name: 114.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 29 Sep 2020 09:17:23 AM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    char s;
    scanf("%c",&s);
    switch(s){
        case 'h':
            printf("He\n");
            break;
        case 'l':
            printf("Li\n");
            break;
        case 'c':
            printf("Cao\n");
            break;
        case 'd':
            printf("Duan\n");
            break;
        case('w'):
            printf("Wang\n");
            break;
        default:
            printf("Not Here\n");
            break;
    }
    return 0;
}
