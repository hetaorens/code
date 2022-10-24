#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
sem_t empty; //控制盘子里可放的水果数 
sem_t apple; //控制苹果数 
sem_t orange; //控制橙子数 
pthread_mutex_t work_mutex=PTHREAD_MUTEX_INITIALIZER; //声明互斥量work_mutex 
int fruitCount = 0;//盘子中水果的数量 

void *thread_f(void *arg) //father线程 
{ 
while(1)
{ 
sem_wait(&empty); //占用一个盘子空间，可放水果数减1 
pthread_mutex_lock(&work_mutex); //加锁 
printf("爸爸放入一个苹果!（盘子当前水果总数：%d）\n", ++fruitCount); 
sem_post(&apple); //释放一个apple信号了，可吃苹果数加1 
pthread_mutex_unlock(&work_mutex); //解锁 
sleep(0.1); 
} 
} 

void * thread_m(void *arg) //mother线程 
{ 
while(1){ 
sem_wait(&empty); 
pthread_mutex_lock(&work_mutex); //加锁 
printf("妈妈放入一个橙子!（盘子当前水果总数：%d）\n", ++fruitCount); 
sem_post(&orange); 
pthread_mutex_unlock(&work_mutex); //解锁 
sleep(0.2); 
} 
} 
void * thread_s(void *arg) //son线程 
{ 
while(1){ 
sem_wait(&orange); //占用一个橙子信号量，可吃橙子数减1 
pthread_mutex_lock(&work_mutex); //加锁 
printf("儿子吃了一个橙子!（盘子当前水果总数：%d）\n", --fruitCount); 
sem_post(&empty); //吃了一个橙子，释放一个盘子空间，可放水果数加1 
pthread_mutex_unlock(&work_mutex); //解锁 
sleep(0.2); 
} 
} 
void * thread_d(void *arg) //daughter线程 
{ 
while(1){ 
sem_wait(&apple); 
pthread_mutex_lock(&work_mutex); //加锁 
printf("女儿吃了一个苹果!（盘子当前水果总数：%d）\n", --fruitCount); 
sem_post(&empty); 
pthread_mutex_unlock(&work_mutex); //解锁 
sleep(0.1); 
} 
} 
int main() 
{ 
pthread_t father; //定义线程 
pthread_t mother; 
pthread_t son; 
pthread_t daughter; 
sem_init(&empty, 0, 3); //信号量初始化 
sem_init(&apple, 0, 0); 
sem_init(&orange, 0, 0); 
pthread_create(&father,NULL, thread_f,NULL); //创建线程 
pthread_create(&mother,NULL, thread_m,NULL); 
pthread_create(&daughter,NULL, thread_d,NULL); 
pthread_create(&son,NULL, thread_s,NULL); 
sleep(1); 
sem_destroy(&empty); 
sem_destroy(&apple); 
sem_destroy(&orange); 
return 0; 
}
