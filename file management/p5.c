#include<stdio.h>
#include<dirent.h>
#include<string.h>

int main(int argc,char*argv[]){
	DIR *dp;
	struct dirent *p;

	if(argc!=3){
		printf("Usage:./a.out directory filename\n");
		return 0;
	}

	dp=opendir(argv[1]);
	if(dp==NULL){
		perror("opendir");
		return 0;
	}

	while((p=readdir(dp))!=NULL){
		if(strcmp(p->d_name,argv[2])==0){
			printf("FILE FOUND!\n...");
			return 0;
		}
	}
	printf("FILE NOT FOUND....\n");
	return 0;
}

