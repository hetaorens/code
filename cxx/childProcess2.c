#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t cid;
    printf("Before fork process id :%d\n", getpid());
    cid = fork();
  if(cid == 0){ //该分支是子进程执行的代码
     sleep(3); 
     printf("Child process id (my parent pid is %d):%d\n", getppid(),getpid());
       for(int i=0; i<3 ; i++)
            printf("hello\n");
}else{ //该分支是父进程执行的代码
       printf("Parent process id :%d\n", getpid());
       for(int i=0; i<3 ; i++)
            printf("world\n");
      wait(NULL);
      }
      // pause();
   return 0;
}

