#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char* argv[]){
	if(argc!=2){
		printf("Usage:%s cmd1,cmd2,cmd3\n",argv[0]);
		return 1;
		}
		char *cmd=argv[1];
		int i=0,j=0;
		char single_cmd[50];

		while(1){

			if(cmd[i]==','||cmd[i]=='\0'){
				single_cmd[j]='\0';

				if(j>0){
					pid_t pid=fork();

					if(pid==0){
						execlp(single_cmd,single_cmd,NULL);
						perror("exec");
					}
					else if(pid>0){
						wait(NULL);
					}
					else{
						perror("fork failed");
						exit(1);
					}
				}

				j=0;
				if(cmd[i]=='\0')
					break;
			}

			else{
				single_cmd[j++]=cmd[i];
			}
			i++;
		}
		return 0;
		

}
