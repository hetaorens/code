#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int x = 100; 
int main() 
{ 
pid_t cid; 
cid = fork(); 
if(cid == 0){ //该分支是子进程执行的代码 
x++; 
printf("In child: x=%d\n",x); 
}else { //该分支是父进程执行的代码 
x--; 
printf("In parent: x=%d\n",x); 
} 
return 0; 
}
