#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t pid1=fork();
	if(pid1==0){
		printf("Child1 pid=%d ppid=%d\n",getpid(),getppid());
			
		pid_t pid2=fork();
		if(pid2==0){
			printf("Child2 pid=%d ppid=%d\n",getpid(),getppid());

			pid_t pid3=fork();
			if(pid3==0){
				printf("Child3 pid=%d ppid=%d\n",getpid(),getppid());
				_exit(0);
			}
			wait(NULL);
			_exit(0);
		}
		wait(NULL);
		_exit(0);
	}
	wait(NULL);
	return 0;
}

