#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<time.h>

pid_t child_pid;

void handler(int s){
	printf("Child pid %d exceeded time! Killing it....\n",s);
	kill(child_pid,SIGKILL);
}

void run_child(int child_number,int limit){
	child_pid=fork();

	if(child_pid==0){
		int d=rand()%10+1;
		printf("Child %d sleeping %d sec\n",child_number,d);
		sleep(d);
		printf("Child %d finished nornally\n",child_number);
		exit(0);
	}

	alarm(limit);
	waitpid(child_pid,NULL,0);
	alarm(0);

	printf("Parent:Child %d done\n\n",child_number);
}

int main(){
	srand(time(NULL));
	signal(SIGALRM,handler);

	run_child(1,4);
	run_child(2,6);
	run_child(3,8);

	printf("All children handled");
	return 0;

}
