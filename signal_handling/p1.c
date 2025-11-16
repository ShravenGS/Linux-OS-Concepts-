#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

int n=10;

void handler(int s){
	printf("Alarm! n=%d\n",n);

	n--;
	if(n==0){
		exit(0);
	}

	alarm(n);
}

int main(){
	signal(SIGALRM,handler);
	alarm(n);
	while(1){
		pause();
	}

}
	
