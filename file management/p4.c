#include<stdio.h>
#include<dirent.h>
int main(int argc, char *argv[]){
	DIR *dp;
	struct dirent *p;
	if(argc!=2){
		printf("Usage:./a.out directory\n");
		return 0;
	}

	dp=opendir(argv[1]);
	if(dp==NULL){
		perror("opendir");
		return 0;
	}

	while((p=readdir(dp))!=NULL){
		printf("%s\n",p->d_name);
	}

	return 0;
}
