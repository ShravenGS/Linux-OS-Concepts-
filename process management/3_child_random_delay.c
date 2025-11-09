#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

	int status,d;
	pid_t p1,p2,p3,cpid;

	srand(getpid());
	p1=fork();
	if(p1==0){
		d=(rand()%10)+1;
		sleep(d);
		printf("Child1:pid=%d ppid=%d exiting after %d sec....",getpid(),getppid(),d);
		_exit(1);
	}

	else{
		p2=fork();
		if(p2==0){
			d=(rand()%10)+1;
			sleep(d);
			printf("Child2:pid=%d ppid=%d exiting after %d sec....\n",getpid(),getppid(),d);
			_exit(2);
		}

		else{
			p3=fork();
			if(p3==0){
				d=(rand()%10)+1;
				sleep(d);
				printf("Child3:pid=%d ppid=%d exiting after %d sec....\n",getpid(),getppid(),d);
				_exit(3);
			}

			else{
				while((cpid=wait(&status))>0){
				printf("Parent: child(pid=%d)\n",cpid);
				}
			}
		}
	}
return 0;
}
