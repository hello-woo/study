/*************************************************************************
	> File Name: ./t6/src/main.c
	> Author:zhaozhicai
	> Mail: 
	> Created Time: Mon 07 Sep 2020 11:56:19 AM CST
 ************************************************************************/

#include<stdio.h>
#include<curl/curl.h>
#include<srdlib.h>
#include<unisted.h>
FILE *fp;
int write_data(void *ptr,size_t size,size_t nmemb.void *stream)
{
    int written=fwrite(ptr,size,nmemb,(FILE*)fp);
    return written;
}
int main(){
    const char* path="/tmp/curl-test";
    const char* mode="w";
    fp=fopen(path,mode);
    curl_global_init(CUR_GLOBAL_ALL);
    CURLcode res;
    CURL *curl=curl_easy_init();
    curl_easy_setopt(curl,CURLOPT_URL,"http://www.linux-ren.org");
    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
    curl_easy_setopt(curl,CURLOPT_VERBOSE,1);
    res=cur_easy_perform(curl);
    curl_easy_cleanup(curl);
}
