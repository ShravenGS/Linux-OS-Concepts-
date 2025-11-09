#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
	int i;
	pid_t pid;
	for(i=0;i<3;i++){
	pid=fork();
	if(pid==0){
		printf("Child %d: pid=%d ppid=%d\n",i+1,getpid(),getppid());
		_exit(0);
	
		}
	}
	while(wait(NULL)>0);
	return 0;
}
