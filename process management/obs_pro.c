#include<stdio.h>
#include<unistd.h>
int main(){
	printf("Before->%d %d\n",getpid(),getppid());
	fork();
	printf("1:%d and %d\n",getpid(),getppid());
	fork();	
	printf("2:%d and %d\n",getpid(),getppid());
	sleep(1);
	fork();
	printf("3:%d and %d\n",getpid(),getppid());

	return 0;

}
