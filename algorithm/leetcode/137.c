/*************************************************************************
	> File Name: 137.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Wed 07 Oct 2020 08:17:55 PM CST
 ************************************************************************/

#include<stdio.h>
int main(){
    int n;
//    char arr[26]={'A','B','C','D','E','F','G',
  //               'H','I','J','K','L','M','N','O',
    //              'P','Q','R','S','T','U','V','W','X','Y','Z'};
    scanf("%d",&n);
    int k=0;
    for(int i=n;i>0;i--){
        for(int j=0;j<i;j++){
            printf("%c",k+65);
            k++;
        }
        printf("\n");
    }
    
    return 0;
}
