#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

void printBank();  //该函数用以输出缓冲区的全部数值

int Bank[10]={0};
int in=0,out=0;   

sem_t empty;
sem_t full;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* producerThd(void* arg){
    for(int i=0; i<20; i++){        
        sem_wait(&empty);
        pthread_mutex_lock(&lock); //临界区开始
        Bank[in] = 1;
        in = (in+1)%10;
        printBank();
     sleep(1);
        pthread_mutex_unlock(&lock);//临界区结束
        sem_post(&full);
    }   
    pthread_exit(0);
}

void* consumerThd(void* arg){
    for(int i=0; i<20; i++){
        sem_wait(&full);
        pthread_mutex_lock(&lock); //临界区开始
        Bank[out] = 0;
        out = (out+1)%10;
        printBank();
  //      sleep(1.5);
        pthread_mutex_unlock(&lock);//临界区结束
        sem_post(&empty);
    }   
    pthread_exit(0);
}

/*该函数用以输出缓冲区的全部数值*/
void printBank(){
    printf("Bank:");
    for(int i=0; i<10; i++){
        printf("[%d]",Bank[i]);
        if(i==9) putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    pthread_t producer_tid, consumer_tid;
 
    sem_init(&empty, 0, 10); 
    sem_init(&full,  0, 0);
 
    pthread_create(&producer_tid, NULL, producerThd, NULL);
    pthread_create(&consumer_tid, NULL, consumerThd, NULL);

    pthread_join(producer_tid, NULL);
    pthread_join(consumer_tid, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
}
