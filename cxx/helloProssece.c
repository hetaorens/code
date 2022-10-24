#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
//pid_t是数据类型，实际上是一个整型，通过typedef重新定义了一个名字，用于存储进程id 
pid_t pid; 
pid= getpid();   //getpid()函数返回当前进程的id号 
printf("Process id :%d\n", pid); 
int i; scanf("%d",&i);
//pause();
return 0; 
}  
