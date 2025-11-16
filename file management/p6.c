#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>
#include<pwd.h>
#include<grp.h>

void print_permissions(mode_t mode){
	//FILE TYPES
	if(S_ISREG(mode)) printf("-");
	else if(S_ISDIR(mode)) printf("d");
	else if(S_ISCHR(mode)) printf("c");
	else if(S_ISBLK(mode)) printf("b");
	else if(S_ISFIFO(mode)) printf("p");
	else if(S_ISSOCK(mode)) printf("s");
	else printf("?");
	
	//USER PERMISSIONS
	
	if(mode & S_IRUSR){
		printf("r");
	}
	else{
		printf("-");
	}

	 if(mode & S_IWUSR){
                printf("w");
        }
        else{
                printf("-");
        }

	 if(mode & S_IXUSR){
                printf("x");
        }
        else{
                printf("-");
        }

	//GROUP PERMISSIONS
	
        if(mode & S_IRGRP){
                printf("r");
        }
        else{
                printf("-");
        }

         if(mode & S_IWGRP){
                printf("w");
        }
        else{
                printf("-");
        }

         if(mode & S_IXGRP){
                printf("x");
        }
        else{
                printf("-");
        }

	//OTHER PERMISSIONS
	
        if(mode & S_IROTH){
                printf("r");
        }
        else{
                printf("-");
        }

         if(mode & S_IWOTH){
                printf("w");
        }
        else{
                printf("-");
        }

         if(mode & S_IXOTH){
                printf("x");
        }
        else{
                printf("-");
        }

}

int main(int argc, char* argv[]){
	DIR *dp;
	struct dirent *p;
	struct stat st;
	char path[512];

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
		sprintf(path,"%s/%s",argv[1],p->d_name);	
	if(stat(path,&st)<0){
		perror("stat");
		continue;
	}
	print_permissions(st.st_mode);
	printf(" ");

	printf("%ld ",st.st_nlink);//no of haed links
	
	//print user name
	struct passwd *pw=getpwuid(st.st_uid);
	printf("%s ",pw->pw_name);
	
	//print group name
	struct group *gr=getgrgid(st.st_gid);
	printf("%s ",gr->gr_name);
	
	//print file size
	printf("%ld ",st.st_size);
	
	//print modification time
	char *mtime=ctime(&st.st_mtime);
	mtime[16]='\0';
	printf("%s ",mtime+4);
	
	//print file name
	printf("%s \n",p->d_name);
	}
	return 0;
}
