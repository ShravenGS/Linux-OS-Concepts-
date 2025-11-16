#include<stdio.h>
#include<time.h>
#include<unistd.h>

int main(){
	time_t t;

	while(1){
		time(&t);
		printf("Time=%s\n",ctime(&t));
		sleep(1);
	}
}
