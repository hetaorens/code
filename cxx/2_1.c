#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int ticketAmount = 2; //Global Variable 

void* ticketAgent(void* arg){
    int t = ticketAmount;
    if (t > 0)
    {
        printf("One ticket sold!\n");
        t--;
    }else{
        printf("Ticket sold out!!\n");
    }
    ticketAmount = t;
    pthread_exit(0);
}
int main(int argc, char const *argv[])
{
pthread_t ticketAgent_tid[2];
//基于同一个线程函数，通过循环创建两个线程
    for (int i = 0; i < 2; ++i)
    {
        pthread_create(ticketAgent_tid+i, NULL, ticketAgent,NULL); 
}
//循环等待所有线程结束
    for (int i = 0; i < 2; ++i)
    {
        pthread_join(ticketAgent_tid[i],NULL);
    }

    printf("The left ticket is %d\n", ticketAmount);
    return 0;
}
