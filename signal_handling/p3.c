#include<stdio.h>
#include<signal.h>
void myhandler(int s){
	printf("Inside user defined handlker for signal %d\n",s);
}

void find_isr(int signo){
	struct sigaction old,temp;

	sigaction(signo,NULL,&old);

	if(old.sa_handler==SIG_DFL){
		printf("Signal %d :DEFAULT\n",signo);
	}
	else if(old.sa_handler==SIG_IGN){
		printf("Signal %d :IGNORE\n",signo);
	}
	else{
		printf("Signal %d:USER DEFINED\n",signo);
	}
}
int main(){
	struct sigaction sa;

	sa.sa_handler=SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;
	sigaction(SIGINT,&sa,NULL);

	sa.sa_handler=myhandler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;
	sigaction(SIGTERM,&sa,NULL);
	
	find_isr(SIGINT);
	find_isr(SIGTERM);
	find_isr(SIGUSR1);
	return 0;
}
