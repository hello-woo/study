#include <iostream>
#include <pthread.h>
using namespace std;
  
pthread_mutex_t mymutex;  //互斥量
int ct = 1;  //全局变量计数
  
void* thread1(void* arg){  //线程1打印'A'
    while(1){
        pthread_mutex_trylock(&mymutex);
        while(ct == 1){ 
            cout << 'A' <<endl;
            ++ct;
        }   
        pthread_mutex_unlock(&mymutex);
    }   
}

void* thread2(void* arg){  //线程2打印'B'
      while(1){
          pthread_mutex_trylock(&mymutex);
          while(ct == 2){
              cout << 'B' <<endl;
              ++ct;
          }
          pthread_mutex_unlock(&mymutex);
      }
  }
  
void* thread3(void* arg){ //线程3打印'C'
      while(1){
          pthread_mutex_trylock(&mymutex);
          while(ct == 3){
              cout << 'C' << endl;
              ct = 1;  //重置ct
          }
          pthread_mutex_unlock(&mymutex); 
      }
  }

int main(){
    pthread_t t1;    
    pthread_t t2;    
    pthread_t t3;
    pthread_mutex_init(&mymutex, NULL);
  
    pthread_create(&t1,NULL,thread1,NULL);
    pthread_create(&t2,NULL,thread2,NULL);
    pthread_create(&t3,NULL,thread3,NULL);
  
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
  
    return 0;
}   
