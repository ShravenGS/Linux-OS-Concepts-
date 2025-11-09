#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
	int d,status;
	pid_t p1,p2,p3,cpid;

	srand(getpid());

	p1=fork();
	if(p1==0){
		d=(rand()%10)+1;
		sleep(d);
		printf("Child1:pid=%d ppid=%d exiting after %d sec....\n",getpid(),getppid(),d);
		_exit(1);
	}

	p2=fork();
	if(p2==0){
		d=(rand()%10)+1;
		sleep(d);
		printf("Child2:pid=%d ppid=%d exiting after %d sec....\n",getpid(),getppid(),d);
		_exit(2);
	}

	p3=fork();
	if(p3==0){
		d=(rand()%10)+1;
		sleep(d);
		printf("Child3:pid=%d ppid=%d exiting after %d sec....\n",getpid(),getppid(),d);
		_exit(3);
	}

	while((cpid=wait(&status))>0){
		int exit_code=status/256;
		printf("Parent:child(pid=%d) exited....\n",cpid);

		if(exit_code==2){
			printf("Parent:child2 exited....\n");
			exit(0);
		}
	}
return 0;
}




