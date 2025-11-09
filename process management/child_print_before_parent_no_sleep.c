#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t pid=fork();
	if(pid==0){
		printf("Child prints first\n");
		_exit(0);
	}

	else{
		wait(NULL);
		printf("Parent prints after child\n");
	}
	return 0;
}
