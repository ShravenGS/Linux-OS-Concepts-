#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int int_count=0;
int quit_count=0;

void sigint_handler(int signo){
	int_count++;
	printf("SIGINT received %d times\n",int_count);

	if(int_count>=3){
		printf("SIGINT restored to default action!\n");
		signal(SIGINT,SIG_DFL);
	}
}

void sigquit_handler(int signo){
	quit_count++;
	printf("SIGQUIT received %d times\n",quit_count);

	if(quit_count>=5){
		printf("SIGQUIT restored to default action\n");
		signal(SIGQUIT,SIG_DFL);
	}
}

int main(){
	struct sigaction sa_int,sa_quit;

	sa_int.sa_handler=sigint_handler;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags=0;
	sigaction(SIGINT,&sa_int,NULL);

	sa_quit.sa_handler=sigquit_handler;
	sigemptyset(&sa_quit.sa_mask);
	sa_quit.sa_flags=0;
	sigaction(SIGQUIT,&sa_quit,NULL);

	printf("Handlers installed.\n");
	printf("SIGINT:default after 3 times\n");
	printf("SIGQUIT:default after 5 times\n");

	while(1){
		pause();
	}
	return 0;

}
