#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	pid_t pid1=fork();
	if(pid1==0){
		execlp("ls","ls",NULL);
		_exit(0);
	}
	
	pid_t pid2=fork();
	if(pid2==0){
		execlp("pwd","pwd",NULL);
		_exit(0);
	}

	pid_t pid3=fork();
	if(pid3==0){
		execlp("pwd","pwd",NULL);
		_exit(0);
	}
	execlp("date","date",NULL);
	return 0;

}
