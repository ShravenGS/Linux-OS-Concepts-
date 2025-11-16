#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	int fd;

	fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0664);

	if(fd<0){
		perror("open");
		return 0;
	}
	printf("File opened,fd=%d\n",fd);

	close(fd);
	return 0;
}
