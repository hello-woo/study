/*************************************************************************
	> File Name: 145copy.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 11 Oct 2020 09:27:32 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdio.h>
#include<string.h>
int main() {
        int n;
        int max=0;
        scanf("%d\n", &n);
        char name[100]={0};
    for(int i=0;i<n;i++){
                char *p=name;
        while(scanf("%c",p++)!=EOF){
            if(*(p-1)=='\n'){
                                *(p-1)=0;
                                break;
                            
            }
                    
        }
                char temp[100]={0};
        if(strlen(name)>max){
                        max=strlen(name);
                        strcpy(temp,name);
                        //strcpy(temp,temp1);
            //        
        }
                printf("%s",temp);
            
    }
        // char temp[100]={0,'c'};
    //     // for(int i=0;i<100;i++){
    //         //     printf("%c",temp[i]);
    //             // }
    //                 return 0;
    //                 }
    //     }
}
