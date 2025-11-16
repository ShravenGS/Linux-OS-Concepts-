#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
int main(int argc, char *argv[]){
	struct stat v;

	if(argc!=2){
		printf("Usage:./a.out filename");
		return 0;
	}
	stat(argv[1],&v);

	printf("atime =%ld\n",v.st_atime);
	printf("mtime =%ld\n",v.st_mtime);
	printf("ctime =%ld\n",v.st_ctime);

	printf("Access time =%s",ctime(&v.st_atime));
	printf("Modify time =%s",ctime(&v.st_ctime));
	printf("Change time =%s",ctime(&v.st_ctime));
	return 0;
}
