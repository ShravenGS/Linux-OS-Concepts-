#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

void handler(int s){
	wait(NULL);
	printf("Child cleaned (NO ZOMBIE!!!)\n");
}

int main(){

	struct sigaction sa;
	
	sa.sa_handler=handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;

	sigaction(SIGCHLD,&sa,NULL);

	if(fork()==0){
		printf("Child running...");
		sleep(1);
		printf("Child exiting...");
		_exit(0);
	}
	else{

		printf("Parent:running (child may exit anytime)\n");
		pause();
		printf("Parent exiting....\n");
	}
	return 0;
}
