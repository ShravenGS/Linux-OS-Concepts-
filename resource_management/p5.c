#include<stdio.h>
#include<sys/resource.h>

int main(){
	struct rlimit v;
	getrlimit(RLIMIT_CPU,&v);
	printf("Soft=%lu\nHard=%lu\n",v.rlim_cur,v.rlim_max);

	v.rlim_cur=10;
	setrlimit(RLIMIT_CPU,&v);
	getrlimit(RLIMIT_CPU,&v);

	printf("New Soft=%lu\n",v.rlim_cur);

	printf("Running infinite loop...\n");
	while(1);
	return 0;
}
