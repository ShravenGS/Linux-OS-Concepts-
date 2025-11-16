#include<stdio.h>
#include<sys/resource.h>
int main(){
	struct rlimit v;
	getrlimit(RLIMIT_FSIZE,&v);
	printf("Soft =%lu\nHard=%lu",v.rlim_cur,v.rlim_max);
	v.rlim_cur=10;
	setrlimit(RLIMIT_FSIZE,&v);

	getrlimit(RLIMIT_FSIZE,&v);
	printf("New Soft =%lu\n",v.rlim_cur);

	FILE *fp;
	char data[]="QWERTY";

	fp=fopen("temp.txt","w");
	fprintf(fp,"%s",data);
	fclose(fp);
	return 0;

}
