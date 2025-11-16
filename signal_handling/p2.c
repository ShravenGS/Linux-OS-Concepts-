#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<time.h>

pid_t child;

void handler(int s){
	printf("Child exceeded time! killing...\n");
	kill(child,SIGKILL);
}

int main(){
	srand(time(NULL));
	child=fork();

	if(child==0){
		int d=rand()%10+1;
		printf("Child sleeping %d sec\n",d);
		sleep(d);
		printf("Child done\n");
		exit(0);
	}

	else{
		signal(SIGALRM,handler);
		alarm(5);
		wait(NULL);
		printf("Parent:finished\n");
	}

}

