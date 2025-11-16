#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
int main(){
	struct rlimit v;
	getrlimit(RLIMIT_STACK,&v);
	printf("Soft =%lu\nHard=%lu\n",v.rlim_cur,v.rlim_max);

	v.rlim_cur=100000;
	setrlimit(RLIMIT_STACK,&v);
	getrlimit(RLIMIT_STACK,&v);

	printf("New Soft =%lu\n",v.rlim_cur);

	system("./fact");

}
