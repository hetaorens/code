#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int ticketAmount = 2; //Global Variable 
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; //Global lock

void* ticketAgent(void* arg){
    pthread_mutex_lock(&lock);
    int t = ticketAmount;
    if (t > 0)
    {
        printf("One ticket sold!\n");
        t--;
    }else{
        printf("Ticket sold out!!\n");
    }
    ticketAmount = t;
    pthread_mutex_unlock(&lock);
    pthread_exit(0);
}

int main(int argc, char const *argv[])
{
    pthread_t ticketAgent_tid[2];
    for (int i = 0; i < 2; ++i)
    {
        pthread_create(ticketAgent_tid+i, NULL, ticketAgent,NULL);
    }
    for (int i = 0; i < 2; ++i)
    {
        pthread_join(ticketAgent_tid[i],NULL);
    }

    printf("The left ticket is %d\n", ticketAmount);
    return 0;
}
/*代码说明：
a. pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; //创建一个互斥锁
b. pthread_mutex_lock(&lock); //上锁
c. pthread_mutex_unlock(&lock); //开锁
*/