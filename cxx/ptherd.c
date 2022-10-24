#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <pthread.h> 
void* threadFunc(void* arg){ //线程函数 
printf("In NEW thread\n"); 
} 
int main() 
{ 
pthread_t tid; 
pthread_create(&tid, NULL, threadFunc, NULL); //线程创建函数
pthread_join(tid, NULL);     //等待指定的线程结束
printf("In main thread\n"); 
return 0; 
}
