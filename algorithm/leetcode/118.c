/*************************************************************************
	> File Name: 118.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 07 Oct 2020 03:46:06 PM CST
 ************************************************************************/


#include<stdio.h>
#include<math.h>
int main(){
    int y;
    scanf("%d",&y);
    int a=y%12-1900%12;
//    printf("%d\n",a);
    switch(a){
        case 0:
            printf("rat\n");
            break;
        case 1:
            printf("ox\n");
            break;
        case 2:
            printf("tiger\n");
            break;
        case 3:
            printf("rabbit\n");
            break;
        case 4:
            printf("dragon\n");
            break;
        case 5:
            printf("snake\n");
            break;
        case 6:
            printf("horse\n");
            break;
        case 7:
            printf("sheep\n");
            break;
        case -4:
            printf("monkey\n");
            break;
        case -3:
            printf("rooster\n");
            break;
        case -2:
            printf("dog\n");
            break;
        case -1:
            printf("pig\n");
            break;
        default:
            printf("No such years!\n");
            break;
    }
    return 0;
}
