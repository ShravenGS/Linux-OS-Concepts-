#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
	int i;
	if(argc<2){
		printf("Usage ./a.out");
	}
	
	for(i=1;i<argc;i++){
		pid_t pid=fork();
		if(pid==0){
			execlp(argv[i],argv[i],NULL);
			perror("exec");
			_exit(1);
		}
	}
	while(wait(NULL)>0);
	return 0;
}

