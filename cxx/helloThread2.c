#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <pthread.h> 
static int value=0;
void* hello(void* arg){ //线程函数 
for(int i=0;i<300;i++)
{
    // printf("hello(%d)\n",value++);
printf("hello(%d),value=%d\n",i,value++);
// value++; 
sleep(1);
}} 
void* world(void* arg){ //线程函数 
for(int i=0;i<300;i++)
{
    //    printf("world(%d)\n",value++);
    printf("world(%d),value=%d\n",i,value++);
// value--;
sleep(1); 
}} 
int main() 
{ pthread_t tid1,tid2; 
pthread_create(&tid1, NULL, hello, NULL); 
pthread_create(&tid2, NULL, world, NULL); 

pthread_join(tid1, NULL); 
pthread_join(tid2, NULL);

printf("In main thread\n"); 
return 0; 
}
