#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
	int fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0664);
	if(fd<0){
		perror("open");
		exit(1);
	}
	
	int new_fd=dup(fd);
	if(new_fd<0){
		perror("dup");
		exit(1);
	}

	write(fd,"Hello using fd\n",15);
	write(new_fd,"Hello using dup_fd\n",19);

	printf("Original fd=%d, Duplicated fd =%d\n",fd,new_fd);

	close(fd);
	close(new_fd);
	return 0;
}
