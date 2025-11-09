#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
	pid_t pid1,pid2,pid3,pid4;
	
	pid1=fork();
	if(pid1==0){
		execlp("ls","ls",NULL);
		_exit(0);
	}

	pid2=fork();
	if(pid2==0){
		execlp("pwd","pwd",NULL);
		_exit(0);
	}

	pid3=fork();
	if(pid3==0){
		execlp("cal","cal",NULL);
		_exit(0);
	}
	
	pid4=fork();
	if(pid4==0){
		execlp("date","date",NULL);
		_exit(0);
	}

	waitpid(pid4,NULL,0);
	waitpid(pid2,NULL,0);
	waitpid(pid3,NULL,0);
	waitpid(pid1,NULL,0);
	return 0;
}
