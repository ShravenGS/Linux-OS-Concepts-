#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]){

	char a[50];
	int fd;

	fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0664);
	if(fd<0){
		perror("open");
		return 0;
	}

	printf("Enter data: ");
	scanf("%s",a);

	write(fd,a,strlen(a));
	close(fd);
	return 0;
}
