#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	int fd,ret;
	char a[128];

	fd=open(argv[1],O_RDONLY);
	if(fd<0){
		perror("open");
		return 0;
	}

	ret=read(fd,a,10);
	a[ret]='\0';

	printf("Read Data:%s\n",a);
	return 0;
}
