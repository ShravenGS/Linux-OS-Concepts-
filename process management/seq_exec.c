#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){

	pid_t pid;
	int status;

	pid=fork();
	if(pid==0){
		execlp("ls","ls",NULL);
		perror("exec");
		_exit(1);
	}

	wait(&status);
	
	 pid=fork();
        if(pid==0){
                execlp("pwd","pwd",NULL);
                perror("exec");
                _exit(1);
        }

        wait(&status);

	 pid=fork();
        if(pid==0){
                execlp("cal","cal",NULL);
                perror("exec");
                _exit(1);
        }
        wait(&status);
	return 0;

}
