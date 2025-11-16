#include<stdio.h>
#include<dirent.h>
int main(int argc, char* argv[]){
	if(argc!=2){
		printf("Usage:./a.out directory\n");
		return 0;
	}


	DIR *dp=opendir(argv[1]);
	if(dp==NULL){
		printf("Directory does not exist\n");
		return 0;
	}

	else{
		printf("Directory exist\n");
	}


	return 0;

}
