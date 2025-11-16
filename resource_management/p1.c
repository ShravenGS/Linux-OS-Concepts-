//Display & modify RLIMIT_STACK


#include<stdio.h>
#include<sys/resource.h>

int main(){
	struct rlimit v;
	getrlimit(RLIMIT_STACK,&v);
	printf("Current soft limit=%lu\n",v.rlim_cur);
	printf("Current Hard limit =%lu\n",v.rlim_max);
	
	v.rlim_cur=1000000;
	setrlimit(RLIMIT_STACK,&v);

	getrlimit(RLIMIT_STACK,&v);
	printf("New soft limit=%lu\n",v.rlim_cur);
	printf("Current Hard limit =%lu\n",v.rlim_max);


}
