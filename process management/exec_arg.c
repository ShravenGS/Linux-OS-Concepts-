#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
	if(argc<2){
		printf("Usage:%s cmd[args]\n",argv[0]);
		return 1;
	}

	pid_t pid=fork();

	if(pid==0){
		execvp(argv[1],&argv[1]);
		perror("execvp");
		_exit(0);
	}
	else{
		wait(NULL);
	}
	return 0;

}
