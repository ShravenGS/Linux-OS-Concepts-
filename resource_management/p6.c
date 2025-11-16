#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>

int main(){
	struct rlimit v;

	getrlimit(RLIMIT_CORE,&v);
	printf("Soft =%u\nHard=%u\n",(unsigned)v.rlim_cur,(unsigned)v.rlim_max);
	v.rlim_cur=100;
	setrlimit(RLIMIT_CORE,&v);

	getrlimit(RLIMIT_CORE,&v);
	printf("New Soft =%u\n",(unsigned)v.rlim_cur);

	return 0;
}
