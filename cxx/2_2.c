#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>   //信号量头文件

//定义同步信号量变量（全局变量）
sem_t empty;
sem_t full;

//生产者线程函数
void* producerThd(void* arg){
    for(int i=0; i<10; i++){
        printf("**Producing one item.**\n");
        sem_wait(&empty);   //P(empty) 
        printf("**PUTTING item %d to warehouse.**\n",i+1);
        sem_post(&full);     //V(full)
    }   
    pthread_exit(0); }

void* consumerThd(void* arg){
    for(int i=0; i<10; i++){
        sem_wait(&full);  //P(full)
        printf("##GETTING item %d from warehouse.##\n",i+1);
        sem_post(&empty);  //V(empty)
        printf("##Consuming the item.##\n");
    }   
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    pthread_t producer_tid, consumer_tid;
    //信号量初始化
    sem_init(&empty, 0, 1);
    sem_init(&full,  0, 0);
    
    pthread_create(&producer_tid, NULL, producerThd, NULL);
    pthread_create(&consumer_tid, NULL, consumerThd, NULL);

    pthread_join(producer_tid, NULL);
    pthread_join(consumer_tid, NULL);

    //销毁信号量
    sem_destroy(&empty);
sem_destroy(&full);
return 0;

}
