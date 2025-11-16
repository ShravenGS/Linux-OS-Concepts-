#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(){
	signal(SIGHUP,SIG_IGN);

	printf("Process started.... non stop process\n");

	while(1){
		printf("Running...");
		sleep(2);
	}
	return 0;

}
