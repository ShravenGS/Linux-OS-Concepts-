#include<stdio.h>
#include<sys/stat.h>
int main(int argc,char *argv[]){
	struct stat v;
	if(argc!=2){
		printf("Usage ./a.out filename\n");
		return 0;
	}

	if(stat(argv[1],&v)<0){
		perror("stat");
		return 0;
	}
	printf("File Size =%ld bytes\n",v.st_size);
	printf("Inode number=%ld\n",v.st_ino);

	return 0;
}
